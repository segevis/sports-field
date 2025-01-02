#include "Player.h"

void Player::Set_VIP() {
    char choice[MAX];
    int num = -1;
    do {
        cout << "Do you want to be a VIP Client: 1 - YES, 2 - NO." << endl;
        cout << "The price is one time and it costs 150 ILS more." << endl;
        cin.getline(choice,MAX);
        if (int(strlen(choice)) != 1)
            cout << "Invalid option, please try again." << endl;
        else if (!Check_Number(choice[0]))
            cout << "Enter incorrect char, please try again." << endl;
        else if (choice[0] != '1' && choice[0] != '2')
            cout << "Enter 1 or 2 only" << endl;
        else
            num = int(choice[0] - '0');
    }while(num != 1 && num != 2);
    if (num == 1)
        this->VIP = Set_String("Yes");
    else
        this->VIP = Set_String("NO");
}


ostream& operator << (ostream& out, Player& print) {
    out << static_cast<User&>(print);
    out << "VIP: " << print.Get_VIP() << endl;
    out << "Game Card: " << print.Get_Card() << " order/s left to use." <<endl;
    out <<endl;
    return out;
}
