#ifndef PEOPLE_H
#define PEOPLE_H

<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
=======
>>>>>>> origin/master
#include "individual.h"

using namespace std;

class People
{
public:
    People(const string filename);
private:
    vector <Individual> person;

};

#endif // PEOPLE_H
