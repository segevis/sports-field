//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Player.h"
#include "Manager.h"
#include "Reservation.h"
#include "Field.h"
#include "Branch.h"


class DataBase {

protected:

    fstream playerList;
    int playerCounter;
    Player** playerArray;

    fstream managerList;
    int managerCounter;
    Manager** managerArray;

    fstream OrderList;
    int orderCounter;
    Reservation** orderArray;


    fstream AshkelonList;
    int AshkelonCounter;
    Field ** AshkelonArray;

    fstream AshdodList;
    int AshdodCounter;
    Field ** AshdodArray;

    fstream TelAvivList;
    int TelAvivCounter;
    Field ** TelAvivArray;

    fstream BeerShevaList;
    int BeerShevaCounter;
    Field ** BeerShevaArray;


public:
    DataBase();
    ~DataBase();

    void addPlayer(const Player& newPlayer);
    void removePlayer(const char *playerID);
    void printPlayers();

    void AddManager(const Manager &newManager);
    void RemoveManager(const char *ManagerID);
    void PrintManagers();

    void addOrder(Reservation* newOrder);
    void removeOrder(int index);
    void printOrder();

    void addAshkelonField(Field* newOrder);
    void removeAshkelonField(int index);
    void printAshkelonFields();

    void addAshdodField(Field* newOrder);
    void removeAshdodField(int index);
    void printAshdodFields();

    void addTelAvivField(Field* newOrder);
    void removeTelAvivField(int index);
    void printTelAvivFields();

    void addBeerShevaField(Field* newOrder);
    void removeBeerShevaField(int index);
    void printBeerShevaFields();


    int getPlayerCounter() const  {return playerCounter;}
    Player** getPlayerList() {return playerArray;}

    Manager** getManagerlist() {return  managerArray;}
    int getManagerCounter() const {return managerCounter;}

    int getOrderCounter() const  {return orderCounter;}
    Reservation** getOrderList() {return orderArray;}

    int getAshkelonCounter() const  {return AshkelonCounter;}
    Field** getAshkelonList() {return AshkelonArray;}

    int getAshdodCounter() const  {return AshdodCounter;}
    Field** getAshdodList() {return AshdodArray;}

    int getTelAvivCounter() const  {return TelAvivCounter;}
    Field** getTelAvivList() {return TelAvivArray;}

    int getBeerShevaCounter() const  {return BeerShevaCounter;}
    Field** getBeerShevanList() {return BeerShevaArray;}

};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
