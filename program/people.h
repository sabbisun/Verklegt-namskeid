#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
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
    void searchMenu();
    void addIndi(Individual& i1);
    Individual getIndi(const int i) const;
    void swap(const int i, const int j);
    void sortAlpabetFront();
    void sortAlpabetBack();
    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGenderMales();
    void sortByGenderFemales();
    void printVector();

private:
    vector <Individual> person;
    void saveFile(const string filename);
    bool checkIndiOrder(const Individual& i1, const Individual& i2);
    bool checkBirthYearOrder(const Individual& i1, const Individual& i2);
    bool checkDeathYearOrder(const Individual& i1, const Individual& i2);
    string makeLower(string& temp);

};

#endif // PEOPLE_H
