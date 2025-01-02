//
// Created by Artiom on 28/02/2024.
//

#include <fstream>
#include "Branch.h"
Branch& Branch::operator+=(Field* object) {
    Field** addFieldArr = new Field*[sizeFieldArray + 1];
    for (int i = 0; i < sizeFieldArray; ++i) {
        addFieldArr[i] = fieldArray[i];
    }
    addFieldArr[sizeFieldArray] = object;
    delete[] fieldArray;
    fieldArray = addFieldArr;
    sizeFieldArray++;
    return *this;
}


void Branch::removeField(Field* object) {
    if (sizeFieldArray == 0)
        return;

    bool found = false;
    for (int i = 0; i < sizeFieldArray; ++i) {
        if (fieldArray[i] == object) {
            found = true;
            break;
        }
    }
    if (!found) {
        return;
    }
    Field** NewField = new Field*[sizeFieldArray - 1];
    int j = 0;
    for (int i = 0; i < sizeFieldArray; ++i) {
        if (fieldArray[i] != object) {
            NewField[j] = fieldArray[i];
            j++;
        } else {
            delete fieldArray[i]; // Delete the object
        }
    }
    delete[] fieldArray;
    fieldArray = NewField;
    sizeFieldArray--;
}


void Branch::AddField(char *str) {
    Field **temp = new Field*[sizeFieldArray + 1];

    for (int i = 0; i < sizeFieldArray; ++i) {
        temp[i] = new Field(*fieldArray[i]);
        delete fieldArray[i];  // Delete the old field
    }

    // Add a new field based on the provided type
    if (strcmp(str, "Tennis") == 0)
        temp[sizeFieldArray] = new Field("Tennis", "206493173", 1, 50, 50, 100);
    else if (strcmp(str, "Basketball") == 0)
        temp[sizeFieldArray] = new Field("Basketball", "206493173" ,1,  70, 50, 120);
    else if (strcmp(str, "Football") == 0)
        temp[sizeFieldArray] = new Field("Football", "206493173",1, 100, 50, 200);
    else if (strcmp(str, "Baseball") == 0)
        temp[sizeFieldArray] = new Field("Baseball", "206493173",1, 150, 150, 200);
    else {
        cout << "Invalid field type." << endl;
        return;
    }

    delete[] fieldArray;
    fieldArray = temp;
    ++sizeFieldArray;
}

void Branch::printDetails(char* VIP)const
{


    cout << "Branch Name: " << branchName << endl;
    for (int i = 0; i < sizeFieldArray; ++i)
    {
        fieldArray[i]->printDetails(VIP);
        cout<<endl;
    }
    cout<<endl;
}

//void Branch::saveBranchToFile() const {
//    const string FILE_PATH = "C:\\Users\\user\\Desktop\\FieldsProject\\branches";
//    ofstream outFile(FILE_PATH, ios::app);
//
//    if (!outFile.is_open()) {
//        cerr << "Error opening file: " << FILE_PATH << endl;
//        return;
//    }
//
//    outFile << "Branch Name: " << branchName << endl;
//
//    for (int i = 0; i < sizeFieldArray; ++i) {
//        outFile << "Field Name: " << fieldArray[i]->GetName() << endl;
//    }
//
//    outFile << endl;
//
//    outFile.close();
//}