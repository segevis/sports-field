#include <iostream>
#include "DataBase.h"
#include "Player.h"

char Int_To_Char(int num) {return char((int)'0' + num);}
static bool Blank_Line(int len)
{
    if (len == 0) {
        cout << "You entered a blank line, please try again." << endl;
        return true;
    }
    return false;

}
char *Set_String(char* str)
{
    char *res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}
static bool Check_Number(char ch) { return ((ch >= '0') && (ch <= '9')); }
bool check_ID(char*& Id)
{
    char ID_check[MAX];
    cout << "Enter an ID, must be only 9 digits" << endl;
    cin.getline(ID_check, MAX);
    int len = int(strlen(ID_check));
    if (Blank_Line(len))
        return false;
    if (len != ID_LIM) {
        cout << "You enter incorrect number of digits, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (!Check_Number(ID_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    Id = Set_String(ID_check);
    return true;
}
bool Check_Date(char* str, int max, int min){
    int len = int(strlen(str));
    if (Blank_Line(strlen(str)))
        return false;
    for (int i = 0; i < len; ++i)
        if (!Check_Number(str[i])) {
            cout << "incorrect char was entered, please try again." << endl;
            return false;
        }
    int check = stoi(str);
    if (check > max|| check <= min) {
        cout << "The number is impossible for a date, please try again." << endl;
        return false;
    }
    return true;
}
bool Set_Date(char*& str){
    char year[MAX], month[MAX], day[MAX];
    do {
        cout << "Enter the year, 2025 is the minimum and 2030 is the maximum." << endl;
        cin.getline(year, MAX);
    } while (!Check_Date(year, 2030,2024));
    do {
        cout << "Enter the number of the month:" << endl;
        cin.getline(month, MAX);
    } while (!Check_Date(month, 12, 0));
    do {
        cout << "Enter the number of the day:" << endl;
        cin.getline(day, MAX);
    } while (!Check_Date(day, 31, 0));
    int check_day = stoi(day);
    int check_month = stoi(month);
    int check_year = stoi(year);
    if (check_month != 1 && check_month != 3 && check_month != 5 && check_month != 7 && check_month != 8 &&
        check_month != 10 && check_month != 12) {
        if (check_day == 31) {
            cout << "The month doesn't have 31 days, please try again." << endl;
            return false;
        } else if (check_month == 2) {
            if (check_day > 29) {
                cout << "The month doesn't have more than 29 days, please try again." << endl;
                return false;
            }
        }
    }
    char temp[11]; // Increase array size to accommodate the null terminator
    temp[0] = Int_To_Char(check_day / 10);
    temp[1] = Int_To_Char(check_day % 10);
    temp[2] = '\\';
    temp[3] = Int_To_Char(check_month / 10);
    temp[4] = Int_To_Char(check_month % 10);
    temp[5] = '\\';
    temp[6] = Int_To_Char(check_year / 1000);
    temp[7] = Int_To_Char((check_year / 100) % 10);
    temp[8] = Int_To_Char((check_year / 10) % 10);
    temp[9] = Int_To_Char(check_year % 10);
    temp[10] = '\0'; // Null terminator to mark the end of the string
    str = new char[11];
    for (int i = 0; i < 11; ++i)
        str[i] = temp[i];
    return true;
}

void EditPlayerName(int index, DataBase &dataBase){
    dataBase.getPlayerList()[index]->Set_Name();
    cout << "The name updated successfully!" << endl;
}
void EditPlayerUsername(int index, DataBase &dataBase) {
    while(!dataBase.getPlayerList()[index]->Set_Username());
    std::cout << "Username updated successfully!\n";
}
void EditPLayerPassword(int index, DataBase &dataBase)
{
    while(!dataBase.getPlayerList()[index]->Get_Password());
    std::cout << "Password updated successfully!\n";
}
void EditPlayerAddress(int index, DataBase &dataBase)
{
    dataBase.getPlayerList()[index]->Set_Address();
    std::cout << "Address updated successfully!\n";
}
void EditPlayerPhone(int index, DataBase &dataBase)
{
    while (!dataBase.getPlayerList()[index]->Set_Phone());
    std::cout << "Phone number updated successfully!\n";
}
void EditPlayerDetails(int index, DataBase &dataBase)
{
    int editChoice;
    do {
        std::cout << "\nEdit Personal Details:\n";
        cout << "1. Edit Name" << endl;
        std::cout << "2. Edit Username\n";
        std::cout << "3. Edit Password\n";
        std::cout << "4. Edit Address\n";
        std::cout << "5. Edit Phone Number\n";
        std::cout << "6. Back to Player Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> editChoice;

        switch (editChoice) {
            case 1:
                EditPlayerName(index, dataBase);
                break;
            case 2:
                EditPlayerUsername(index, dataBase);
                break;
            case 3:
                EditPLayerPassword(index, dataBase);
                break;
            case 4:
                EditPlayerAddress(index, dataBase);
                break;
            case 5:
                EditPlayerPhone(index, dataBase);
                break;
            case 6:
                cout << "Returning to Player Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (editChoice != 6);
}

void EditManagerName(int index, DataBase &dataBase){
    dataBase.getManagerlist()[index]->Set_Name();
    cout << "The name updated successfully!" << endl;
}
void EditManagerAddress(int index, DataBase &dataBase)
{
    dataBase.getManagerlist()[index]->Set_Address();
    cout << "Address updated successfully!\n";
}
void EditManagerUsername(int index, DataBase &dataBase)
{
    while(!dataBase.getManagerlist()[index]->Get_Username());
    cout << "Username updated successfully!\n";
}
void EditManagerPassword(int index, DataBase &dataBase)
{
    while(!dataBase.getManagerlist()[index]->Get_Password());
    cout << "Password updated successfully!\n";
}
void EditManagerGender(int index, DataBase &dataBase)
{
    dataBase.getManagerlist()[index]->Set_Gender();
    cout << "Gender updated successfully!\n";
}
void EditManagerEmail(int index, DataBase &dataBase)
{
    while(!dataBase.getManagerlist()[index]->Set_Email());
    cout << "Email updated successfully!\n";
}
void EditManagerPhone(int index, DataBase &dataBase) {
    while(!dataBase.getManagerlist()[index]->Set_Phone());
    cout << "Phone updated successfully!\n";
}
void EditManagerBirthday(int index, DataBase &dataBase) {
    while(!dataBase.getManagerlist()[index]->Set_Birthday());
    cout << "Birthday updated successfully!\n";
}
void EditManagerDetails(int index, DataBase &dataBase) {
    int editChoice;
    do {
        cout << endl << "Edit Personal Details:" << endl;
        cout << "1. Edit Name" << endl;
        cout << "2. Edit Gender" << endl;
        cout << "3. Edit Email" << endl;
        cout << "4. Edit Phone Number" << endl;
        cout << "5. Edit Username" << endl;
        cout << "6. Edit Password" << endl;
        cout << "7. Edit Address" << endl;
        cout << "8. Edit Birthday" << endl;
        cout << "9. Back to Player Menu" << endl;
        cout << "Enter your choice: ";
        cin >> editChoice;

        switch (editChoice) {
            case 1:
                EditManagerName(index, dataBase);
                break;
            case 2:
                EditManagerGender(index, dataBase);
                break;
            case 3:
                EditManagerEmail(index, dataBase);
                break;
            case 4:
                EditManagerPhone(index, dataBase);
                break;
            case 5:
                EditManagerUsername(index, dataBase);
                break;
            case 6:
                EditManagerPassword(index, dataBase);
                break;
            case 7:
                EditManagerAddress(index, dataBase);
                break;
            case 8:
                EditManagerBirthday(index, dataBase);
                break;
            case 9:
                cout << "Returning to Player Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (editChoice != 9);
}


void PlayerPassRestore(Player** arr, int size){
    bool check = false;
    do {
        getchar();
        char user[MAX], phone[MAX];
        cout << "Enter your username:" << endl;
        cin.getline(user, MAX);
        cout << "Enter your phone number:" << endl;
        cin.getline(phone, MAX);
        for (int i = 0; i < size; ++i) {
            if (strcmp(arr[i]->Get_Username(), user) == 0 && strcmp(arr[i]->Get_Phone(), phone) == 0) {
                cout << arr[i]->Get_Password() << endl;
                check = true;
            }
        }
        if (!check) {
            int option;
            cout << "the Data you entered was incorrect" << endl;
            do {
            cout << "would you like to try again? 1 - Yes 2 - No" << endl;
            cin >> option;
            if (option == 1)
                check = false;
            else if (option ==2)
                check = true;
            else
                cout <<"Enter incorrect option" << endl;
            }while(option != 1 && option !=2);

        }
    }while(!check);

}
void PlayerUserRestore(Player** arr, int size){
    bool check = false;
    do {
        getchar();
        char ID[MAX], phone[MAX];
        cout << "Enter your ID:" << endl;
        cin.getline(ID, MAX);
        cout << "Enter your phone number:" << endl;
        cin.getline(phone, MAX);
        for (int i = 0; i < size; ++i) {
            if (strcmp(arr[i]->Get_ID(), ID) == 0 && strcmp(arr[i]->Get_Phone(), phone) == 0) {
                cout << arr[i]->Get_Username() << endl;
                check = true;
            }
        }
        if (!check) {
            int option;
            cout << "the Data you entered was incorrect" << endl;
            do {
                cout << "would you like to try again? 1 - Yes 2 - No" << endl;
                cin >> option;
                if (option == 1)
                    check = false;
                else if (option ==2)
                    check = true;
                else
                    cout <<"Enter incorrect option" << endl;
            }while(option != 1 && option !=2);

        }
    }while(!check);

}
void ManagerPassRestore(Manager ** arr, int size){
    bool check = false;
    do {
        getchar();
        char user[MAX], phone[MAX];
        cout << "Enter your username:" << endl;
        cin.getline(user, MAX);
        cout << "Enter your phone number:" << endl;
        cin.getline(phone, MAX);
        for (int i = 0; i < size; ++i) {
            if (strcmp(arr[i]->Get_Username(), user) == 0 && strcmp(arr[i]->Get_Phone(), phone) == 0) {
                cout << arr[i]->Get_Password() << endl;
                check = true;
            }
        }
        if (!check) {
            int option;
            cout << "the Data you entered was incorrect" << endl;
            do {
                cout << "would you like to try again? 1 - Yes 2 - No" << endl;
                cin >> option;
                if (option == 1)
                    check = false;
                else if (option ==2)
                    check = true;
                else
                    cout <<"Enter incorrect option" << endl;
            }while(option != 1 && option !=2);

        }
    }while(!check);

}
void ManagerUserRestore(Manager** arr, int size){
    bool check = false;
    do {
        getchar();
        char ID[MAX], phone[MAX];
        cout << "Enter your ID:" << endl;
        cin.getline(ID, MAX);
        cout << "Enter your phone number:" << endl;
        cin.getline(phone, MAX);
        for (int i = 0; i < size; ++i) {
            if (strcmp(arr[i]->Get_ID(), ID) == 0 && strcmp(arr[i]->Get_Phone(), phone) == 0) {
                cout << arr[i]->Get_Username() << endl;
                check = true;
            }
        }
        if (!check) {
            int option;
            cout << "the Data you entered was incorrect" << endl;
            do {
                cout << "would you like to try again? 1 - Yes 2 - No" << endl;
                cin >> option;
                if (option == 1)
                    check = false;
                else if (option ==2)
                    check = true;
                else
                    cout <<"Enter incorrect option" << endl;
            }while(option != 1 && option !=2);

        }
    }while(!check);

}


void Book_Order(int index, DataBase &dataBase) {
    int choice, index_field, hour, option;
    char* date , *rent, *location, *type;
    Reservation * newRes;
    do {
        cout << "Enter the number of Branch you want:" << endl;
        cout << "1. Ashdod" << endl;
        cout << "2. Ashkelon" << endl;
        cout << "3. Tel-Aviv" << endl;
        cout << "4. Beer-Sheva" << endl;
        cin >> choice;
        if (choice < 0 || choice > 4)
            cout << "Enter incorrect option please try again" << endl;
    }while(choice < 0 || choice > 4);
    if (choice == 1) {
        if (dataBase.getAshdodCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printAshdodFields();
        do{
            cout << "choose the field you want:"<< endl;
           cin >> index_field;
           if (index_field > dataBase.getAshdodCounter() || index_field < 0)
               cout << "Enter incorrect option please try again" << endl;
        }while(index_field > dataBase.getAshdodCounter() || index_field < 0);
    }
    else if (choice == 2) {
        if (dataBase.getAshkelonCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printAshkelonFields();
        do{
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getAshkelonCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        }while(index_field > dataBase.getAshkelonCounter() || index_field < 0);
    }
    else if (choice == 3) {
        if (dataBase.getTelAvivCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printTelAvivFields();
        do {
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getTelAvivCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        } while (index_field > dataBase.getTelAvivCounter() || index_field < 0);
    }
    else if (choice == 4) {
        if (dataBase.getBeerShevaCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printBeerShevaFields();
        do {
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getBeerShevaCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        } while (index_field > dataBase.getBeerShevaCounter() || index_field < 0);
    }
    getchar();
    while (!Set_Date(date));
    do {
        cout << "Enter an hour" << endl;
        cin >> hour;
        if (hour < 6 || hour > 21)
            cout << "Enter incorrect hour please try again" << endl ;
    }while(hour < 6 || hour > 21);
    for (int i = 0; i < dataBase.getOrderCounter(); ++i) {
        if(strcmp(date, dataBase.getOrderList()[i]->getDate()) == 0) {
            if (dataBase.getOrderList()[i]->getHour() == 0) {
                cout << "Day mark as unavailable" << endl;
                return;
            }
            if (dataBase.getOrderList()[i]->getHour() == hour) {
                if (strcmp(dataBase.getOrderList()[i]->getID(), dataBase.getPlayerList()[index]->Get_ID()) == 0) {
                    cout << "You already have Order in that time and date." << endl;
                    return;
                } else if (dataBase.getOrderList()[i]->getNumField() == index_field)
                    if ((choice == 1 && (strcmp(dataBase.getOrderList()[i]->getlocation(), "Ashdod") == 0)) ||
                        (choice == 2 && (strcmp(dataBase.getOrderList()[i]->getlocation(), "Ashkelon") == 0)) ||
                        (choice == 3 && (strcmp(dataBase.getOrderList()[i]->getlocation(), "Tel-Aviv") == 0)) ||
                        (choice == 4 && (strcmp(dataBase.getOrderList()[i]->getlocation(), "Beer-Sheva")) == 0)) {
                        cout << "The field is already book in that time " << endl;
                        return;
                    }
            }
        }
    }
    do {
        cout << "This are the equipment you can rent, you can only rent one at order." <<endl;
        cout << "1. Shoes - 10 ILS" <<endl;
        cout << "2. Ball - 25 ILS" << endl;
        cout << "3. Gloves - 15 ILS" << endl;
        cout << "If you dont want any of this enter 0" << endl;
        cin >> option;
        if (option > 3 || option < 0)
            cout << "Invalid option" << endl;
    }while(option > 3 || option < 0);
    if (option == 1)
        rent = Set_String("Shoes");
    else if (option == 2 )
        rent = Set_String("Ball");
    else if (option == 3)
        rent = Set_String("Gloves");
    else
        rent = Set_String("No");
    if (choice == 1) {
        location = Set_String("Ashdod");
        type = Set_String(dataBase.getAshdodList()[index_field-1]->getNameOfField());
    }
    else if (choice == 2 ) {
        location = Set_String("Ashkelon");
        type = Set_String(dataBase.getAshkelonList()[index_field-1]->getNameOfField());
    }
    else if (choice == 3) {
        location = Set_String("Tel-Aviv");
        type = Set_String(dataBase.getTelAvivList()[index_field-1]->getNameOfField());
    }
    else {
        location = Set_String("Beer-Sheva");
        type = Set_String(dataBase.getBeerShevanList()[index_field-1]->getNameOfField());
    }

    newRes = new Reservation(hour,dataBase.getPlayerList()[index]->Get_ID(), rent, date,location,type, index_field);
    dataBase.addOrder(newRes);
    cout << "Order was added successfully!" << endl;
    if (dataBase.getPlayerList()[index]->Get_Card() != 0) {
        dataBase.getPlayerList()[index]->Set_Card(-1);
        cout << "You have " << dataBase.getPlayerList()[index]->Get_Card() << " left" << endl;
    }
    else
        cout << "You have no more credit in your card game consider buy more" <<endl;
    delete[] location;
    delete[] type;
    delete[] rent;

}
void Cancel_order(int index, DataBase &dataBase){
    int num_of_order = 0, del_oder = 0;
    for (int i = 0; i < dataBase.getOrderCounter(); ++i) {
        if (strcmp(dataBase.getOrderList()[i]->getID(), dataBase.getPlayerList()[index]->Get_ID()) == 0) {
            cout << "Order number: " << ++num_of_order << endl;
            cout << *dataBase.getOrderList()[i] << endl;
        }
    }
    if (num_of_order == 0)
        cout << "There aren't any booking in you name." << endl;
    else {
        bool check = true;
        do {
            cout << "Enter the number of the order you want to cancel." << endl;
            cout << "Enter 0 if you want don't want to cancel." << endl;
            cin >> del_oder;
            if (del_oder > num_of_order || del_oder < 0)
                cout << "The option is not valid, please try again." << endl;
            else
                check = false;
        } while (check);
        if (del_oder != 0) {
            num_of_order = 0;
            for (int j = 0; j < dataBase.getOrderCounter(); ++j) {
                if (strcmp(dataBase.getOrderList()[j]->getID(),
                           dataBase.getPlayerList()[index]->Get_ID()) == 0) {
                    ++num_of_order;
                    if (num_of_order == del_oder) {
                        dataBase.removeOrder(j);
                        cout << "The order cancel." <<endl;
                    }
                }
            }
            cout << "Would you like to Place another order instead?" << endl;
            int option;
            do {
                cout << "Enter 1 for yes, enter 2 for no." <<endl;
                cin >> option;
                if (option != 1 && option != 2)
                    cout << "You enter invalid option, please try again." << endl;
            }while(option != 1 && option !=2);
            if (option == 1)
                Book_Order(index, dataBase);
        } else
            cout << "No order was cancel." << endl;
    }
}
void Buying_Card(int index, DataBase &dataBase){
    int option;
    cout << "Average field cost about 150 ILS and the discount will be calculated according to this price." << endl;
    cout << "This are the different types of Game Card We have:" << endl;
    cout << "1. 3 order - game card for 15% discount - Price: 382.5 NIS." << endl;
    cout << "2. 5 order - game card for 25% discount - Price: 562.5 NIS." << endl;
    cout << "3. 7 order - game card for 35% discount - Price: 682.5 NIS." << endl;
    cout << "4. 10 order - game card for 50% discount - Price:750 NIS." << endl;
    do {
        cout << "Enter the number of the option you want." << endl;
        cout << "Enter 0 if you want to cancel." << endl;
        cin >> option;
        if (option < 0 || option > 4){
            cout << "invalid option please try again" << endl;
        }
    }while (option < 0 || option > 4);
    if (option == 1)
        dataBase.getPlayerList()[index]->Set_Card(3);
    else if (option == 2)
        dataBase.getPlayerList()[index]->Set_Card(5);
    else if (option == 3)
        dataBase.getPlayerList()[index]->Set_Card(7);
    else if (option == 4)
        dataBase.getPlayerList()[index]->Set_Card(10);
    else
        cout << "No game card was bought." << endl;
    cout << "You have " << dataBase.getPlayerList()[index]->Get_Card() << " orders left to use" << endl;
}
void AboutUs(DataBase &dataBase){
    cout << "Branch: Ashdod" <<endl;
    cout << "Branch Ashdod is located in Rogozin st. 15." << endl;
    if (dataBase.getAshdodCounter() != 0) {
        cout << "Branch Ashdod has the following fields:" << endl << endl;
        dataBase.printAshdodFields();
    }
    else
        cout << "The branch doesn't have field it." << endl;

    cout << endl << "Branch: Ashklon" <<endl;
    cout << "Branch Ashkelon is located in Haziyunot st. 3." << endl;
    if (dataBase.getAshkelonCounter() != 0) {
        cout << "Branch Ashdod has the following fields:" << endl << endl;
        dataBase.printAshkelonFields();
    }
    else
        cout << "The branch doesn't have field it." << endl;

    cout << endl << "Branch: Tel Aviv" <<endl;
    cout << "Branch Ashkelon is located in heaven Gvirol st. 9." << endl;
    if (dataBase.getTelAvivCounter() != 0) {
        cout << "Branch Ashdod has the following fields:" << endl << endl;
        dataBase.printTelAvivFields();
    }
    else
        cout << "The branch doesn't have field it." << endl;

    cout << endl << "Branch: Tel Aviv" <<endl;
    cout << "Branch Ashkelon is located in heaven shapira st. 4." << endl;
    if (dataBase.getBeerShevaCounter() != 0) {
        cout << "Branch Ashdod has the following fields:" << endl << endl;
        dataBase.printBeerShevaFields();
    }
    else
        cout << "The branch doesn't have field it." << endl;
}

void AddField(int index, DataBase &dataBase) {
    getchar();
    Field * tempField;
    char temp[MAX], *type;
    int len, width, price;
    bool check;
    do {
        check = true;
        cout << "Enter number the type of the field" << endl;
        cout << "1. Tennis" << endl;
        cout << "2. Basketball" << endl;
        cout << "3. Football" << endl;
        cout << "4. Baseball" << endl;
        cin.getline(temp, MAX);
        if (strlen(temp) != 1) {
            cout << "Enter in correct number of chars" << endl;
            check = false;
        } else if (temp[0] != '1' && temp[0] != '2' && temp[0] != '3' && temp[0] != '4') {
            cout << "You Enter incorrect char please try again" << endl;
            check = false;
        }
    }while(!check);
    if (temp[0] == '1') {
        type = Set_String("Tennis");
        len = 24;
        width = 9;
        price = 50;
    }
    else if (temp[0] == '2') {
        type = Set_String("Basketball");
        len = 28;
        width = 15;
        price = 100;
    }
    else if (temp[0] == '3') {
        type = Set_String("Football");
        len = 100;
        width = 75;
        price = 150;
    }
    else if (temp[0] == '4'){
        type = Set_String("Baseball");
        len = 300;
        width = 300;
        price = 250;
    }
    if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashdod") == 0) {
        tempField = new Field(type, dataBase.getManagerlist()[index]->Get_ID(), dataBase.getAshdodCounter() + 1, len, width, price);
        dataBase.addAshdodField(tempField);
    }
    else if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashkelon") == 0) {
        tempField = new Field(type, dataBase.getManagerlist()[index]->Get_ID(), dataBase.getAshkelonCounter() + 1, len, width, price);
        dataBase.addAshkelonField(tempField);
    }
    else if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Tel-Aviv") == 0) {
        tempField = new Field(type, dataBase.getManagerlist()[index]->Get_ID(), dataBase.getTelAvivCounter() + 1, len, width, price);
        dataBase.addTelAvivField(tempField);
    }
    else if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Beer-Sheva") == 0) {
        tempField = new Field(type, dataBase.getManagerlist()[index]->Get_ID(), dataBase.getBeerShevaCounter() + 1, len, width, price);
        dataBase.addBeerShevaField(tempField);
    }
    cout << "Field added Successfully" << endl;
}
void RemoveField(int index, DataBase&dataBase){
    if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashdod") == 0) {
        for (int i = 0; i < dataBase.getAshdodCounter(); ++i) {
            if (strcmp(dataBase.getManagerlist()[index]->Get_ID(), dataBase.getAshdodList()[i]->GetManagerID()) == 0)
                cout << *dataBase.getAshdodList()[i] << endl;
            cout << "Do you want to delete this fields? 1 - yes else enter any char" << endl;
            char option;
            cin >> option;
            if (option == '1') {
                dataBase.removeAshdodField(i);
                break;
            }
        }
    }
    else if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashkelon") == 0) {
        for (int i = 0; i < dataBase.getAshkelonCounter(); ++i) {
            if (strcmp(dataBase.getManagerlist()[index]->Get_ID(), dataBase.getAshkelonList()[i]->GetManagerID()) == 0)
                cout << *dataBase.getAshkelonList()[i] << endl;
            cout << "Do you want to delete this fields? 1 - yes else enter any char" << endl;
            char option;
            cin >> option;
            if (option == '1') {
                dataBase.removeAshkelonField(i);
                break;
            }
        }
    }
    else if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Tel-Aviv") == 0) {
        for (int i = 0; i < dataBase.getTelAvivCounter(); ++i) {
            if (strcmp(dataBase.getManagerlist()[index]->Get_ID(), dataBase.getTelAvivList()[i]->GetManagerID()) == 0)
                cout << *dataBase.getTelAvivList()[i] << endl;
            cout << "Do you want to delete this fields? 1 - yes else enter any char" << endl;
            char option;
            cin >> option;
            if (option == '1') {
                dataBase.removeTelAvivField(i);
                break;
            }
        }
    }
    else if(strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Beer-Sheva") == 0) {
        for (int i = 0; i < dataBase.getBeerShevaCounter(); ++i) {
            if (strcmp(dataBase.getManagerlist()[index]->Get_ID(), dataBase.getBeerShevanList()[i]->GetManagerID()) == 0)
                cout << *dataBase.getBeerShevanList()[i] << endl;
            cout << "Do you want to delete this fields? 1 - yes else enter any char" << endl;
            char option;
            cin >> option;
            if (option == '1') {
                dataBase.removeBeerShevaField(i);
                break;
            }
        }
    }

}
void UnavailableField(int index, DataBase&dataBase){
    int index_field;
    char * date;
    if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashdod") == 0) {
        if (dataBase.getAshdodCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printAshdodFields();
        do{
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getAshdodCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        }while(index_field > dataBase.getAshdodCounter() || index_field < 0);
    }
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashkelon") == 0) {
        if (dataBase.getAshkelonCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printAshkelonFields();
        do{
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getAshkelonCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        }while(index_field > dataBase.getAshkelonCounter() || index_field < 0);
    }
    if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Tel-Aviv") == 0) {
        if (dataBase.getTelAvivCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printTelAvivFields();
        do {
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getTelAvivCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        } while (index_field > dataBase.getTelAvivCounter() || index_field < 0);
    }
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Beer-Sheva") == 0) {
        if (dataBase.getBeerShevaCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printBeerShevaFields();
        do {
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getBeerShevaCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        } while (index_field > dataBase.getBeerShevaCounter() || index_field < 0);
    }
    getchar();
    while (!Set_Date(date));
    for (int i = 0; i < dataBase.getOrderCounter(); ++i) {
        if (strcmp(date, dataBase.getOrderList()[i]->getDate()) == 0) {
            if (dataBase.getOrderList()[i]->getNumField() == index_field)
                if ((strcmp(dataBase.getManagerlist()[index]->Get_Location(),
                            dataBase.getOrderList()[i]->getlocation()) == 0))
                    cout << "The field is already book in that date " << endl;
            return;
        }
    }
    Reservation * UnRes;
    UnRes = new Reservation(0,dataBase.getManagerlist()[index]->Get_ID(),"None", date, dataBase.getManagerlist()[index]->Get_Location(), dataBase.getOrderList()[index_field-1]->gettypeOfField(), index);
    dataBase.addOrder(UnRes);
    cout << "The field was marked as unavailable in that time" << endl;
}
void Print_FieldOfManager(int index, DataBase &dataBase) {
    bool hours[16];
    char* date;
    getchar();
    while(!Set_Date(date));
    for (int i = 0; i < 15; ++i) {
        hours[i] = false;
    }
    int index_field;
    if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashdod") == 0) {
        if (dataBase.getAshdodCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printAshdodFields();
        do{
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getAshdodCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        }while(index_field > dataBase.getAshdodCounter() || index_field < 0);
    }
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Askelon") == 0) {
        if (dataBase.getAshkelonCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printAshkelonFields();
        do{
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getAshkelonCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        }while(index_field > dataBase.getAshkelonCounter() || index_field < 0);
    }
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Tel-Aviv") == 0) {
        if (dataBase.getTelAvivCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printTelAvivFields();
        do {
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getTelAvivCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        } while (index_field > dataBase.getTelAvivCounter() || index_field < 0);
    }
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Beer-Sheva") == 0) {
        if (dataBase.getBeerShevaCounter() == 0) {
            cout << "there aren't any fields yet" << endl;
            return;
        }
        dataBase.printBeerShevaFields();
        do {
            cout << "choose the field you want:"<< endl;
            cin >> index_field;
            if (index_field > dataBase.getBeerShevaCounter() || index_field < 0)
                cout << "Enter incorrect option please try again" << endl;
        } while (index_field > dataBase.getBeerShevaCounter() || index_field < 0);
    }
    for (int i = 0; i < dataBase.getOrderCounter(); ++i) {
        if (strcmp(dataBase.getOrderList()[i]->getlocation(), dataBase.getManagerlist()[index]->Get_Location()) == 0)
            if(dataBase.getOrderList()[i]->getNumField() == index_field)
                if (strcmp(dataBase.getOrderList()[i]->getDate(), date) == 0) {
                    cout << dataBase.getOrderList()[i]->getHour() << endl;
                    hours[dataBase.getOrderList()[i]->getHour() - 6] = true;
                }
    }
    if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashdod") == 0)
        dataBase.getAshdodList()[index_field]->displaySchedule(hours,date);
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Ashkelon") == 0)
        dataBase.getAshkelonList()[index_field]->displaySchedule(hours,date);
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Tel-Aviv") == 0)
        dataBase.getTelAvivList()[index_field]->displaySchedule(hours,date);
    else if (strcmp(dataBase.getManagerlist()[index]->Get_Location(), "Beer-Sheva") == 0)
        dataBase.getBeerShevanList()[index_field]->displaySchedule(hours,date);
}

void playerMenu(int index, DataBase &dataBase)
{

    int choice;
    do {
        system("pause");
        system("cls");
        cout << "\nPlayer Menu:\n";
        cout << "1. View Profile\n";
        cout << "2. Edit Personal Details\n";
        cout << "3. Book a Field\n";
        cout << "4. Cancel a Booking" <<endl;
        cout << "5. View Booking History\n";
        cout << "6. Buying Game Card" <<endl;
        cout << "7. About Us" <<endl;
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        getchar();

        switch (choice) {
            case 1:
                system("pause");
                system("cls");
                cout << "Viewing Profile...\n";
                cout << endl;
                cout << *dataBase.getPlayerList()[index];
                break;
            case 2:
                system("pause");
                system("cls");
                std::cout << "Editing Personal Details...\n";
                EditPlayerDetails(index, dataBase);
                break;
            case 3: {
                system("pause");
                system("cls");
                std::cout << "Booking a Field...\n";
                Book_Order(index, dataBase);
                break;
            }
            case 4: {
                system("pause");
                system("cls");
                cout << "Canceling Booking..." << endl;
                Cancel_order(index, dataBase);
                break;
            }
            case 5: {
                system("pause");
                system("cls");
                std::cout << "Viewing Booking History...\n";
                for (int i = 0; i < dataBase.getOrderCounter(); ++i) {
                    if (strcmp(dataBase.getPlayerList()[index]->Get_ID(), dataBase.getOrderList()[i]->getID()) == 0)
                        cout << *dataBase.getOrderList()[i] << endl;
                }
                break;
            }
            case 6:{
                system("pause");
                system("cls");
                cout << "Buying Game Card..." << endl;
                Buying_Card(index, dataBase);
                break;
            }
            case 7:{
                system("pause");
                system("cls");
                cout << "About Us..." << endl;
                AboutUs(dataBase);

            }
            case 8:
                system("pause");
                system("cls");
                std::cout << "Logging out...\n";
                break;
            default:
                system("pause");
                system("cls");
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
}

void managerMenu(int index, DataBase &dataBase){
    int choice;
    do {
        system("pause");
        system("cls");
        cout << "\nManager Menu:\n";
        cout << "1. View Profile\n";
        cout << "2. Edit Personal Details\n";  // New option
        cout << "3. Add Field" << endl;
        cout << "4. Delete Field" << endl;
        cout << "5. Make Field Unavailable" << endl;
        cout << "6. Print Fields schedule" <<endl;
        cout << "7. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("pause");
                system("cls");
                std::cout << "Viewing Profile...\n";
                cout << endl;
                cout << *dataBase.getManagerlist()[index];
                break;
            case 2:
                system("pause");
                system("cls");
                std::cout << "Editing Personal Details...\n";
                EditManagerDetails(index, dataBase);
                break;
            case 3:
                system("pause");
                system("cls");
                cout << "Adding Fields..." <<endl;
                AddField(index, dataBase);
                break;
            case 4:
                system("pause");
                system("cls");
                cout << "Removing Fields..." <<endl;
                RemoveField(index, dataBase);
                break;
            case 5:
                system("pause");
                system("cls");
                cout << "Making Fields Unavailable..." <<endl;
                UnavailableField(index, dataBase);
                break;
            case 6:
                system("pause");
                system("cls");
                cout << "Displaying Fields Schedule..." <<endl;
                Print_FieldOfManager(index, dataBase);
            case 7:
                system("pause");
                system("cls");
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}


int main() {
    DataBase D;

    int choice;
    do {
        do {
            std::cout << "Hello ! Welcome to Sami Sports Field Rental.\n"
                         "for existing member press 1. \n"
                         "for New member press 2.\n"
                         "To exit the system press 3." << endl;
            std::cin >> choice;
            system("pause");
            system("cls");

            if (choice != 1 && choice != 2 && choice != 3)
                std::cout << "The selection is not supported by the system. Please select again.\n";

        } while (choice != 1 && choice != 2 && choice != 3);

        switch (choice) {
            case 1: {
                bool flag = false;
                do {
                    std::cout << "Welcome back!\n"
                                 "To sign in as a new player press 1\n"
                                 "To sign in as a new manager press 2\n";
                    std::cin >> choice;

                    if (choice != 1 && choice != 2)
                        std::cout << "The selection is not supported by the system. Please select again.\n";

                } while (choice != 1 && choice != 2);
                do {
                    char usernameC[100], passwordC[100];
                    int index_pass = -2, index_user = -1;
                    cout << "Enter your Username" << endl;
                    cin >> usernameC;
                    cout << "Enter your Password" << endl;
                    cin >> passwordC;
                    switch (choice) {
                        case 1: {
                            for (int i = 0; i < D.getPlayerCounter(); ++i) {
                                if (strcmp(D.getPlayerList()[i]->Get_Username(), usernameC) == 0)
                                    index_user = i;
                                if (strcmp(D.getPlayerList()[i]->Get_Password(), passwordC) == 0)
                                    index_pass = i;
                            }
                            if (index_pass == -2 && index_user == -1)
                                cout << "You entered incorrect number" << endl;
                            else if (index_user == index_pass) {
                                cout << "You login successfully!" << endl;
                                flag = true;
                                playerMenu(index_user, D);
                            } else
                                cout << "The username and password aren't match" << endl;

                            break;
                        }
                        case 2: {
                            for (int i = 0; i < D.getManagerCounter(); ++i) {
                                if (strcmp(D.getManagerlist()[i]->Get_Username(), usernameC) == 0)
                                    index_user = i;
                                if (strcmp(D.getManagerlist()[i]->Get_Password(), passwordC) == 0)
                                    index_pass = i;
                            }
                            if (index_pass == -2 && index_user == -1)
                                cout << "You entered in correct data" << endl;
                            else if (index_user == index_pass) {
                                cout << "You login successfully!" << endl;
                                flag = true;
                                managerMenu(index_user, D);
                            } else
                                cout << "The username and password aren't match" << endl;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    if (!flag) {
                        int check;
                        do {
                            cout << "If you want to try again please enter 1." << endl;
                            cout << "If you want to retrieve your username please enter 2." << endl;
                            cout << "If you want to retrieve your password please enter 3." << endl;
                            cout << "If you want to leave the system enter 4" << endl;
                            cin >> check;
                            flag = false;
                            if (check == 1)
                                cout << "Going back to the login" << endl;
                            else if (check == 2 && choice == 1)
                                PlayerUserRestore(D.getPlayerList(), D.getPlayerCounter());
                            else if (check == 2 && choice == 2)
                                ManagerUserRestore(D.getManagerlist(), D.getManagerCounter());
                            else if (check == 3 && choice == 1)
                                PlayerPassRestore(D.getPlayerList(), D.getPlayerCounter());
                            else if (check == 3 && choice == 2)
                                ManagerPassRestore(D.getManagerlist(), D.getManagerCounter());
                            else if (check == 4)
                                flag = true;
                            else
                                cout << "incorrect option" << endl;
                        } while (check != 1 && check != 2 && check != 3 && check != 4);
                    }
                } while (!flag);

                break;
            }
            case 2: {
                do {
                    cout << "Glad you decided to join us!\n"
                            "To register as a new player press 1\n"
                            "To register as a new manager press 2\n";
                    cin >> choice;

                    if (choice != 1 && choice != 2)
                        cout << "The selection is not supported by the system. Please select again.\n";

                } while (choice != 1 && choice != 2);

                switch (choice) {
                    case 1: {
                        cout << "Welcome !\n"
                                "In order to complete your registration as a new member in our system,\n"
                                "we need some additional details from you.\n";
                        cout << "Insert an ID card to check if you exist in the system:" << endl;
                        char *id = nullptr;
                        getchar();
                        while (!check_ID(id));
                        bool flag = false;

                        for (int i = 0; i < D.getPlayerCounter(); ++i) {
                            if (strcmp(D.getPlayerList()[i]->Get_ID(), id) == 0) {
                                cout << "You exist in the system!" << endl;
                                flag = true;
                                break;
                            }

                        }
                        if (!flag) {
                            Player newPlayer(id);
                            bool check1, check2;
                            do {
                                check1 = true;
                                for (int i = 0; i < D.getPlayerCounter(); ++i) {
                                    if (strcmp(D.getPlayerList()[i]->Get_Email(), newPlayer.Get_Email()) == 0) {
                                        cout << "The email is already exist, please enter another" << endl;
                                        check1 = false;
                                        while (!newPlayer.Set_Email());
                                        break;
                                    }
                                }
                            } while (!check1);
                            do {
                                check2 = true;
                                for (int i = 0; i < D.getPlayerCounter(); ++i) {
                                    if (strcmp(D.getPlayerList()[i]->Get_Phone(), newPlayer.Get_Phone()) == 0) {
                                        cout << "The phone number is already exist, please enter another" << endl;
                                        check2 = false;
                                        while (!newPlayer.Set_Phone());
                                    }
                                }
                            } while (!check2);
                            D.addPlayer(newPlayer);
                            std::cout << "Welcome you have successfully registered you can log in." << std::endl;

                        }
                        delete[] id;
                        break;
                    }
                    case 2: {
                        std::cout << "Welcome !\n"
                                     "In order to complete your registration as a new manager in our system,\n"
                                     "we need some additional details from you.\n";
                        cout << "Insert an ID number to check if you exist in the system:" << endl;
                        char *id = nullptr;
                        getchar();
                        while (!check_ID(id));
                        bool flag = false;

                        for (int i = 0; i < D.getManagerCounter(); ++i) {
                            if (strcmp(D.getManagerlist()[i]->Get_ID(), id) == 0) {
                                cout << "You exist in the system!" << endl;
                                flag = true;
                                break;
                            }

                        }
                        if (!flag) {
                            Manager newManger(id);
                            char temp[5];
                            temp[0] = newManger.Get_Birthday()[6];
                            temp[1] = newManger.Get_Birthday()[7];
                            temp[2] = newManger.Get_Birthday()[8];
                            temp[3] = newManger.Get_Birthday()[9];
                            temp[4] = '\n';
                            int num = stoi(temp);
                            if (num > 2003)
                                cout << "You are to young to be a Manger" << endl;
                            else {
                                D.AddManager(newManger);
                                cout << "Welcome you have successfully registered you can log in." << endl;
                            }
                        }
                        delete[] id;
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
    }while(choice != 3);
    cout << "Goodbye, hope to see you again soon!" << endl;
    return 0;
}
