#ifndef USER_H_FIELD_H
#define USER_H_FIELD_H
using namespace std;
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include "Player.h"
#include "Reservation.h"


class Field {
protected:
    char* Manager_ID;
    char* nameOfField ;
    int FieldNumber;
    int length, width;
    int pricePerHour;
    bool isHourReserved[15];
    int num_Reservations;
    Reservation ** Reservations;

public:
    Field(): nameOfField(nullptr), Manager_ID(nullptr), FieldNumber(0), length(0), width(0), pricePerHour(0.0){
        for (int i = 0; i < 15; ++i) {
            isHourReserved[i] = false;
        }
    }
    Field(char* nameOfField, char* ID, int FieldNum, int length, int width, int pricePerHour);
    Field(const Field &other);
    virtual ~Field(){delete[] nameOfField;}
    void printDetails(char* VIP);
    char* getNameOfField()const{return nameOfField;}
//    void writeScheduleToFile();
//    void readFromScheduleFile();
//    void showPlayerOrderHistory(const string& playerId) const;
    char* GetManagerID()const{return Manager_ID;}
    char* GetName() const{return nameOfField;}
    int GetFieldNumber()const{return FieldNumber;}
    int getLength()const{return length;}
    int getWidth()const{return width;}
    int getPricePerHour()const{return pricePerHour;}
    void markAsReserved(int hour, char* ID, char* rentEquipment ,char * Date, char* location, char* type, int num);
    bool isAvailable(int hour) const;
    void displaySchedule(const bool *hours, char*& date);
    bool reserveField(int hour, char* ID, char* rentEquipment ,char * Date, char* location, char* typem, int num);
//    void cancelOrderById(const string &idToCancel);
    void displayScheduleAtHour(int hour);
    Reservation ** GetReservations (){return Reservations;}

    friend ostream& operator<<(ostream& os, Field& field) {
        os << "Field Name: " << field.nameOfField << "\n"
           << "Field Number: " << field.FieldNumber << "\n"
           << "Length: " << field.length << "\n"
           << "Width: " << field.width << "\n"
           << "Price per Hour: " << field.pricePerHour << "\n";
        return os;
    }


};


#endif //USER_H_FIELD_H
