#include "Manager.h"

bool Manager::Set_Location() {
    char temp[MAX];
    cout << "Enter number the Location of the Branch" << endl;
    cout << "1. Ashdod" << endl;
    cout << "2. Ashklon" << endl;
    cout << "3. Tel-Aviv" << endl;
    cout << "4. Beer-Sheva" << endl;
    cin.getline(temp, MAX);
    if (strlen(temp) != 1){
        cout <<"Enter in correct number of chars" << endl;
        return false;
    }
    if (temp[0] != '1' && temp[0] != '2' && temp[0] != '3' && temp[0] != '4'){
        cout <<"You Enter incorrect char please try again" << endl;
        return false;
    }
    if (temp[0] == '1')
        this->location = Set_String("Ashdod");
    else if (temp[0] == '2')
        this->location = Set_String("Ashkelon");
    else if (temp[0] == '3')
        this->location = Set_String("Tel-Aviv");
    else if (temp[0] == '4')
        this->location = Set_String("Beer-Sheva");
    return true;
}

ostream& operator << (ostream& out, Manager& print) {
    out << static_cast<User &>(print);
    cout << "Location of the Branch: ";
    print.PrintAddress(print.Get_Location(), out);
    out << endl;
    return out;
}