//
// Created by segev on 2/28/2024.
//

#include "MainProgram.h"
#define NumberOfColl 9

MainProgram::MainProgram()
{
    int choice;
    do {
        std::cout << "Hello ! Welcome to Sami Sports Field Rental.\n"
                     "If you are an existing member in the system press 1. \n"
                     "for New member press 2.\n";
        std::cin >> choice;

        if (choice != 1 && choice != 2)
            std::cout << "The selection is not supported by the system. Please select again.\n";

    } while (choice != 1 && choice != 2);

    switch (choice)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            do {
                std::cout << "Glad you decided to join us!\n"
                             "To register as a new player press 1\n"
                             "To register as a new manager press 2\n";
                std::cin  >> choice;

                if (choice != 1 && choice != 2)
                    std::cout << "The selection is not supported by the system. Please select again.\n";

            } while (choice != 1 && choice != 2);

            switch (choice)
            {
                case 1:
                {
                    std::cout << "Welcome !\n"
                                 "In order to complete your registration as a new member in our system,\n"
                                 "we need some additional details from you.\n";
                    Player player;
                    addPlayer(player);
                    std::cout << "Thank you " << player.Get_First_Name() << " " << player.Get_Last_Name()
                              << " You are now an existing customer in our system.\n"
                                 " You can now log in.\n";
                    choice = 2;
                    break;
                }
                case 2:
                {
                    break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
}













void MainProgram::addPlayer(Player playerToAdd)
{
    char*** tempMatrix = new char**[counter + 1];

    for (int i = 0; i < counter; ++i)
    {
        tempMatrix[i] = new char*[NumberOfColl];

        for (int j = 0; j < NumberOfColl; ++j)
        {
            tempMatrix[i][j] = new char[strlen(matrix[i][j]) + 1];
            strcpy(tempMatrix[i][j], matrix[i][j]);
        }
    }

    tempMatrix[counter] = new char*[NumberOfColl];

    char* id = playerToAdd.Get_ID();
    char* firstName = playerToAdd.Get_First_Name();
    char* lastName = playerToAdd.Get_Last_Name();
    char* birthday = playerToAdd.Get_Bithday();
    char* phone = playerToAdd.Get_Phone();
    char* username = playerToAdd.Get_Username();
    char* password = playerToAdd.Get_Password();
    char* address = playerToAdd.Get_Address();
    char* vip = playerToAdd.Get_VIp();
    char* gender = playerToAdd.Get_Gender();

    tempMatrix[counter][0] = new char[strlen(id) + 1];
    strcpy(tempMatrix[counter][0], id);

    tempMatrix[counter][1] = new char[strlen(firstName) + 1];
    strcpy(tempMatrix[counter][1], firstName);

    tempMatrix[counter][2] = new char[strlen(lastName) + 1];
    strcpy(tempMatrix[counter][2], lastName);

    tempMatrix[counter][3] = new char[strlen(birthday) + 1];
    strcpy(tempMatrix[counter][3], birthday);

    tempMatrix[counter][4] = new char[strlen(phone) + 1];
    strcpy(tempMatrix[counter][4], phone);

    tempMatrix[counter][5] = new char[strlen(username) + 1];
    strcpy(tempMatrix[counter][5], username);

    tempMatrix[counter][6] = new char[strlen(password) + 1];
    strcpy(tempMatrix[counter][6], password);

    tempMatrix[counter][7] = new char[strlen(address) + 1];
    strcpy(tempMatrix[counter][7], address);

    tempMatrix[counter][8] = new char[strlen(vip) + 1];
    strcpy(tempMatrix[counter][8], vip);

    tempMatrix[counter][9] = new char[strlen(gender) + 1];
    strcpy(tempMatrix[counter][9], gender);

    // Free the old matrix memory
    for (int i = 0; i < counter; ++i) {
        for (int j = 0; j < NumberOfColl; ++j) {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;

    // Assign the new matrix to matrix
    counter++;
    matrix = tempMatrix;

    for (int i = 0; i < counter + 1; ++i)
    {
        for (int j = 0; j < NumberOfColl; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


}
