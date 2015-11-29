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
<<<<<<< HEAD
    People(People& p1);
    //void searchMenu();
=======
    People();

    void searchMenu();
    void searchName();
>>>>>>> 1734bc8766a34f6e623e13f3d0fbda2ef47773e8
    void addIndi(Individual& i1);
    Individual getIndi(const int i) const;
    void swap(const int i, const int j);
    void sortAlpabetFront();
    void printVector();

    void searchGender();
    void searchBirth();
    void searchDeath();
private:
    vector <Individual> person;
    void saveFile(const string filename);
    bool checkIndiOrder(const Individual& i1, const Individual& i2);

};

#endif // PEOPLE_H
