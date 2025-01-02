/*
 * Group Members
Artiom Bondar - 332692730
Bar Shira swisa - 211631551
Gal Warsulker - 206493173
Osher madar - 212998751
Segev Isaac - 207938085

 */


#include <fstream>
#include "Field.h"

Field::Field(char* nameOfField, char* ID, int FieldNum, int length, int width, int pricePerHour)
{
    this->nameOfField = new char[strlen(nameOfField)+1];
    strcpy(this->nameOfField,nameOfField);

    this->Manager_ID = new char[strlen(ID) + 1];
    strcpy(this->Manager_ID, ID);

    this->FieldNumber = FieldNum;

    this->width=width;
    this->length=length;
    this->pricePerHour=pricePerHour;
    for (int i = 0; i < 15; ++i) {
        isHourReserved[i] = false;
    }
    this->num_Reservations = 0;
    this->Reservations = nullptr;
}


Field::Field(const Field &other) {
    nameOfField = new char[strlen(other.nameOfField) + 1];
    strcpy(nameOfField, other.nameOfField);

    Manager_ID = new char[strlen(other.Manager_ID) + 1];
    strcpy(Manager_ID, other.Manager_ID);

    FieldNumber = other.FieldNumber;
    width = other.width;
    length = other.length;
    pricePerHour = other.pricePerHour;
}


void Field::printDetails(char* VIP) {
    cout << "Field Name: " << nameOfField << endl;
    cout << "Type: " << FieldNumber << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    if (strcmp(VIP, "No") == 0)
        cout << "Price per hour is: " << pricePerHour << endl;
    else
        cout << "Price per hour is: " << pricePerHour * 0.85 << endl;
}


void Field::markAsReserved(int hour, char* ID, char* rentEquipment ,char * Date, char* location, char* type ,int num)
{
    // Assuming hour is a single character representing the hour (e.g., '8', '9', '10', etc.)
    int time = hour;

    // Check if the hour is within valid range
    if (time >= 8 && time <= 22) {
        isHourReserved[time - 8] = true;
        Reservation ** temp = new Reservation * [this->num_Reservations + 1];
        for (int i = 0; i < this->num_Reservations; ++i) {
            temp[i] = this->Reservations[i];
        }
        temp[num_Reservations] = new Reservation(hour, ID, rentEquipment, Date, location, type, num);
        for (int i = 0; i < num_Reservations; ++i) {
            delete Reservations[i];
        }
        delete [] Reservations;
        this->Reservations = temp;
    }
}




void Field::displaySchedule(const bool *hours, char*& date)
{
    cout << "Schedule for " << nameOfField << " on " << date << ":" << endl;
    cout << "+--------------------------------+" << endl;
    cout << "| Hour          | Availability   |" << endl;
    cout << "+--------------------------------+" << endl;

    for (int hour = 6; hour <= 21; ++hour) {
        cout << "| " << setw(2) << hour << ":00 - " << setw(2) << hour + 1 << ":00 | ";

        // Check if the hour is within the valid range
        if (!hours[hour - 6]) {
            cout << "Available      |" << endl;
        } else {
            cout << "Reserved       |" << endl;
        }
    }

    cout << "+--------------------------------+" << endl;
}





bool Field::isAvailable(int hour) const
{
    // Check if the hour is within valid range
    if (hour < 6 || hour > 21)
    {
        return false;
    }

    // Check if the hour is available
    return isHourReserved[hour - 6] == false;
}


bool Field::reserveField(int hour, char* ID, char* rentEquipment ,char * Date, char* location, char* type, int num) {
    // Convert the character hour to an integer
    int time = hour;

    // Check if the hour is within valid range
    if (time < 8 || time > 22) {
        cout << "Invalid hour for reservation." << endl;
        return false;
    }

    // Check if the hour is available
    if (!isAvailable(time)) {
        cout << "Field is already reserved at " << time << ":00." << std::endl;
        return false;
    }

    // Make the reservation
    markAsReserved(hour, ID, rentEquipment, Date, location, type, num);

    // Update the schedule file
    // writeScheduleToFile();

    cout << "Reservation successful for " << nameOfField << " at " << time << ":00." << std::endl;
    return true;
}


//void Field::showPlayerOrderHistory(const string& playerId) const
//{
//    const std::string FILE_PATH = "C:\\Users\\Artiom\\CLionProjects\\FieldsProject\\schedule list";
//    std::ifstream inputFile(FILE_PATH);
//    if (!inputFile.is_open()) {
//        std::cout << "Error opening schedule file." << std::endl;
//        return;
//    }
//
//    string line;
//    while (getline(inputFile, line)) {
//        // Check if the line contains the player's ID
//        if (line.find(playerId) != string::npos) {
//            cout << line << endl;
//        }
//    }
//    inputFile.close();
//}


//void Field::cancelOrderById(const string& idToCancel)
//{
//    const string FILE_PATH = "C:\\Users\\Artiom\\CLionProjects\\FieldsProject\\schedule list";
//    ifstream inputFile(FILE_PATH);
//    if (!inputFile.is_open()) {
//        cout << "Error opening schedule file." << endl;
//        return;
//    }
//
//    // Read the existing content into memory
//    string fileContent((istreambuf_iterator<char>(inputFile)),istreambuf_iterator<char>());
//
//    // Find the position of the reservation with the specified ID
//    size_t idPosition = fileContent.find(idToCancel);
//    if (idPosition == string::npos) {
//        cout << "Reservation with ID " << idToCancel << " not found." << endl;
//        return;
//    }
//
//    // Find the start of the line containing the reservation
//    size_t lineStart = fileContent.rfind('\n', idPosition) + 1;
//
//    // Find the end of the line containing the reservation
//    size_t lineEnd = fileContent.find('\n', idPosition);
//
//    // Erase the line containing the reservation
//    fileContent.erase(lineStart, lineEnd - lineStart + 1);
//
//    // Write the modified content back to the file
//    ofstream outputFile(FILE_PATH);
//    if (!outputFile.is_open()) {
//        cout << "Error opening schedule file for writing." << endl;
//        return;
//    }
//
//    outputFile << fileContent;
//    cout << "Order with ID " << idToCancel << " has been canceled." << endl;
//
//    inputFile.close();
//    outputFile.close();
//}



void Field::displayScheduleAtHour(int hour)  {
    if (hour < 8 || hour > 22) {
        cout << "Invalid hour. Please provide an hour between 8 and 22." << endl;
        return;
    }

    cout << "Schedule for " << nameOfField << " at " << hour << ":00:" << endl;
    cout << "+---------------------------------------------------------------------------+" << endl;
    cout << "| Hour          | Availability   | ID              | Equipment Rented       |" << endl;
    cout << "+---------------------------------------------------------------------------+" << endl;

    // Check if the hour is within valid range
    if (isAvailable(hour)) {
        cout << "| " << setw(2) << hour << ":00 - " << setw(2) << hour + 1 << ":00 | ";
        cout << "Available      |                 |                        |" << endl;
    } else {
        cout << "| " << setw(2) << hour << ":00 - " << setw(2) << hour + 1 << ":00 | ";
        cout << "Reserved       | " << setw(16) << left << "Reservations[hour - 8].getID()" << "| " << setw(23) << left << "Reservations[hour - 8].getEquipmentRented()" << "|" << endl;
    }

    cout << "+---------------------------------------------------------------------------+" << endl;
}
