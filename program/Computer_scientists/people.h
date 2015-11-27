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
    void searchMenu();
    //searchName();
    //searchGender();
    //searchBirth();
    //searchDeath();
private:
    vector <Individual> person;

};

#endif // PEOPLE_H
