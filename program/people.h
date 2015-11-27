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
    People();

    void searchMenu();
    void searchName();
    void addIndi(Individual& i1);
    Individual getIndi(const int i) const;

private:
    vector <Individual> person;
    void saveFile(const string filename);

};

#endif // PEOPLE_H
