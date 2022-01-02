#ifndef TIMETABLE
#define TIMETABLE


std::string test = "Hello";
class Train{
    private:
        int hour;
        int minute;
        std::string dest;
    
    public:
        Train(int h, int m, std::string d) : hour(h), minute(m), dest(d){

        }

        int getHour(){
            return hour;
        }

        int getMinute(){
            return minute;
        }

        std::string getDest(){
            return dest;
        }
};

Train getNextTrain(int lastMin, std::vector<Train> *timeTable, int offSet=0){
    for(auto it = timeTable->begin(); it != timeTable->end(); ++it){
        int m = it->getHour()*60 + it->getMinute();
        if(lastMin + 9 < m){ // 9分前に出たら間に合わないので
            if(offSet == 0) return *it;
            int index = std::distance(timeTable->begin(), it) + offSet;
            if(index < 0) index = timeTable->size()+index;
            else if (timeTable->size() <= index) index = index - timeTable->size();
            return (*timeTable)[index];
        }
    }
    return *(timeTable->begin());
}

std::vector<Train> timeTableWeekDay;
void addToTimeTable(std::vector<Train> *timeTable, int h, int m, std::string d){
    Train train(h, m, d);
    timeTable->push_back(train);
}
void initTimeTableWeekDay(std::vector<Train> *timeTable){
    addToTimeTable(timeTable, 5, 0,  "A");
    addToTimeTable(timeTable, 5, 7,  "Y");
    addToTimeTable(timeTable, 5, 16, "A");
    addToTimeTable(timeTable, 5, 27, "Y");
    addToTimeTable(timeTable, 5, 35, "A");
    addToTimeTable(timeTable, 5, 40, "A");
    addToTimeTable(timeTable, 5, 47, "Mu");
    addToTimeTable(timeTable, 5, 56, "A");

    addToTimeTable(timeTable, 6, 4,  "Y");
    addToTimeTable(timeTable, 6, 11, "A");
    addToTimeTable(timeTable, 6, 16, "Y");
    addToTimeTable(timeTable, 6, 22, "K");
    addToTimeTable(timeTable, 6, 28, "A");
    addToTimeTable(timeTable, 6, 33, "Mu");
    addToTimeTable(timeTable, 6, 41, "S");
    addToTimeTable(timeTable, 6, 45, "A");
    addToTimeTable(timeTable, 6, 52, "K");
    addToTimeTable(timeTable, 6, 57, "A");

    addToTimeTable(timeTable, 7, 2,  "S");
    addToTimeTable(timeTable, 7, 10, "Y");
    addToTimeTable(timeTable, 7, 15, "A");
    addToTimeTable(timeTable, 7, 20, "Y");
    addToTimeTable(timeTable, 7, 28, "A");
    addToTimeTable(timeTable, 7, 38, "Y");
    addToTimeTable(timeTable, 7, 45, "A");
    addToTimeTable(timeTable, 7, 51, "A");
    addToTimeTable(timeTable, 7, 58, "A");

    addToTimeTable(timeTable, 8, 6,  "A");
    addToTimeTable(timeTable, 8, 19, "S");
    addToTimeTable(timeTable, 8, 28, "Me");
    addToTimeTable(timeTable, 8, 33, "A");
    addToTimeTable(timeTable, 8, 46, "A");
    addToTimeTable(timeTable, 8, 58, "A");

    addToTimeTable(timeTable, 9, 12, "A");
    addToTimeTable(timeTable, 9, 22, "Mu");
    addToTimeTable(timeTable, 9, 30, "A");
    addToTimeTable(timeTable, 9, 46, "A");
    addToTimeTable(timeTable, 9, 57, "Y");

    addToTimeTable(timeTable, 10,  8, "A");
    addToTimeTable(timeTable, 10, 17, "Y");
    addToTimeTable(timeTable, 10, 26, "A");
    addToTimeTable(timeTable, 10, 37, "Y");
    addToTimeTable(timeTable, 10, 46, "A");
    addToTimeTable(timeTable, 10, 57, "Y");

    addToTimeTable(timeTable, 11,  8, "A");
    addToTimeTable(timeTable, 11, 17, "Y");
    addToTimeTable(timeTable, 11, 26, "A");
    addToTimeTable(timeTable, 11, 37, "Y");
    addToTimeTable(timeTable, 11, 46, "A");
    addToTimeTable(timeTable, 11, 57, "Y");

    addToTimeTable(timeTable, 12,  8, "A");
    addToTimeTable(timeTable, 12, 17, "Y");
    addToTimeTable(timeTable, 12, 26, "A");
    addToTimeTable(timeTable, 12, 37, "Y");
    addToTimeTable(timeTable, 12, 46, "A");
    addToTimeTable(timeTable, 12, 57, "Y");
        
    addToTimeTable(timeTable, 13,  8, "A");
    addToTimeTable(timeTable, 13, 17, "Y");
    addToTimeTable(timeTable, 13, 26, "A");
    addToTimeTable(timeTable, 13, 37, "Y");
    addToTimeTable(timeTable, 13, 46, "A");
    addToTimeTable(timeTable, 13, 57, "Y");

    addToTimeTable(timeTable, 14,  8, "A");
    addToTimeTable(timeTable, 14, 17, "Y");
    addToTimeTable(timeTable, 14, 26, "A");
    addToTimeTable(timeTable, 14, 37, "Y");
    addToTimeTable(timeTable, 14, 46, "A");
    addToTimeTable(timeTable, 14, 57, "Y");

    addToTimeTable(timeTable, 15,  8, "A");
    addToTimeTable(timeTable, 15, 17, "Y");
    addToTimeTable(timeTable, 15, 26, "A");
    addToTimeTable(timeTable, 15, 37, "Y");
    addToTimeTable(timeTable, 15, 46, "A");
    addToTimeTable(timeTable, 15, 54, "S");

    addToTimeTable(timeTable, 16,  0, "A");
    addToTimeTable(timeTable, 16, 14, "A");
    addToTimeTable(timeTable, 16, 25, "Mu");
    addToTimeTable(timeTable, 16, 33, "A");
    addToTimeTable(timeTable, 16, 43, "Mu");
    addToTimeTable(timeTable, 16, 50, "A");
    addToTimeTable(timeTable, 16, 57, "Y");

    addToTimeTable(timeTable, 17,  8, "A");
    addToTimeTable(timeTable, 17, 17, "Y");
    addToTimeTable(timeTable, 17, 24, "A");
    addToTimeTable(timeTable, 17, 32, "Y");
    addToTimeTable(timeTable, 17, 37, "A");
    addToTimeTable(timeTable, 17, 43, "A");
    addToTimeTable(timeTable, 17, 50, "A");
    addToTimeTable(timeTable, 17, 57, "A");
    
    addToTimeTable(timeTable, 18, 11, "Y");
    addToTimeTable(timeTable, 18, 18, "A");
    addToTimeTable(timeTable, 18, 24, "I");
    addToTimeTable(timeTable, 18, 32, "H");
    addToTimeTable(timeTable, 18, 37, "A");
    addToTimeTable(timeTable, 18, 45, "S");
    addToTimeTable(timeTable, 18, 51, "A");

    addToTimeTable(timeTable, 19,  0, "A");
    addToTimeTable(timeTable, 19,  7, "A");
    addToTimeTable(timeTable, 19, 21, "A");
    addToTimeTable(timeTable, 19, 29, "A");
    addToTimeTable(timeTable, 19, 39, "A");
    addToTimeTable(timeTable, 19, 53, "A");

    addToTimeTable(timeTable, 20,  6, "A");
    addToTimeTable(timeTable, 20, 14, "A");
    addToTimeTable(timeTable, 20, 20, "A");
    addToTimeTable(timeTable, 20, 33, "A");
    addToTimeTable(timeTable, 20, 46, "A");
    addToTimeTable(timeTable, 20, 53, "A");

    addToTimeTable(timeTable, 21,  2, "A");
    addToTimeTable(timeTable, 21, 15, "Mu");
    addToTimeTable(timeTable, 21, 22, "A");
    addToTimeTable(timeTable, 21, 37, "A");
    addToTimeTable(timeTable, 21, 51, "A");

    addToTimeTable(timeTable, 22,  4, "A");
    addToTimeTable(timeTable, 22, 11, "Y");
    addToTimeTable(timeTable, 22, 17, "A");
    addToTimeTable(timeTable, 22, 31, "A");
    addToTimeTable(timeTable, 22, 39, "Y");
    addToTimeTable(timeTable, 22, 44, "A");
    addToTimeTable(timeTable, 22, 58, "A");

    addToTimeTable(timeTable, 23, 15, "Y");
    addToTimeTable(timeTable, 23, 25, "A");
    addToTimeTable(timeTable, 23, 40, "A");
    addToTimeTable(timeTable, 23, 55, "A");

    addToTimeTable(timeTable, 24, 15, "A");

};

std::vector<Train> timeTableWeekEnd;
void initTimeTableWeekEnd(std::vector<Train> *timeTable){
    addToTimeTable(timeTable, 5, 0,  "A");
    addToTimeTable(timeTable, 5, 7,  "Y");
    addToTimeTable(timeTable, 5, 22, "A");
    addToTimeTable(timeTable, 5, 28, "Y");
    addToTimeTable(timeTable, 5, 45, "A");

    addToTimeTable(timeTable, 6, 4,  "A");
    addToTimeTable(timeTable, 6, 19, "A");
    addToTimeTable(timeTable, 6, 32, "A");
    addToTimeTable(timeTable, 6, 47, "K");

    addToTimeTable(timeTable, 7,  0, "A");
    addToTimeTable(timeTable, 7, 16, "A");
    addToTimeTable(timeTable, 7, 26, "Y");
    addToTimeTable(timeTable, 7, 31, "A");
    addToTimeTable(timeTable, 7, 44, "A");
    addToTimeTable(timeTable, 7, 58, "A");

    addToTimeTable(timeTable, 8, 12, "A");
    addToTimeTable(timeTable, 8, 25, "A");
    addToTimeTable(timeTable, 8, 38, "A");
    addToTimeTable(timeTable, 8, 53, "A");

    addToTimeTable(timeTable, 9,  4, "S");
    addToTimeTable(timeTable, 9, 10, "A");
    addToTimeTable(timeTable, 9, 23, "A");
    addToTimeTable(timeTable, 9, 32, "Mu");
    addToTimeTable(timeTable, 9, 37, "A");
    addToTimeTable(timeTable, 9, 50, "A");

    addToTimeTable(timeTable, 10,  3, "A");
    addToTimeTable(timeTable, 10,  9, "S");
    addToTimeTable(timeTable, 10, 16, "A");
    addToTimeTable(timeTable, 10, 21, "Y");
    addToTimeTable(timeTable, 10, 31, "A");
    addToTimeTable(timeTable, 10, 47, "A");
    addToTimeTable(timeTable, 10, 57, "Y");

    addToTimeTable(timeTable, 11,  6, "A");
    addToTimeTable(timeTable, 11, 17, "Y");
    addToTimeTable(timeTable, 11, 26, "A");
    addToTimeTable(timeTable, 11, 37, "Y");
    addToTimeTable(timeTable, 11, 46, "A");
    addToTimeTable(timeTable, 11, 57, "Y");

    addToTimeTable(timeTable, 12,  6, "A");
    addToTimeTable(timeTable, 12, 17, "Y");
    addToTimeTable(timeTable, 12, 26, "A");
    addToTimeTable(timeTable, 12, 37, "Y");
    addToTimeTable(timeTable, 12, 46, "A");
    addToTimeTable(timeTable, 12, 57, "Y");
        
    addToTimeTable(timeTable, 13,  6, "A");
    addToTimeTable(timeTable, 13, 17, "Y");
    addToTimeTable(timeTable, 13, 26, "A");
    addToTimeTable(timeTable, 13, 37, "Y");
    addToTimeTable(timeTable, 13, 46, "A");
    addToTimeTable(timeTable, 13, 57, "Y");

    addToTimeTable(timeTable, 14,  6, "A");
    addToTimeTable(timeTable, 14, 17, "Y");
    addToTimeTable(timeTable, 14, 26, "A");
    addToTimeTable(timeTable, 14, 37, "Y");
    addToTimeTable(timeTable, 14, 46, "A");
    addToTimeTable(timeTable, 14, 57, "Y");

    addToTimeTable(timeTable, 15,  6, "A");
    addToTimeTable(timeTable, 15, 16, "Mu");
    addToTimeTable(timeTable, 15, 25, "A");
    addToTimeTable(timeTable, 15, 36, "Mu");
    addToTimeTable(timeTable, 15, 44, "A");
    addToTimeTable(timeTable, 15, 54, "Y");

    addToTimeTable(timeTable, 16,  0, "A");
    addToTimeTable(timeTable, 16, 10, "Mu");
    addToTimeTable(timeTable, 16, 15, "A");
    addToTimeTable(timeTable, 16, 22, "A");
    addToTimeTable(timeTable, 16, 32, "A");
    addToTimeTable(timeTable, 16, 42, "A");
    addToTimeTable(timeTable, 16, 51, "A");

    addToTimeTable(timeTable, 17,  1, "S");
    addToTimeTable(timeTable, 17,  6, "A");
    addToTimeTable(timeTable, 17, 13, "A");
    addToTimeTable(timeTable, 17, 20, "A");
    addToTimeTable(timeTable, 17, 30, "A");
    addToTimeTable(timeTable, 17, 40, "A");
    addToTimeTable(timeTable, 17, 55, "A");
    
    addToTimeTable(timeTable, 18,  8, "Mu");
    addToTimeTable(timeTable, 18, 13, "A");
    addToTimeTable(timeTable, 18, 26, "A");
    addToTimeTable(timeTable, 18, 32, "Mu");
    addToTimeTable(timeTable, 18, 42, "A");
    addToTimeTable(timeTable, 18, 54, "Mu");

    addToTimeTable(timeTable, 19,  5, "A");
    addToTimeTable(timeTable, 19, 18, "A");
    addToTimeTable(timeTable, 19, 31, "A");
    addToTimeTable(timeTable, 19, 41, "Mu");
    addToTimeTable(timeTable, 19, 46, "A");
    addToTimeTable(timeTable, 19, 57, "Y");

    addToTimeTable(timeTable, 20,  2, "A");
    addToTimeTable(timeTable, 20,  7, "H");
    addToTimeTable(timeTable, 20, 16, "Mu");
    addToTimeTable(timeTable, 20, 24, "A");
    addToTimeTable(timeTable, 20, 35, "Y");
    addToTimeTable(timeTable, 20, 43, "A");
    addToTimeTable(timeTable, 20, 53, "S");
    addToTimeTable(timeTable, 20, 59, "A");

    addToTimeTable(timeTable, 21, 12, "A");
    addToTimeTable(timeTable, 21, 25, "A");
    addToTimeTable(timeTable, 21, 38, "A");
    addToTimeTable(timeTable, 21, 48, "S");
    addToTimeTable(timeTable, 21, 55, "A");

    addToTimeTable(timeTable, 22,  5, "Y");
    addToTimeTable(timeTable, 22, 17, "A");
    addToTimeTable(timeTable, 22, 25, "Mu");
    addToTimeTable(timeTable, 22, 25, "A");
    addToTimeTable(timeTable, 22, 32, "A");

    addToTimeTable(timeTable, 23,  1, "A");
    addToTimeTable(timeTable, 23, 16, "A");
    addToTimeTable(timeTable, 23, 31, "A");
    addToTimeTable(timeTable, 23, 54, "A");

    addToTimeTable(timeTable, 24, 13, "A");

};

#endif