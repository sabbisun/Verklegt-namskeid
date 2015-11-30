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


int People::getSize(){
    int tala;
    tala=person.size();
    return tala;
}

void People::addIndi(Individual& i1)
{
    person.push_back(i1);
    saveFile("people.txt");     //ætti að vera const string?
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

void People::sortByBirthYear()
{
    People result(*this);
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkBirthYearOrder(result.person[j],result.person[i]))
            {
               result.swap(j,i);
            }
        }
    }
   result.printVector();
}

void People::sortByDeathYear()
{
    People result(*this);
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkDeathYearOrder(result.person[j],result.person[i]))
            {
               result.swap(j,i);
            }
        }
    }
    result.printVector();
}

void People::sortByGenderMales()
{
    People r1(*this);
    People male,female;
    for(unsigned int j = 0; j<r1.person.size(); j++) {
        if(r1.getIndi(j).getGender() == 'm')
            male.person.push_back(r1.person[j]);
        else
            female.person.push_back(r1.person[j]);
    }
    cout << "--- Reading males ---" << endl;
    male.sortAlpabetFront();
    cout << "--- Reading females ---" << endl;
    female.sortAlpabetFront();
}

void People::sortByGenderFemales()
{
    People r1(*this);
    People male,female;
    for(unsigned int j = 0; j<r1.person.size(); j++) {
        if(r1.getIndi(j).getGender() == 'm')
            male.person.push_back(r1.person[j]);
        else
            female.person.push_back(r1.person[j]);
    }
    cout << "--- Reading females ---" << endl;
    female.sortAlpabetFront();
    cout << "--- Reading males ---" << endl;
    male.sortAlpabetFront();

}

People::People(People& p1)
{
    for(unsigned int i = 0 ; i < p1.person.size(); i++) {
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

bool People::checkBirthYearOrder(const Individual& i1, const Individual& i2)
{
    return(i1.getBirth()>i2.getBirth());

}

bool People::checkDeathYearOrder(const Individual& i1, const Individual& i2)
{
    return(i1.getDeath()>i2.getDeath());

}

string People::makeLower(string& temp)
{
    //converts string variable temp to all lower letters:
    for (unsigned int i = 0; i < temp.length(); i++) {
        if(isupper(temp[i]))
            temp[i] = tolower(temp[i]);
    }
    return temp;
}

void People::searchName()
{
    bool found = false;
    string tempStr, searchStr = "";
    cin.ignore();   //annars virkar getline ekki
    cout << "Enter a name to search for:" << endl;
    getline(cin, searchStr);
    searchStr = makeLower(searchStr);

    cout << "--- The following people match your search ---" << endl;
    for(unsigned int i = 0; i < person.size(); i++) {
        tempStr = person[i].getName() + " " + person[i].getSurname();
        tempStr = makeLower(tempStr);
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

People People::removeIndi(People& vec)
{
    People removed;
    char ans;
    string name, tempName;
    bool found = false;

    cout << "Do you want to see the list of all people?(y/n) " << endl;
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
        printVector();
    cin.ignore();

    cout << "Enter the exact name of the individual that will be removed: ";
    getline(cin, name);     // input as: name surname

    for (unsigned int i = 0; i < vec.person.size()-1; i++) {
        tempName = vec.person[i].getName() + " " + vec.person[i].getSurname();
        if(tempName != name) {
            removed.person.push_back(vec.person[i]);
            //removed.addIndi(person[i]);
            found = true;
        }
    }
    if (found == false)
        cout << "There is no one named " << name << " on the list." << endl;

    return removed;
}





