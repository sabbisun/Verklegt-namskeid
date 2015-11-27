#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

class Individual
{
private:
    string name, surname;
    char gender; // f/F or m/M
    int birth, death;
    bool alive;
public:
    Individual();
    Individual(string nam, string surnam, char gend, int bir, int dea);
    bool isDead();
    friend ostream& operator << (ostream& outs, Individual& id);
    friend istream& operator >> (istream& ins, Individual& id);
    
    string getName();
    string getSurname();
    char getGender();
    int getBirth();
    int getDeath();
};

#endif // INDIVIDUAL_H
