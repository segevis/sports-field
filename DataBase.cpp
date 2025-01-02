#include "DataBase.h"
const std::string FILE_PATH_PLAYER = "C:\\Users\\user\\Desktop\\SportFields\\player list";
const std::string FILE_PATH_MANAGER = "C:\\Users\\user\\Desktop\\SportFields\\manager list";
const std::string FILE_PATH_ORDERS = "C:\\Users\\user\\Desktop\\SportFields\\order";
const std::string FILE_PATH_ASHKELON = "C:\\Users\\user\\Desktop\\SportFields\\BranchAshkelon";
const std::string FILE_PATH_ASHDOD = "C:\\Users\\user\\Desktop\\SportFields\\BranchAshdod";
const std::string FILE_PATH_TELAVIV = "C:\\Users\\user\\Desktop\\SportFields\\BranchTelAviv";
const std::string FILE_PATH_BEERSHEVA = "C:\\Users\\user\\Desktop\\SportFields\\BranchBeerSheva";

DataBase::DataBase() {
    ///////////////////////////////////////////////////////////////Player//////////////////////////////////////////////////////
    {
        playerList.open(FILE_PATH_PLAYER, std::ios::in);

        if (!playerList) {
            std::cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_PLAYER
                      << std::endl;
            return;
        }

        playerCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (playerList.peek() != EOF) {
            playerList.getline(temp, 1000);
            playerCounter++;
        }

        playerList.clear(); // Clear the end-of-file flag
        playerList.seekg(0, std::ios::beg);

        playerArray = new Player *[playerCounter];
        char id[50], fName[50], lName[50], date[50], phone[50], userName[50], password[50], address[50], vip[50], gender[50], email[100], card[100];

        for (int i = 0; i < playerCounter; ++i) {
            playerList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address,
                   vip, gender, email, card);
            playerArray[i] = new Player(id, fName, lName, date, phone, userName, password, address, vip, gender, email, atoi(card));
        }

    }
    playerList.close();
///////////////////////////////////////////////////////////////Manager//////////////////////////////////////////////////////

    {
        managerList.open(FILE_PATH_MANAGER, std::ios::in);

        if (!managerList) {
            std::cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_PLAYER
                      << std::endl;
            return;
        }
        managerCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (managerList.peek() != EOF) {
            managerList.getline(temp, 1000);
            managerCounter++;
        }

        managerList.clear(); // Clear the end-of-file flag
        managerList.seekg(0, std::ios::beg);

        managerArray = new Manager *[managerCounter];
        char id[50], fName[50], lName[50], date[50], phone[50], userName[50], password[50], address[50], location[50], gender[50], email[100];

        for (int i = 0; i < managerCounter; ++i) {
            managerList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address,
                   location, gender, email);
            managerArray[i] = new Manager(id, fName, lName, date, phone, userName, password, address, location, gender,
                                          email);
        }

    }
    managerList.close();
///////////////////////////////////////////////////////////////Order//////////////////////////////////////////////////////

    {
        OrderList.open(FILE_PATH_ORDERS, std::ios::in);

        if (!OrderList) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_ORDERS << endl;
            return;
        }
        orderCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (OrderList.peek() != EOF) {
            OrderList.getline(temp, 1000);
            orderCounter++;
        }

        OrderList.clear(); // Clear the end-of-file flag
        OrderList.seekg(0, std::ios::beg);

        orderArray = new Reservation *[orderCounter];
        char id[50], location[50], field[50], date[50], hour[50], rent[50], num[50];

        for (int i = 0; i < orderCounter; ++i) {
            OrderList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s", id, location, field, num, date, hour, rent);
            orderArray[i] = new Reservation(atoi(hour), id, rent, date, location, field, atoi(num));
        }

    }
    OrderList.close();
    ///////////////////////////////////////////////////////////////Ashkelon//////////////////////////////////////////////////////
    {
        AshkelonList.open(FILE_PATH_ASHKELON, std::ios::in);

        if (!AshkelonList) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_ASHKELON << endl;
            return;
        }
        AshkelonCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (AshkelonList.peek() != EOF) {
            AshkelonList.getline(temp, 1000);
            AshkelonCounter++;
        }

        AshkelonList.clear(); // Clear the end-of-file flag
        AshkelonList.seekg(0, std::ios::beg);

        AshkelonArray = new Field *[AshkelonCounter];
        char ID[50], number[50], name[50], len[50], width[50], price[50];

        for (int i = 0; i < AshkelonCounter; ++i) {
            AshkelonList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s", ID, name, number, len, width, price);
            AshkelonArray[i] = new Field(name, ID, atoi(number), atoi(len), atoi(width), atoi(price));
        }

    }
    AshkelonList.close();


    ///////////////////////////////////////////////////////////////Ashdod//////////////////////////////////////////////////////
    {
        AshdodList.open(FILE_PATH_ASHDOD, ios::in);

        if (!AshdodList) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_ASHDOD << endl;
            return;
        }
        AshdodCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (AshdodList.peek() != EOF) {
            AshdodList.getline(temp, 1000);
            AshdodCounter++;
        }

        AshdodList.clear(); // Clear the end-of-file flag
        AshdodList.seekg(0, std::ios::beg);

        AshdodArray = new Field *[AshdodCounter];
        char ID[50], number[50], name[50], len[50], width[50], price[50];

        for (int i = 0; i < AshdodCounter; ++i) {
            AshdodList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s", ID, name, number, len, width, price);
            AshdodArray[i] = new Field(name, ID, atoi (number), atoi(len), atoi(width), atoi(price));
        }

    }
    AshdodList.close();

    ///////////////////////////////////////////////////////////////Tel-Aviv//////////////////////////////////////////////////////
    {
        TelAvivList.open(FILE_PATH_TELAVIV, ios::in);

        if (!TelAvivList) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_TELAVIV << endl;
            return;
        }
        TelAvivCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (TelAvivList.peek() != EOF) {
            TelAvivList.getline(temp, 1000);
            TelAvivCounter++;
        }

        TelAvivList.clear(); // Clear the end-of-file flag
        TelAvivList.seekg(0, std::ios::beg);

        TelAvivArray = new Field *[TelAvivCounter];
        char ID[50], number[50], name[50], len[50], width[50], price[50];

        for (int i = 0; i < TelAvivCounter; ++i) {
            TelAvivList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s", ID, name, number, len, width, price);
            TelAvivArray[i] = new Field(name, ID, atoi(number), atoi(len), atoi(width), atoi(price));
        }

    }
    TelAvivList.close();

    ///////////////////////////////////////////////////////////////Beer-Sheva//////////////////////////////////////////////////////
    {
        BeerShevaList.open(FILE_PATH_BEERSHEVA, ios::in);

        if (!BeerShevaList) {
            cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH_BEERSHEVA << endl;
            return;
        }
        BeerShevaCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (BeerShevaList.peek() != EOF) {
            BeerShevaList.getline(temp, 1000);
            BeerShevaCounter++;
        }

        BeerShevaList.clear(); // Clear the end-of-file flag
        BeerShevaList.seekg(0, std::ios::beg);

        BeerShevaArray = new Field *[BeerShevaCounter];
        char ID[50], number[50], name[50], len[50], width[50], price[50];

        for (int i = 0; i < BeerShevaCounter; ++i) {
            BeerShevaList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s", ID, name, number, len, width, price);
            BeerShevaArray[i] = new Field(name, ID, atoi(number), atoi(len), atoi(width), atoi(price));
        }

    }
    BeerShevaList.close();
}




DataBase::~DataBase()
{
    ///////////////////////////////////////////////////////////////Player//////////////////////////////////////////////////////
    ofstream ofs(FILE_PATH_PLAYER, std::ofstream::out | ofstream::trunc);

    if (!ofs.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH_PLAYER << std::endl;
        return;
    }

    for (int i = 0; i < playerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = playerArray[i]->Get_ID();
        const char* firstName = playerArray[i]->Get_First_Name();
        const char* lastName = playerArray[i]->Get_Last_Name();
        const char* birthday = playerArray[i]->Get_Birthday();
        const char* phone = playerArray[i]->Get_Phone();
        const char* username = playerArray[i]->Get_Username();
        const char* password = playerArray[i]->Get_Password();
        const char* address = playerArray[i]->Get_Address();
        const char* vip = playerArray[i]->Get_VIP();
        const char* gender = playerArray[i]->Get_Gender();
        const char* email = playerArray[i]->Get_Email();
        const int card =playerArray[i]->Get_Card();

        // Write values to the file
        ofs << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << vip << " " << gender << " " << email << " " << card << std::endl;

    }

    ofs.close(); // Close the file after writing

    for (int i = 0; i < playerCounter; ++i)
    {
        delete playerArray[i];
    }
    delete[] playerArray;


    ///////////////////////////////////////////////////////////////Manager//////////////////////////////////////////////////////

    std::ofstream ofs1(FILE_PATH_MANAGER, std::ofstream::out | std::ofstream::trunc);

    if (!ofs1.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH_MANAGER << std::endl;
        return;
    }

    for (int i = 0; i < managerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = managerArray[i]->Get_ID();
        const char* firstName = managerArray[i]->Get_First_Name();
        const char* lastName = managerArray[i]->Get_Last_Name();
        const char* birthday = managerArray[i]->Get_Birthday();
        const char* phone = managerArray[i]->Get_Phone();
        const char* username = managerArray[i]->Get_Username();
        const char* password = managerArray[i]->Get_Password();
        const char* address = managerArray[i]->Get_Address();
        const char* location = managerArray[i]->Get_Location();
        const char* gender = managerArray[i]->Get_Gender();
        const char* email = managerArray[i]->Get_Email();

        // Write values to the file
        ofs1 << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << location << " " << gender << " " << email << std::endl;

    }

    ofs1.close(); // Close the file after writing

    for (int i = 0; i < managerCounter; ++i)
    {
        delete managerArray[i];
    }
    delete[] managerArray;

///////////////////////////////////////////////////////////////Orders//////////////////////////////////////////////////////

    std::ofstream ofs3(FILE_PATH_ORDERS, std::ofstream::out | std::ofstream::trunc);
    if (!ofs3.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH_ORDERS << std::endl;
        return;
    }
    for (int i = 0; i < orderCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = orderArray[i]->getID();
        const char* location = orderArray[i]->getlocation();
        const char* rent = orderArray[i]->getEquipmentRented();
        const int hour = orderArray[i]->getHour();
        const char* typeOfField = orderArray[i]->gettypeOfField();
        const char* Date = orderArray[i]->getDate();
        const int num = orderArray[i]->getNumField();

        // Write values to the file
        ofs3 << id << " " << location << " " << typeOfField << " " << num << " " << Date << " "
             << hour << " " << rent << endl;

    }
    for (int i = 0; i < orderCounter; ++i)
    {
        delete orderArray[i];
    }
    delete[] orderArray;

    ///////////////////////////////////////////////////////////////Ashklon//////////////////////////////////////////////////////

    ofstream ofs4(FILE_PATH_ASHKELON, ofstream::out | ofstream::trunc);
    if (!ofs4.is_open()) {
        cerr << "Error: Unable to open file for writing: " << FILE_PATH_ASHKELON << endl;
        return;
    }
    for (int i = 0; i < AshkelonCounter; ++i) {
        // Store values in temporary variables
        const char* ID = AshkelonArray[i]->GetManagerID();
        const char* name = AshkelonArray[i]->getNameOfField();
        const int Num = AshkelonArray[i]->GetFieldNumber();
        const int len = AshkelonArray[i]->getLength();
        const int width = AshkelonArray[i]->getWidth();
        const int price = AshkelonArray[i]->getPricePerHour();

        // Write values to the file
        ofs4 << ID << " " << name << " " << Num << " " << len << " " << width << " " << price << endl;
    }
    for (int i = 0; i < AshkelonCounter; ++i)
        delete AshkelonArray[i];
    delete[] AshkelonArray;


   ///////////////////////////////////////////////////////////////Ashdod//////////////////////////////////////////////////////

    ofstream ofs5(FILE_PATH_ASHDOD, ofstream::out | ofstream::trunc);
    if (!ofs5.is_open()) {
        cerr << "Error: Unable to open file for writing: " << FILE_PATH_ASHDOD << endl;
        return;
    }
    for (int i = 0; i < AshdodCounter; ++i) {
        // Store values in temporary variables
        const char* ID = AshdodArray[i]->GetManagerID();
        const char* name = AshdodArray[i]->getNameOfField();
        const int Num = AshdodArray[i]->GetFieldNumber();
        const int len = AshdodArray[i]->getLength();
        const int width = AshdodArray[i]->getWidth();
        const int price = AshdodArray[i]->getPricePerHour();

        // Write values to the file
        ofs5 << ID << " " << name << " " << Num << " " << len << " " << width << " " << price << endl;
    }
    for (int i = 0; i < AshdodCounter; ++i)
        delete AshdodArray[i];
    delete[] AshdodArray;


    ///////////////////////////////////////////////////////////////Tel-Aviv//////////////////////////////////////////////////////

    ofstream ofs6(FILE_PATH_TELAVIV, ofstream::out | ofstream::trunc);
    if (!ofs6.is_open()) {
        cerr << "Error: Unable to open file for writing: " << FILE_PATH_TELAVIV << endl;
        return;
    }
    for (int i = 0; i < TelAvivCounter; ++i) {
        // Store values in temporary variables
        const char* ID = TelAvivArray[i]->GetManagerID();
        const char* name = TelAvivArray[i]->getNameOfField();
        const int Num = TelAvivArray[i]->GetFieldNumber();
        const int len = TelAvivArray[i]->getLength();
        const int width = TelAvivArray[i]->getWidth();
        const int price = TelAvivArray[i]->getPricePerHour();

        // Write values to the file
        ofs6 << ID << " " << name << " " << Num << " " << len << " " << width << " " << price << endl;
    }
    for (int i = 0; i < TelAvivCounter; ++i)
        delete TelAvivArray[i];
    delete[] TelAvivArray;


    ///////////////////////////////////////////////////////////////Ashklon//////////////////////////////////////////////////////

    ofstream ofs7(FILE_PATH_ASHKELON, ofstream::out | ofstream::trunc);
    if (!ofs7.is_open()) {
        cerr << "Error: Unable to open file for writing: " << FILE_PATH_ASHKELON << endl;
        return;
    }
    for (int i = 0; i < BeerShevaCounter; ++i) {
        // Store values in temporary variables
        const char* ID = BeerShevaArray[i]->GetManagerID();
        const char* name = BeerShevaArray[i]->getNameOfField();
        const int Num = BeerShevaArray[i]->GetFieldNumber();
        const int len = BeerShevaArray[i]->getLength();
        const int width = BeerShevaArray[i]->getWidth();
        const int price = BeerShevaArray[i]->getPricePerHour();

        // Write values to the file
        ofs7 << ID << " " << name << " " << Num << " " << len << " " << width << " " << price << endl;
    }
    for (int i = 0; i < BeerShevaCounter; ++i)
        delete BeerShevaArray[i];
    delete[] BeerShevaArray;

}


void DataBase::printPlayers()
{
    for (int i = 0; i < playerCounter; ++i)
    {
        cout << *playerArray[i];
    }

}
void DataBase::addPlayer(const Player &newPlayer)
{
// Create a new array with increased size
    auto** newArray = new Player*[playerCounter + 1];

    // Copy existing players to the new array
    for (int i = 0; i < playerCounter; ++i)
    {
        newArray[i] = playerArray[i];
    }

    // Add the new player to the end of the array
    newArray[playerCounter] = new Player(newPlayer);

    // Delete the old array
    delete[] playerArray;

    // Update the playerArray pointer
    playerArray = newArray;

    // Increment the playerCounter
    ++playerCounter;
}
void DataBase::removePlayer(const char* playerID)
{
    // Find the index of the player with the given ID
    int index = -1;
    for (int i = 0; i < playerCounter; ++i)
    {
        if (strcmp(playerArray[i]->Get_ID(), playerID) == 0)
        {
            index = i;
            break;
        }
    }

    // If player found, remove from the array
    if (index != -1)
    {
        // Delete the player at the found position
        delete playerArray[index];

        // Shift the remaining players to fill the gap
        for (int i = index; i < playerCounter - 1; ++i)
        {
            playerArray[i] = playerArray[i + 1];
        }

        // Decrement the playerCounter
        --playerCounter;
    }
    else
    {
        std::cerr << "Error: Player with ID " << playerID << " not found." << std::endl;
    }
}

void DataBase::PrintManagers()
{
    for (int i = 0; i < managerCounter; ++i)
    {
        cout << *managerArray[i];
    }

}
void DataBase::AddManager(const Manager& newManager)
{
    // Create a new array with increased size
    auto** newArray = new Manager*[managerCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < managerCounter; ++i)
    {
        newArray[i] = managerArray[i];
    }

    // Add the new manager to the end of the array
    newArray[managerCounter] = new Manager(newManager);

    // Delete the old array
    delete[] managerArray;

    // Update the managerArray pointer
    managerArray = newArray;

    // Increment the managerCounter
    ++managerCounter;
}
void DataBase::RemoveManager(const char* managerID)
{
    // Find the index of the manager with the given ID
    int index = -1;
    for (int i = 0; i < managerCounter; ++i)
    {
        if (strcmp(managerArray[i]->Get_ID(), managerID) == 0)
        {
            index = i;
            break;
        }
    }

    // If manager found, remove from the array
    if (index != -1)
    {
        // Delete the manager at the found position
        delete managerArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < managerCounter - 1; ++i)
        {
            managerArray[i] = managerArray[i + 1];
        }

        // Decrement the managerCounter
        --managerCounter;
    }
    else
    {
        std::cerr << "Error: Manager with ID " << managerID << " not found." << std::endl;
    }
}


void DataBase::printOrder() {
    for (int i = 0; i < orderCounter; ++i)
        cout << *orderArray[i] << endl;
}
void DataBase::addOrder(Reservation * newOrder)
{
    // Create a new array with increased size
    Reservation ** newArray = new Reservation*[orderCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < orderCounter; ++i)
    {
        newArray[i] = orderArray[i];
    }

    // Add the new manager to the end of the array
    newArray[orderCounter] = newOrder;

    // Delete the old array
    delete[] orderArray;

    // Update the managerArray pointer
    orderArray = newArray;

    // Increment the managerCounter
    ++orderCounter;
}
void DataBase::removeOrder(int index)
{
    // Find the index of the manager with the given ID
//    int index = -1;
//    for (int i = 0; i < orderCounter; ++i)
//    {
//        if (strcmp(orderArray[i]->getID(), ID) == 0)
//        {
//            index = i;
//            break;
//        }
//    }

    // If manager found, remove from the array
    if (index != -1)
    {
        // Delete the manager at the found position
        delete orderArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < orderCounter - 1; ++i)
        {
            orderArray[i] = orderArray[i + 1];
        }

        // Decrement the managerCounter
        --orderCounter;
    }
//    else
//    {
//        std::cerr << "Error: Order with the ID " << ID << " not found." << std::endl;
//    }
}


void DataBase::printAshkelonFields() {
    for (int i = 0; i < AshkelonCounter; ++i)
        cout << *AshkelonArray[i] << endl;
}
void DataBase::addAshkelonField(Field * newOrder)
{
    // Create a new array with increased size
    Field ** newArray = new Field*[AshkelonCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < AshkelonCounter; ++i)
    {
        newArray[i] = AshkelonArray[i];
    }

    // Add the new manager to the end of the array
    newArray[AshkelonCounter] = newOrder;

    // Delete the old array
    delete[] AshkelonArray;

    // Update the managerArray pointer
    AshkelonArray = newArray;

    // Increment the managerCounter
    ++AshkelonCounter;
}
void DataBase::removeAshkelonField(int index)
{
    // If manager found, remove from the array
    if (index != -1){
        // Delete the manager at the found position
        delete AshkelonArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < AshkelonCounter - 1; ++i)
            AshkelonArray[i] = AshkelonArray[i + 1];

        // Decrement the managerCounter
        --AshkelonCounter;
    }
}


void DataBase::printAshdodFields() {
    for (int i = 0; i < AshdodCounter; ++i)
        cout << *AshdodArray[i] << endl;
}
void DataBase::addAshdodField(Field * newOrder)
{
    // Create a new array with increased size
    Field ** newArray = new Field*[AshdodCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < AshdodCounter; ++i)
    {
        newArray[i] = AshdodArray[i];
    }

    // Add the new manager to the end of the array
    newArray[AshdodCounter] = newOrder;

    // Delete the old array
    delete[] AshdodArray;

    // Update the managerArray pointer
    AshdodArray = newArray;

    // Increment the managerCounter
    ++AshdodCounter;
}
void DataBase::removeAshdodField(int index)
{
    // If manager found, remove from the array
    if (index != -1){
        // Delete the manager at the found position
        delete AshdodArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < AshdodCounter - 1; ++i)
            AshdodArray[i] = AshdodArray[i + 1];

        // Decrement the managerCounter
        --AshdodCounter;
    }
}


void DataBase::printTelAvivFields() {
    for (int i = 0; i < TelAvivCounter; ++i)
        cout << *TelAvivArray[i] << endl;
}
void DataBase::addTelAvivField(Field * newOrder)
{
    // Create a new array with increased size
    Field ** newArray = new Field*[TelAvivCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < TelAvivCounter; ++i)
    {
        newArray[i] = TelAvivArray[i];
    }

    // Add the new manager to the end of the array
    newArray[TelAvivCounter] = newOrder;

    // Delete the old array
    delete[] TelAvivArray;

    // Update the managerArray pointer
    TelAvivArray = newArray;

    // Increment the managerCounter
    ++TelAvivCounter;
}
void DataBase::removeTelAvivField(int index)
{
    // If manager found, remove from the array
    if (index != -1){
        // Delete the manager at the found position
        delete TelAvivArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < TelAvivCounter - 1; ++i)
            TelAvivArray[i] = TelAvivArray[i + 1];

        // Decrement the managerCounter
        --TelAvivCounter;
    }
}


void DataBase::printBeerShevaFields() {
    for (int i = 0; i < BeerShevaCounter; ++i)
        cout << *BeerShevaArray[i] << endl;
}
void DataBase::addBeerShevaField(Field * newOrder)
{
    // Create a new array with increased size
    Field ** newArray = new Field*[BeerShevaCounter + 1];

    // Copy existing managers to the new array
    for (int i = 0; i < BeerShevaCounter; ++i)
    {
        newArray[i] = BeerShevaArray[i];
    }

    // Add the new manager to the end of the array
    newArray[BeerShevaCounter] = newOrder;

    // Delete the old array
    delete[] BeerShevaArray;

    // Update the managerArray pointer
    BeerShevaArray = newArray;

    // Increment the managerCounter
    ++BeerShevaCounter;
}
void DataBase::removeBeerShevaField(int index)
{
    // If manager found, remove from the array
    if (index != -1){
        // Delete the manager at the found position
        delete AshdodArray[index];

        // Shift the remaining managers to fill the gap
        for (int i = index; i < BeerShevaCounter - 1; ++i)
            BeerShevaArray[i] = BeerShevaArray[i + 1];

        // Decrement the managerCounter
        --BeerShevaCounter;
    }
}