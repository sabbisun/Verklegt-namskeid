#include "people.h"

People::People() {}

People::People(const string filename)
{
    ifstream ins;
    ins.open(filename.c_str());
    if(ins.fail())
    {
        cout << "Something went wrong while opening the file" << endl;
        exit(1);
    }
    string first ,last;
    int byear, dyear;
    char gender;
    while(getline(ins,last))
    {

      if(last == "\0")
      {
          getline(ins,last);
      }

      getline(ins,first);
      ins >> gender;
      ins >> byear;
      ins >> dyear;
      Individual i1(last,first,gender,byear,dyear);
      person.push_back(i1);
    }
    ins.close();
}
void People::addIndi(Individual& i1)
{
    person.push_back(i1);
    saveFile("people.txt");
}
void People::saveFile(const string filename)
{
    ofstream outs;
    outs.open(filename.c_str(), ios::app);
    if(outs.fail())
    {
        cout << "Something went wrong with opening the output file" << endl;
        exit(1);
    }
    outs << person[person.size()-1].getSurname() << endl;
    outs << person[person.size()-1].getName() << endl;
    outs << person[person.size()-1].getGender() << endl;
    outs << person[person.size()-1].getBirth() << endl;
    outs << person[person.size()-1].getDeath() <<endl;
    cout << endl;
    outs.close();
}

Individual People::getIndi(const int i) const
{
    return person[i];
}
void People::sortAlpabetFront()
{
     People result(*this);
     for(unsigned int i = 1 ; i < result.person.size(); i++)
     {
         for(unsigned int j = 0; j < result.person.size(); j++)
         {
             if(result.checkIndiOrder(result.person[i],result.person[j]))
             {
                result.swap(j,i);
             }

         }
     }
    result.printVector();
}
void People::sortAlpabetBack()
{
    People result(*this);
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkIndiOrder(result.person[j],result.person[i]))
            {
               result.swap(j,i);
            }

        }
    }
   result.printVector();
}

People::People(People& p1)
{
    for(unsigned int i = 0 ; i < p1.person.size(); i++)
    {
       person.push_back(p1.person[i]);

    }
}
void People::swap(const int i, const int j)
{
    Individual temp = person[i];
    person[i] = person[j];
    person[j] = temp;
}

void People::printVector()
{
     for(unsigned int i = 0; i < person.size(); i++) {
        cout << person[i] << endl;
     }
}

bool People::checkIndiOrder(const Individual& i1, const Individual& i2)
{
    string s1 = i1.getSurname();
    string s2 = i2.getSurname();
    char c1 = tolower(s1[0]);
    char c2 = tolower(s2[0]);
    int t1 = static_cast <int> (c1);
    int t2 = static_cast <int> (c2);
    return(t2>t1);
}

void People::searchMenu(){
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
        case 'N':   searchName();
                    break;
        case 'g':
        case 'G':   searchGender();
                    break;
        case 'b':
        case 'B':   searchBirth();
                    break;
        case 'd':
        case 'D':   searchDeath();
                    break;
        default:;
    }
}

void People::sortMenu()
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
        case 'A':   sortAlpabetFront();
                    break;
        case 'r':
        case 'R':   sortAlpabetBack();
                    break;
        case 'b':
        case 'B':   //
                    break;
        case 'd':
        case 'D':   //
                    break;
        case 'f':
        case 'F':   //
                    break;
        case 'm':
        case 'M':   //
                    break;
        default:;
    }

    printVector();
}


/*void People::searchName(){
    string searchStr = "";
    People temp;
    cout << "Enter a name to search for:" << endl;
    getline(cin, searchStr);
    for(unsigned int i = 0; i < person.size(); i++){
        string tempStr = person[i].getName() + " " + person[i].getName();
        if(tempStr.find(searchStr) != string::npos){
            Individual tempInd;
            tempInd = getIndi(i);
            temp.addIndi(tempInd);
        }
    }
}*/

void People::searchName()
{
    bool found = false;
    string tempStr, searchStr = "";
    cin.ignore();   //annars virkar getline ekki
    cout << "Enter a name to search for:" << endl;
    getline(cin, searchStr);

    cout << "--- The following people match your search ---" << endl;
    for(unsigned int i = 0; i < person.size(); i++) {
        tempStr = person[i].getName() + " " + person[i].getSurname();

        if(tempStr.find(searchStr) != string::npos) {  //if ( . == string::npos) ->not found
            cout << person[i] << endl;
            found = true;
        }
    }
    if (found == false)
        cout << "No one matched your search." << endl;
}

void People::searchGender()
{
    bool found = false;
    char findGender, ansGender;
    cout << "Enter which gender you want to search for (m/f): ";
    cin >> ansGender;
    cout << "--- The following people match your search ---" << endl;
    for (unsigned int i = 0; i < person.size(); i++) {
        findGender = person[i].getGender();
        if (ansGender == findGender) {
            cout << person[i] << endl;
            found = true;
        }
    }
    if (found == false)
        cout << "No one matched your search." << endl;
}

void People::searchBirth()
{
    bool found = false;
    int findYear, ansYear;
    cout << "Enter a birth year: ";
    cin >> ansYear;
    cout << "--- The following people match your search ---" << endl;
    for (unsigned int i = 0; i < person.size(); i++) {
        findYear = person[i].getBirth();
        if (ansYear == findYear) {
            cout << person[i] << endl;
            found = true;
        }
    }
    if (found == false)
        cout << "No one matched your search." << endl;
}

void People::searchDeath()
{
    bool found = false;
    int findYear, ansYear;
    cout << "Enter a death year: ";
    cin >> ansYear;
    cout << "--- The following people match your search ---" << endl;
    for (unsigned int i = 0; i < person.size(); i++) {
        findYear = person[i].getDeath();
        if (ansYear == findYear) {
            cout << person[i] << endl;
            found = true;
        }
    }
    if (found == false)
        cout << "No one matched your search." << endl;
}


