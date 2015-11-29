#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Individual
{
private:
    string name, surname;
    char gender; // f/F or m/M
    int birth, death;
    bool alive;
public:
    Individual();
    Individual(string surnam, string nam, char gend, int bir, int dea);
    bool isDead();
    friend ostream& operator << (ostream& outs, Individual& id);
    friend istream& operator >> (istream& ins, Individual& id);
    
    string getName();
    string getSurname()const;
    char getGender();
    int getBirth() const;
    int getDeath() const;
};

#endif // INDIVIDUAL_H
