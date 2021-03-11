//Hello World
/* By Daisy Santana */
//iostream used for inputting and outputting
#include <iostream>
using namespace std;


//////////////////////////////////////
//Main is always the first to run
/////////////////////////////////////
int main()
{
    string name;
    string favFood;

    cout << "Please enter your name: " << endl;
    cin >> name;
	cout << "hello, " << name << ", nice to see you, what is your favorite food? \n";
    cin >> favFood;
    cout << "Great! " << favFood << " is one of my favorites too!\n";
    return 0;
}
