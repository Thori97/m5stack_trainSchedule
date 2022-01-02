#include <M5Stack.h>
#include <string.h>
#include <vector>
#include <WiFi.h>
#include "time.h"
#include "M5FontRender.h"

#include "timetable.hpp"
#include "config.hpp"


const char* ntpServer = "ntp.nict.jp";
const long  gmtOffset_sec = 3600 * 9;
const int   daylightOffset_sec = 0;

// at 2:10:30, 
int lastSec; // 7200+600+30
int lastMin; // 120+10
int lastNextTrainMin; // 300
Train nextTrain(5, 0, "A");
Train next2Train(5, 0, "A");
Train next3Train(5, 0, "A");
bool DisplayMode;
M5FontRender render;
std::vector<Train> *timeTable;

int offSet;

void printLocalTime(int y, int mon=1, int d=1, int h=1, int min=1, int sec=1){
  int x0 = 40, y0 = 20;

  render.setTextSize(24);
  //M5.Lcd.loadFont(f24, SD);
  render.setCursor(x0, y0);
  if (y < 0){
    render.printf("Failed to obtain time");
  }
  else{
    render.printf("%04d-%02d-%02d %02d:%02d:%02d", y, mon, d, h, min, sec);
  }
}

void printLeftTime(){
  int leftTime = nextTrain.getHour()*60*60 + nextTrain.getMinute()*60 - lastSec;
  if(leftTime<0) leftTime += 60*60*24;
  int x0 = 15, y0 = 60;
  int h = leftTime/60/60;
  int m = leftTime%(60*60)/60;
  int s = leftTime%60;

  if(60*11<=leftTime && leftTime <= 60*13) render.setTextColor(ORANGE);
  if(60*9<=leftTime && leftTime < 60*11) render.setTextColor(RED);
  render.setTextSize(45);
  render.setCursor(x0, y0);
  render.printf("あと %02d:%02d:%02d", h, m, s);
  if(60*9<=leftTime && leftTime <= 60*13) render.setTextColor(WHITE);
}

void updateLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    printLocalTime(-1);
    return;
  }
  int hour = timeinfo.tm_hour;
  int min = timeinfo.tm_min;
  int sec = timeinfo.tm_sec;

  int newSec = 60*60*hour + 60*min + sec;
  if(newSec == lastSec) return;
  else{
    lastSec = newSec;
    lastMin = 60*hour + min;
    int year = timeinfo.tm_year+1900;
    int mon = timeinfo.tm_mon+1;
    int day = timeinfo.tm_mday;
    printLocalTime(year, mon, day, hour, min, sec);
    printLeftTime();
  }
}

bool todayIsWeekDay(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    printLocalTime(-1);
    return true;
  }
  int wd = timeinfo.tm_wday;
  if(wd == 0 || wd == 6) return false;
  else return true;
}

void initWiFi(){
  M5.Lcd.print("Connecting to YOUR_SSID ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }
  M5.Lcd.println(" CONNECTED");
}

void updateTimeTable(){
  if(lastSec == 60*20){ // 0:20に更新
    if(todayIsWeekDay()) timeTable = &timeTableWeekDay;
    else timeTable = &timeTableWeekEnd;
    return;
  }
  else return;
}

std::string mapToDest(std::string d){
  if(d == "A")       return "　綾　瀬　";
  else if (d == "Y") return "代々木上原";
  else if (d == "Mu")return "向ヶ丘遊園";
  else if (d == "K") return "霞　ヶ　関";
  else if (d == "S") return "成城学園前";
  else if (d == "H") return "本　厚　木";
  else if (d == "Me")return "明治神宮前";
  else if (d == "I") return "伊　勢　原";
  else return "Undefine";
}

  void printNextTrains(){
  int textSize = 24;
  render.setTextSize(textSize);
  std::string dest = mapToDest(nextTrain.getDest());
  int h = nextTrain.getHour();
  int m = nextTrain.getMinute();
  int x0 = 30, y0 = 120;
  if (dest != "　綾　瀬　") render.setTextColor(RED);
  else render.setTextColor(WHITE);
  M5.Lcd.fillRect(x0+textSize/2*10, y0+5, textSize*5, textSize, BLACK); // cursorとprintする位置のずれ
  render.setCursor(x0, y0);
  render.printf("%02d:%02d for %s", h, m, dest.c_str());

  dest = mapToDest(next2Train.getDest());
  h = next2Train.getHour();
  m = next2Train.getMinute();
  x0 = 30, y0 = 150;
  if (dest != "　綾　瀬　") render.setTextColor(RED);
  else render.setTextColor(WHITE);
  M5.Lcd.fillRect(x0+textSize/2*10, y0+5, textSize*5, textSize, BLACK);
  render.setCursor(x0, y0);
  render.printf("%02d:%02d for %s", h, m, dest.c_str());

  dest = mapToDest(next3Train.getDest());
  h = next3Train.getHour();
  m = next3Train.getMinute();
  x0 = 30, y0 = 180;
  if (dest != "　綾　瀬　") render.setTextColor(RED);
  else render.setTextColor(WHITE);
  M5.Lcd.fillRect(x0+textSize/2*10, y0+5, textSize*5, textSize, BLACK);
  render.setCursor(x0, y0);
  render.printf("%02d:%02d for %s", h, m, dest.c_str());

  render.setTextColor(WHITE);
}

void updateNextTrain(){
  nextTrain = getNextTrain(lastMin, timeTable, 0+offSet);
  int h = nextTrain.getHour();
  int m = nextTrain.getMinute();

  int newNextTrainMin = h*60 + m;

  if(newNextTrainMin == lastNextTrainMin) return;
  else{
    lastNextTrainMin = newNextTrainMin;
    next2Train = getNextTrain(lastMin, timeTable, 1+offSet);
    next3Train = getNextTrain(lastMin, timeTable, 2+offSet);
    printNextTrains();
  }
}

void setup() {
  M5.begin();
  M5.Power.begin();
  initTimeTableWeekDay(&timeTableWeekDay);
  initTimeTableWeekEnd(&timeTableWeekEnd);
  render.loadFont("/touhuku.ttf");
  initWiFi();
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  lastNextTrainMin = 0;
  DisplayMode = false;
  M5.Lcd.clear(TFT_BLACK);
  M5.Lcd.fillTriangle(52, 235, 75, 235, 63, 212, TFT_WHITE);
  M5.Lcd.fillTriangle(320-52, 212, 320-75, 212, 320-63, 235, TFT_WHITE);
  if(todayIsWeekDay()) timeTable = &timeTableWeekDay;
  else timeTable = &timeTableWeekEnd;
  if(M5.BtnA.isPressed())timeTable = &timeTableWeekDay;
  if(M5.BtnC.isPressed())timeTable = &timeTableWeekEnd;
}

void loop() {
  //put your main code here, to run repeatedly:
  if(M5.BtnA.wasPressed())offSet--;
  if(M5.BtnC.wasPressed())offSet++;
  if(M5.BtnB.wasPressed())offSet = 0;
  updateLocalTime();
  updateNextTrain();
  updateTimeTable();
  if(60*90<=lastSec && lastSec<=60*360) M5.Lcd.setBrightness(0);
  if(lastSec==60*360+1)M5.Lcd.setBrightness(255);
  delay(100);
  M5.update();
}