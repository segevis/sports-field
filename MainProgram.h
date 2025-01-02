//
// Created by segev on 2/28/2024.
//

#ifndef SPORT_FIELD_SEGEV_ALONE_MAINPROGRAM_H
#define SPORT_FIELD_SEGEV_ALONE_MAINPROGRAM_H
#include <iostream>
#include "User.h"
#include "Player.h"
#include "DataBase.h"


class MainProgram : public DataBase{
private:

public:
    MainProgram();

    void addPlayer(Player playerToAdd);
};


#endif //SPORT_FIELD_SEGEV_ALONE_MAINPROGRAM_H
