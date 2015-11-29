#include "individual.h"

Individual::Individual() {
    //empty
}

Individual::Individual(string surnam, string nam, char gend, int bir, int dea) {
    name = nam;
    surname = surnam;
    gender = gend;
    birth = bir;
    death = dea;
}

ostream& operator << (ostream& outs, Individual& id)
{
    outs << "Name: " << id.surname << ", " << id.name << endl;
    outs << "Gender: " << id.gender << endl;
    outs << "Year of birth: " << id.birth << endl;
    if (id.death == 0)
        outs << "The individual is still alive." << endl;
    else
        outs << "Year of death: " << id.death << endl;
    
    return outs;
}

istream& operator >> (istream& ins, Individual& id)
{
    char ans;
    cout << "Surname name: ";
    getline(ins, id.surname);
    cout << "Given name: ";
    getline(ins, id.name);
    cout << "Gender (m/f): ";
    ins >> id.gender;
    cout << "Year of birth: ";
    ins >> id.birth;
    cout << "Is the individual alive?(y/n) ";
    cin >> ans;
    if (ans == 'n') {
        cout << "Year of death: ";
        ins >> id.death;
        id.alive = 1;
    }
    else {
        id.death = 0;
        id.alive = 0;
    }
    
    return ins;
}

bool Individual::isDead()
{
    if (alive == 1) {
        //cout << "The individual is alive." << endl
        return false;
    }
    else {
        //cout << "The individual is dead." << endl
        //<< "Year of death: " << death << endl;
        return true;
    }
}

string Individual::getName() {
    return name;
}

string Individual::getSurname() {
    return surname;
}

char Individual::getGender() {
    return gender;
}

int Individual::getBirth() {
    return birth;
}

int Individual::getDeath() {
    return death;
}

