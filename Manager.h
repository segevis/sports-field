#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H


#include "User.h"

class Manager: public User {

private:
    char *location;

public:
    bool Set_Location();
    char * Get_Location(){return this->location;}

    Manager(char *newID) : User(newID) { Set_Location(); }

    Manager(char *n_ID, char *f_name, char *l_name, char *birth,
            char *n_phone, char *user, char *password, char *address,
            char *Location, char *gender, char *email)
            : User(n_ID, f_name, l_name, gender, email, n_phone, user, password, address, birth) {
        location = new char[strlen(Location) + 1];
        strcpy(location, Location);
    }
//    ~Manager(){delete [] this->Manager_ID;}

    friend ostream& operator << (ostream& out, Manager& print);
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_MANAGER_H
