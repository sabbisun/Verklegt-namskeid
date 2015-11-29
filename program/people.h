#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "individual.h"

using namespace std;

class People
{
public:
    People(const string filename);
    People(People& p1);
    People();

    void searchName();
    void searchGender();
    void searchBirth();
    void searchDeath();

    void addIndi(Individual& i1);
    Individual getIndi(const int i) const;
    void swap(const int i, const int j);
    void sortAlpabetFront();
    void sortAlpabetBack();
    void printVector();

    string makeLower(string& temp);

private:
    vector <Individual> person;
    void saveFile(const string filename);
    bool checkIndiOrder(const Individual& i1, const Individual& i2);

};

#endif // PEOPLE_H
