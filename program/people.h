#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "individual.h"
const string FILENAME = "people.txt";

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
    void searchMenu();
    void addIndi(Individual& i1);
    void swap(const int i, const int j);
    void sortAlpabetFront();
    void sortAlpabetBack();
    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGender();
    void printVector();
    int getSize();
    friend ostream& operator << (ostream& outs, People& p1);
    Individual getIndi(const int i) const;
    People removeIndi();

private:
    vector <Individual> person;
    void saveFile(const string filename);
    bool checkIndiOrder(const Individual& i1, const Individual& i2);
    bool checkBirthYearOrder(const Individual& i1, const Individual& i2);
    bool checkDeathYearOrder(const Individual& i1, const Individual& i2);
    string makeLower(string& temp);
    //converts string variable temp to all lower letters:
};

#endif // PEOPLE_H
