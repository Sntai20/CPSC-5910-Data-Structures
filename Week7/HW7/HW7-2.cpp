/*
 * Created by Antonio Santana on 5/21/2021.
 *
 * Problem 2: Write a program that: Prompts the user to enter two filenames where the files both
 * contain either all-integers (one per line) or all-(non-integer)-strings (one per line). Detects
 * whether it is working with integers or strings based on the first line of the first file
 * (i.e. if it's an integer, do integer sorting, otherwise do string sorting). Merges these two
 * files into a single sorted output file called "output.txt".
 *
 * You may not use any C/C++ Standard Library sorting algorithms, but rather supply your own in
 * the source code (which can be based on code in the book or lecture materials). You must use
 * the same function for sorting integers and strings. Hint: Consider a template function.
 *
 * Include a descriptive paragraph (not bullet points, not line-oriented code comments)
 * in a block comment in the source code that explains the runtime complexity of your
 * solution. It must be efficient to get full credit. Your program should be fully contained
 * in a file called HW7-2.cpp and compile with the standard command-line flags.
 */
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

//Function prototypes
template <typename T>
void sort(vector<T>& data);
template <typename T>
void display(vector<T> data);

int main()
{
    string filename1, filename2,data;
    bool isInt = true;
//Prompt for file names
    cout << "Enter file names with space: ";
    cin >> filename1 >> filename2;
    ifstream in1(filename1);
    ifstream in2(filename2);
//File open error check
    if (!in1 || !in2) {
        cout << "File not found\n";
        exit(0);
    }
//Check for integer
    in1 >> data;
    for (int i = 0; i < data.length(); i++)
    {
        if (!isdigit(data[i])) {
            isInt = false;
            break;
        }
    }
//If integer read into a int vector
    if (isInt) {
        vector<int> values;
        values.push_back(stoi(data));
        while (in1 >> data) {
            values.push_back(stoi(data));
        }
        while (in2 >> data) {
            values.push_back(stoi(data));
        }
        in1.close();
        in2.close();
//Display before sort
        cout << "Values before sort:\n";
        display(values);
//Call sort
        sort(values);
//Display after sort
        cout << "\nValues after sort:\n";
        display(values);
    }
//String data
    else {
        vector<string> values;
        values.push_back(data);
        while (in1 >> data) {
            values.push_back(data);
        }
        while (in2 >> data) {
            values.push_back(data);
        }
        in1.close();
        in2.close();
        cout << "Values before sort:\n";
        display(values);
        sort(values);
        cout << "\nValues after sort:\n";
        display(values);
    }
    return 0;
}

/*
* This is a template function
* So passed argument data type not matter
* Sort using insertion sort
* Complexity become O(n)
*/

template <typename T>
void sort(vector<T>& data) {
    for (int i = 1; i < data.size(); i++)
    {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}
/*
* Display passed data
*/
template <typename T>
void display(vector<T> data)
{
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }
}

/*
Output

        Enter file names with space: strfile1.txt strfile2.txt
        Values before sort:
hello
        what
you
        want
hi
        how
are
        you

Values after sort:
are
        hello
hi
        how
want
        what
you
        you

*/
/*
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

bool fileExists(string userInput)
{
    ifstream ifile;
    ifile.open(userInput);
    if(ifile) { return true; }
    else return false;
}


// Function to merge the two halves vector left and vector right of the vector vec.
void merge (vector<string>& vec, vector<string>& left, vector<string>& right) {
    // Create iterators for input vectors
    vector<string>::iterator v = vec.begin();
    vector<string>::iterator l = left.begin();
    vector<string>::iterator r = right.begin();

    while (l != left.end() && r != right.end())
    {
        if (*l <= *r ){
            *v = *l;
            l++;
        }
        else {
            *v = *r;
            r++;
        }
        v++;
    }
    // Copy remaining elements of vector left, if there are any
    while (l != left.end())
    {
        *v = *l;
        l++;
        v++;
    }

    // Copy remaining elements of vector right, if there are any
    while (r != right.end())
    {
        *v = *r;
        r++;
        v++;
    }
}

// Function to merge sort a vector of integers. Accepts a reference to the vector.
void mergeSort (vector<string> &vec)
{
    if (vec.size() == 1) return;
    else {

        // Declare temp vectors
        vector<string> left;
        vector<string> right;

        int mid = (vec.size() + 1) / 2;

        // Copy contents of input vector to temp vectors
        for (int i=0; i < mid; i++){
            left.push_back(vec[i]);
        }

        for (int i = mid; i < (int)vec.size(); i++) {
            right.push_back(vec[i]);
        }

        mergeSort(left);
        mergeSort(right);
        merge(vec, left, right);

    }
}

int main() {
    string userInput;

    // Inform the user if the input was a palindrome
    cout << "Please input a file path to a file containing integers:  ";
    //cin >> userInput;
    userInput = "testints.txt";

    // Prompt the user to enter an integer k
    cout << "Please enter an integer k:  ";

    // Prints the k'th largest integer in the file.
    cout << "HW7 tester" << endl << "============" << endl;

    bool foundException = false;
    try
    {
        // Create a test file
//        srand(7);
//
//        const int RANGE = 1000;
//        const long SIZE = 10000;
//        int* data = new int[SIZE];
//        for (int i = 0; i < SIZE; i++)
//        {
//            data[i] = rand() % RANGE;
//        }
//
//        std::ofstream myfile;
//        myfile.open ("testints.txt");
//        for (int i = 0; i < SIZE; i++)
//        {
//            myfile << data[i] << endl;
//        }
//        myfile.close();

        string inputFilePath;
        if (fileExists(userInput) && userInput.length() >= 1)
        {
            inputFilePath = userInput;
            vector<string> stringData;
            vector<int> numbers;
            ifstream inputFile;
            string data;
            inputFile.open(inputFilePath);

//            int number = 0;
//            while(inputFile >> number)
//            {
//                numbers.push_back(number);
//            }
            stringstream ss;


//             Running loop till the end of the stream
            string temp;
            int found;

            while(inputFile >> data)
            {
                 Storing the whole string into string stream
                ss << data;
//                 extracting word by word from stream
                ss >> temp;

//                 Checking the given word is integer or not
                if (stringstream(data) >> found)
                {
                    numbers.push_back(found);
                }

                if (data.length() >= 1)
                {
                    for (long unsigned int i = 0; i < data.length(); i++)
                    {
                        char c = tolower(data[i]);
                        if (isalpha(c))
                        {
                            stringData.push_back(data);
                        }
                    }
                }

//                 To save from space at the end of string
                temp = "";
            }
            inputFile.close();

            mergeSort(stringData);
//            mergeSort(numbers);
            for (auto sD :  stringData)
            {
                cout << sD << " ";

            }
            cout << endl;
            for (auto num :  numbers)
            {
                cout << num << " ";
            }
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

    return 0;
}




//template<typename ItemType>
//list<int> preProcess(ItemType &inputFilePath)
//{
//    ifstream inputFile;
//    int number = 0;
//    inputFile.open(inputFilePath);
//    list<int> numbers;
//
//    while(inputFile >> number)
//    {
//        numbers.push_back(number);
//    }
//
//    inputFile.close();
//    return numbers;
//}
*/