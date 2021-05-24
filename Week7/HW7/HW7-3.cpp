/*
 * Created by Antonio Santana on 5/21/2021.
 *
 * Problem 3: Write a program that: Prompts the user to enter an integer n, Creates an array of
 * random integers of size n where all values are between 1 and 1000 inclusive. Sort this array
 * in O(n) time. Hint: Research "sort in linear time" or "sort in O(n) time" on the Internet.
 * Print the sorted array to the console. Your program should be fully contained in a file
 * called HW7-3.cpp and compile with the standard command-line flags.
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //declaring variable n
    int n;
    cout<<"Enter an integer n: ";
    //taking the user input n
    cin>>n;
    //declaring an array of size n+1
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        //Generating random integers in between 1 and 1000 and storing it inside arr[i]
        arr[i]=(rand()%1000)+1;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    //Initializing an array brr[] of size n+1 and an array of size 1001 which is crr[]
    int brr[n+1],crr[1001]={0};
    for(int i=1;i<=n;i++)
    {

        crr[arr[i]]+=1;
    }

    //Now crr[] array's each block contains the number of elements which are equal to its each index
    for(int i=1;i<=1000;i++)
    {
        crr[i]=crr[i]+crr[i-1];
    }
    //now crr[] array's each block contains number of elements which are less than or equal to each index
    for(int i=1;i<=n;i++)
    {
        //In the following line we are actually storing the element at index i of arr[]
        // at index crr[arr[i]] of brr[] array because we know that crr[arr[i]]
        //contains number of elements less than or equal to arr[i]
        brr[crr[arr[i]]]=arr[i];
        //At the same time we are decrementing crr[arr[i]] by 1 because we have
        //alreday placed arr[i] in brr[] array in the perfect position
        crr[arr[i]]=crr[arr[i]]-1;
    }
    //printing the brr[] array which contains the sorted elements of arr[] array in increasing order
    for(int i=1;i<=n;i++)
    {
        cout<<brr[i]<<" ";
    }

    return 0;
}

/*
Explanation:>

I have chosen counting-sort algorithm because it's the best choice as it operates best on an array of size n whose elements are in the range

of 1 to k.It's complexity is roughly O(n).It is also a stable algorithm.Here the given range is 1 to 1000.so k=1000

Now ley us see the code working to calculate the time complexity of the algorithm .There are basically 2 types of for loops one is running from

1 to n and another is running from 1 to 1000.

So,overall time complexity is O(n+1000) ≃ O(n)

Output:>

Enter an integer n: 15 42 468 335 501 170 725 479 359 963 465 706 146 282 828 962 42 146 170 282 335 359 465 468 479 501 706
*/


/*
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <list>

using namespace std;

void hW7Tester();
bool fileExists(string userInput);
list<string> preProcess(string &inputFilePath);

int main() {
    cout << "HW7 tester" << std::endl << "============" << std::endl;
    hW7Tester();

    return 0;
}

bool fileExists(string userInput)
{
    ifstream ifile;
    ifile.open(userInput);
    if(ifile) { return true; }
    else return false;
}

list<string> preProcess(string &inputFilePath)
{
    string line;
    ifstream inputFile;
    list<string> wordsList;
    list<string>::iterator myPosition = wordsList.begin();

    inputFile.open(inputFilePath);    // watch for the working directory when you run the project
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            string word;
            if (line.length() >= 1){
                for (long unsigned int i = 0; i < line.length(); i++)
                {
                    char c = tolower(line[i]);
                    if (isalpha(c) || isalnum(c))  word += c;
                }
                wordsList.insert(myPosition, word);
            }
        }
    }
    inputFile.close();
    return wordsList;
}

void hW7Tester() {
    bool foundException = false;
    try
    {
        string userInput = "int.txt";
        string inputFilePath;

        // Inform the user if the input was a palindrome
        cout << "Please input a file path to a file containing integers:  ";
        cin >> userInput;

        if (fileExists(userInput) && userInput.length() >= 1)
        {
            inputFilePath = userInput;
            list<string> wordsList = preProcess(inputFilePath);
            wordsList.sort();
            for (auto word : wordsList)
            {
                cout << word << endl;
            }
            return;
        }
    }
    catch (invalid_argument& e)
    {
        foundException = true;
    }
    if (!foundException)
    {
        cerr << "\nDid not catch an invalid input" << endl;
    }

}

*/

/*
 * vector<int>* numbers;
        if (!inFile) {
            throw std::runtime_error("invalid input!");
        }
        cout << "** TEST INSERT**" << endl << "Inserting in this order: ";
        string line;

        vector<int>::iterator myPosition = numbers->begin();
        while (getline(inFile, line)) {
            stringstream ss(line);
            int n;
            ss >> n;
            cout << n << " ";
            numbers->insert(myPosition, n);
        }

        cout << endl;
        auto start = std::chrono::high_resolution_clock::now();

//        mergeSort(numbers, 0, SIZE - 1);
        auto stop = std::chrono::high_resolution_clock::now();

        for (auto number : *numbers)
        {
            cout << number << endl;
        }

 */