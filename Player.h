#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H


#include "User.h"

#include "User.h"

class Player: public User {
private:
    char* VIP;
    int GameCard;
public :
    Player(char *ID) : User(ID){Set_VIP(); this->GameCard = 0;}


    Player(char *n_ID, char *f_name, char *l_name, char* birth,
           char *n_phone, char *user, char *password, char *address,
           char *vip, char* gender,char* email, int card)
            : User(n_ID,f_name,l_name,gender,email,n_phone,user,password,address,birth) {
        this->VIP = new char[strlen(vip) + 1];
        strcpy(this->VIP, vip);
        this->GameCard = card;
    }

    void Set_VIP();
    void Set_Card(int num){this->GameCard += num;}
    char* Get_VIP(){return this->VIP;}
    int Get_Card(){return this->GameCard;}
    friend ostream& operator << (ostream& out, Player& print);
};

#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_PLAYER_H
