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
    if (id.death == 0){
        outs << "The individual is still alive." << endl;
    }
    else{
        outs << "Year of death: " << id.death << endl;
    }
    return outs;
}

bool operator == (Individual& indi, Individual& indi2){
    if(indi.birth==indi2.birth && indi.death==indi2.death && indi.surname ==indi2.surname && indi.gender==indi2.gender &&indi.name ==indi2.name){
        return true;
    }
    else
        return false;

}

istream& operator >> (istream& ins, Individual& id)
{
    char ans;
    cout << "Surname name: ";
    getline(ins, id.surname);
    cout << "Given name: ";
    getline(ins, id.name);

    do{
        cout << "Gender (m/f): ";
        ins >> id.gender;
        if(id.gender != 'f' && id.gender != 'm')
            cout << "Invalid input!" << endl << "Type again" << endl << endl;

    }while(id.gender != 'f' && id.gender != 'm');

    do{
        ins.clear();
        ins.ignore();
        cout << "Year of birth: ";
        ins >> id.birth;
        if(ins.fail()){
            cout << endl << "Invalid input!" << endl << "Type again" << endl << endl;
        }
    }while(ins.fail());

    cout << "Is the individual alive?(y/n) ";
    cin >> ans;
    if (ans == 'n') {
        do{
            ins.clear();
            ins.ignore();
            cout << "Year of death: ";
            ins >> id.death;
            if(ins.fail()){
                cout << endl << "Invalid input!" << endl << "Type again" << endl << endl;
            }
            while(id.birth>id.death){
                cout<<"Illegal deathyear! Input again: ";
                ins >>id.death;
            }
        }while(ins.fail());

        id.alive = 1;
    }
    else {
        id.death = 0;
        id.alive = 0;
    }
    
    return ins;
}

string Individual::getName() const {
    return name;
}

string Individual::getSurname() const {
    return surname;
}

char Individual::getGender() const {
    return gender;
}

int Individual::getBirth()const {
    return birth;
}

int Individual::getDeath() const {
    return death;
}


