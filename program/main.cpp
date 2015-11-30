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

int main()
{

    People list(FILENAME);
    char choice;
    do {
        ask();
        cin >> choice;
        menu(choice, list);
    } while (legalAns(choice));
}


bool legalAns(char ans) {
    return (ans == 'A' || ans == 'a' || ans == 'S' || ans == 's'
            || ans == 'P' || ans == 'p' || ans == 'R' || ans == 'r');
}

void ask() {
    cout << "Do you want to: " << endl;
    cout << "(A) Add to list? " << endl;
    cout << "(S) Search list? " << endl;
    cout << "(P) Print list? " << endl; //fyrst spurt um sort svo print
    cout << "(R) Remove from list? " << endl;
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
        case 's':
        case 'S':   searchMenu(list);
                    break;
        case 'p':
        case 'P':   {
                        sortMenu(list);
                    }
                    break;
        case 'r':
        case 'R':   list = list.removeIndi(list);
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
         << "(G) Gender" << endl;
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
        case 'g':
        case 'G':   p.sortByGender();
                    break;
        default:;
    }
}
