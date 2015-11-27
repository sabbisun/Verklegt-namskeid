#include "people.h"

People::People(){}

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


void People::searchMenu(){
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

void People::searchName(){
    string searchStr = "";
    People temp;
    cout << "Enter a name to search for:" << endl;
    getline(cin, searchStr);

    for(unsigned int i = 0; i < person.size(); i++){
        string tempStr = person[i].getName() + " " + person[i].getName();
        if(true){
            Individual tempInd;
            tempInd = getIndi(i);
            temp.addIndi(tempInd);
        }
    }
}
