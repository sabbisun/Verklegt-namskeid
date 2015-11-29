#include <QCoreApplication>
#include<iostream>
#include "people.h"

const string FILENAME = "people.txt";
void searchMenu();
using namespace std;

int main()
{


    People p1(FILENAME);
    /*
    Individual i1;
    cin >> i1;
    p1.addIndi(i1);

<<<<<<< HEAD
    */
   p1.sortByDeathYear();
   // p1.printVector();



}

void searchMenu(){
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name" << endl
         << "(G) Gender" << endl
        << "(B) Year of Birth" << endl
        << "(D) Year of Death" << endl;
    cout << "Select a letter:";
    cin >> choice;

    switch(choice){
        case 'N':
        break;
        case 'G':
        break;
        case 'B':
        break;
        case 'D':
        break;
    default:;
    }

}
