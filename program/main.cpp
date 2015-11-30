#include <QCoreApplication>
#include <iostream>
#include "people.h"

const string FILENAME = "people.txt";
using namespace std;

bool legalAns(char ans);
//checks if answer fits choices, if false then programs ends
void ask();
//asks what should be done with the list
void menu(char ans, People& list);
//call for changes to the list
void searchMenu(People& p);
//choose what shall be searched for
void sortMenu(People& p);
//choose in what order the list shall be printed

int main(){


    People list(FILENAME);
    cout<<"------------Welcome to the database of famous computer scientists-------------"<<endl;
    cout<<"\t"<<"    In this database you can add, remove, sort and search"<<endl;
    cout<<"\t \t"<<" At this moment we have "<<list.getSize()<<" computer scientists!"<<endl;
    cout<<"------------------------------------Enjoy!------------------------------------"<<endl;
    char choice;
    do {
        ask();
        cin >> choice;
        menu(choice, list);
    } while (legalAns(choice));
}


bool legalAns(char ans) {
    return (ans == 'A' || ans == 'a' || ans == 'B' || ans == 'b'
            || ans == 'C' || ans == 'c' || ans == 'D' || ans == 'd');
}

void ask() {
    cout << "Do you want to: " << endl;
    cout << "(A) Add to list? " << endl;
    cout << "(B) Search list? " << endl;
    cout << "(C) Print list? " << endl; //fyrst spurt um sort svo print
    cout << "(D) Remove from list? " << endl;
}

void menu(char ans, People& list)
{
    switch(ans) {
        case 'a':
        case 'A':   {
                        cin.ignore();
                        Individual id;
                        cin >> id;
                        list.addIndi(id);
                    }
                    break;
        case 'b':
        case 'B':   searchMenu(list);
                    break;
        case 'c':
        case 'C':   {
                        sortMenu(list);
                    }
                    break;
        case 'd':
        case 'D':   list = list.removeIndi(list);
                    break;
        default:;
    }
}


void searchMenu(People& p)
{
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name" << endl
         << "(G) Gender" << endl
         << "(B) Year of Birth" << endl
         << "(D) Year of Death" << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice) {
        case 'n':
        case 'N':   p.searchName();
                    break;
        case 'g':
        case 'G':   p.searchGender();
                    break;
        case 'b':
        case 'B':   p.searchBirth();
                    break;
        case 'd':
        case 'D':   p.searchDeath();
                    break;
        default:;
    }
}

void sortMenu(People& p)
{
    char choice;
    cout << "Print/Sort by: " << endl;
    cout << "(A) Alphabetic order" << endl
         << "(R) Reverse alphabetic order" << endl
         << "(B) Year of Birth" << endl
         << "(D) Year of Death" << endl
         << "(F) Females first, then males" << endl
         << "(M) Males first, then females" << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice) {
        case 'a':
        case 'A':   p.sortAlpabetFront();
                    break;
        case 'r':
        case 'R':   p.sortAlpabetBack();
                    break;
        case 'b':
        case 'B':   p.sortByBirthYear();
                    break;
        case 'd':
        case 'D':   p.sortByDeathYear();
                    break;
        case 'f':
        case 'F':   p.sortByGenderFemales();
                    break;
        case 'm':
        case 'M':   p.sortByGenderMales();
                    break;
        default:;
    }
}
