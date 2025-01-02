//
// Created by Artiom on 28/02/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_BRANCH_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_BRANCH_H
#include "Field.h"


class Branch {
protected:
    char* branchName;
    int sizeFieldArray;
    Field** fieldArray;

public:
    Branch(char *name):fieldArray(nullptr),sizeFieldArray(0){
        this->branchName = new char [strlen(name) + 1];
        strcpy(this->branchName, name);

    }

    ~Branch() {
        delete[] branchName; // Add this line to free the allocated memory for branchName
        for (int i = 0; i < sizeFieldArray; ++i) {
            delete fieldArray[i];
        }
        delete[] fieldArray;
    }
    Field** GetFields(){return fieldArray;}
    int getSizeFieldArray()const{return sizeFieldArray;}
    void printDetails(char* VIP)const;
    void AddField(char*);
    Branch &operator +=(Field* object);
    void removeField(Field* object);
    void saveBranchToFile() const;
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_BRANCH_H
