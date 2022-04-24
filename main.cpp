#include <iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;
const int possibleTries=5;
bool char_in_word(char char_,string &country){
    for(auto a:country)
    {
        if(a==char_)return true;
    }
    return false;
}
void fill_Occurrence(char char_,string &unknown,string &country){
    for(int i=0;i<country.size();i++)
    {
        if(country[i]==char_)
        {
            unknown[i]=char_;
        }
    }
}
int main()
{
    cout << "\n\t\t\t\tWelcome to hangman...Guess a country Name\n";
	cout << "\n\t\t\t\tEach letter is represented by a star.\n";
	cout << "\n\t\t\t\tYou have to type only one letter in one try\n";
	cout << "\n\t\t\t\tYou have " << possibleTries << " tries to try and guess the word.\n";
	cout << "\n\t\t\t\tPress Enter to start\n";
	if(cin.get()=='\n')system("cls");
    string buffer;
    vector<string>Countries_Names;
    ifstream country("contries.txt");
    while(getline(country,buffer))
    {
        string name="";
        for(auto ch:buffer)name+=tolower(ch);
        Countries_Names.push_back(name);
    }
    srand(time(0));
    int numbers_of_countries=Countries_Names.size();
    int randam_country=rand()%numbers_of_countries;
    string unknown(Countries_Names[randam_country].size(),'*');
    string country_=Countries_Names[randam_country];

	cout<<"Country : "<<unknown<<endl;
	int _try_=0;
	while(_try_<possibleTries)
    {
        char char_;
        cin>>char_;
        if(char_in_word(char_,country_))
        {
            fill_Occurrence(char_,unknown,country_);
            cout << endl << "You found a letter! Isn't that exciting! it's " <<unknown<<endl;
        }
        else
        {
            cout << endl << "Whoops! That letter isn't in there!" << endl;
            _try_++;
        }
        if(unknown==country_)
        {
			cout << "Yeah! You got it! ";cout << unknown << endl;
			break;
        }
        cout << "You have " << possibleTries - _try_;
		cout << " guesses left." << endl;
    }
    if(_try_==possibleTries)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The Country was : " << country_ << endl;
    }
    return 0;
}
