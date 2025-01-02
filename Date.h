//
// Created by segev on 2/28/2024.
//

#ifndef SPORT_FIELD_SEGEV_ALONE_DATE_H
#define SPORT_FIELD_SEGEV_ALONE_DATE_H
#include <iostream>
using namespace std;


class Date {
private:
    int year;
    int month;
    int day;

public:
    explicit Date(int n_year = 0, int n_month = 0, int n_day = 0): year(n_year), month(n_month), day(n_day) {}
    Date(const Date& copy){this->day = copy.day; this->month = copy.month; this->year = copy.year;}
//    int get_day() const {return this->day;}
//    int get_month() const {return this->month;}
//    int get_year() const {return this.year;};


    friend ostream& operator<<(ostream& os, const Date& obj){
        os << obj.day << "\\" << obj.month << "\\" << obj.year << endl;
        return os;
    }


};


#endif //SPORT_FIELD_SEGEV_ALONE_DATE_H
