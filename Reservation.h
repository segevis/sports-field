#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_RESERVATION_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_RESERVATION_H
#include <iostream>
#include <cstring>
#include "Player.h"

using namespace std;

class Reservation {
private:
    int hour;
    char* location;
    char* typeOfField;
    int numOfField;
    char* ID;
    char* equipmentRented;
    char* Date;
public:
    Reservation():hour(0),ID(nullptr),equipmentRented(nullptr), Date("01/01/2024"), location("Ashdod"),typeOfField("Tennis"),numOfField(0){}
    Reservation(int hour,char* ID,char* equipmentRented, char* Date , char* location, char* typeOfField, int num)
    {
        this->hour = hour;
        this->ID = new char [strlen(ID)+1];
        strcpy(this->ID, ID);
        this->Date = new char [strlen(Date)+1];
        strcpy(this->Date, Date);
        this->location = new char [strlen(location)+1];
        strcpy(this->location, location);
        this->typeOfField = new char [strlen(typeOfField)+1];
        strcpy(this->typeOfField, typeOfField);
        this->equipmentRented=new char[strlen(equipmentRented)+1];
        strcpy(this->equipmentRented,equipmentRented);
        this->numOfField = num;
    }
    Reservation(const Reservation& other)
    {
        hour = other.hour;
        ID = new char[strlen(other.ID) + 1];
        strcpy(ID, other.ID);
        Date = new char[strlen(other.Date) + 1];
        strcpy(Date, other.Date);
        location = new char[strlen(other.location) + 1];
        strcpy(location, other.location);
        typeOfField = new char[strlen(other.typeOfField) + 1];
        strcpy(typeOfField, other.typeOfField);
        equipmentRented = new char[strlen(other.equipmentRented) + 1];
        strcpy(equipmentRented, other.equipmentRented);
        numOfField = other.numOfField;
    }
//    ~Reservation(){
//        delete[] equipmentRented;
//        delete[] Manager_ID;
//        delete[] Date;
//        delete[] ID;
//        delete[] hour;
//        delete[] FieldNumber;
//    }

//    void setHour(char* hour) { this->hour = new char [strlen(hour)+1];
//        strcpy(this->hour, hour); }

    void setID(char* ID) {this->ID = new char [strlen(ID)+1];
        strcpy(this->ID, ID); }

    void setEquipmentRented(char* equipmentRented) {
        if(this->equipmentRented != nullptr)
            delete[] this->equipmentRented;
        this->equipmentRented=new char[strlen(equipmentRented)+1];
        strcpy(this->equipmentRented,equipmentRented);
    }

    void setAll(int hour,char* ID,char* equipmentRented)
    {
        this->hour = hour;
        setID(ID);
        setEquipmentRented(equipmentRented);
    }

    char* getID() const { return ID; }
    char* getEquipmentRented() const { return equipmentRented; }
    char* getlocation() const { return location; }
    char* gettypeOfField() const { return typeOfField; }
    char* getDate() const { return Date; }
    int getHour() const { return hour; }
    int getNumField() const{return numOfField;}


    friend ostream& operator<<(ostream& os, Reservation& reservation) {
        os << "Hour: " << reservation.getHour() << ":00" << endl;
        os << "ID: " << reservation.getID() << endl;
        os << "Equipment Rented: " << reservation.getEquipmentRented() << endl;
        os << "Location: " << reservation.getlocation() << endl;
        os << "Type of Field: " << reservation.gettypeOfField() << endl;
        os << "Date: " << reservation.getDate() << endl;

        return os;
    }

};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_RESERVATION_H
