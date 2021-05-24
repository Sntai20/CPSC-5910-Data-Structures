/*
 * Created by Antonio Santana on 5/24/2021.
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
#include <sstream>

using namespace std;

//Function prototypes
template <typename T>
void insertionSort(vector<T>& data);
template <typename T>
void display(vector<T> data);
bool fileExists(string filePath)
{
    ifstream ifile;
    ifile.open(filePath);
    if(ifile) { return true; }
    else return false;
}

template<class T>
void merge(std::vector<T>& v, int p, int q, int r)
{
    int size1 = q-p+1;
    int size2 = r-q;
    std::vector<T> L(size1);
    std::vector<T> R(size2);

    for(int i = 0; i < size1; i++)
    {
        L[i] = v[p+i];
    }
    for(int j = 0; j < size2; j++)
    {
        R[j]=v[q+j+1];
    }

    int i=0,j=0;
    int k;
    for(k = p; k <= r && i < size1 && j < size2; k++)
    {
        if(L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
    for(i = i; i < size1; ++i)
    {
        v[k] = L[i];
        k++;
    }

    for(j = j; j < size2; j++)
    {
        v[k] = R[j];
        k++;
    }
}

template<class T>
void merge_sort(std::vector<T>& v, int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(v, p, q);
        merge_sort(v, q+1, r);
        merge(v, p, q, r);
    }
}

int main()
{
    string firstFileName, secondFileName,data;
    bool isInt = true;

    //Prompt for file names
    cout << "Enter file names with space: ";
//    cin >> firstFileName >> secondFileName;
    firstFileName = "int.txt";
    secondFileName = "word.txt";

    // File open error check
    if (!fileExists(firstFileName))
    {
        cout << "File not found\n";
        exit(0);
    } else if (!fileExists(secondFileName))
    {
        cout << "File not found\n";
        exit(0);
    }

    ifstream firstFileStreamIn(firstFileName);
    ifstream secondFileStreamIn(secondFileName);

    //Check for integer
    firstFileStreamIn >> data;
    for (long unsigned int i = 0; i < data.length(); i++)
    {
        if (!isdigit(data[i]))
        {
            isInt = false;
            break;
        }
    }

    //If integer read into a int vector
    if (isInt)
    {
        vector<int> values;
        int number;
        stringstream ss(data); // To grab the first value.
        ss >> number;
        values.push_back(number);
        while (firstFileStreamIn >> data)
        {
            stringstream ss1(data);
            ss1 >> number;
            values.push_back(number);
        }
        while (secondFileStreamIn >> data)
        {
            stringstream ss2(data);
            ss2 >> number;
            values.push_back(number);
        }
        firstFileStreamIn.close();
        secondFileStreamIn.close();

        // Display before insertionSort
        cout << "Values before Sort:" << endl;
        display(values);

        // Call insertionSort
//        insertionSort(values);
        // Display after insertionSort
        cout << "\nValues after Merge Sort:" << endl;
        int vsz = values.size();
        merge_sort(values, 0, vsz);
        std::cout << "Entered values vector : ";
        for(int n = 0; n < vsz; n++)
        {
            std::cout << values[n] <<" ";
        }
        display(values);
    }
    //String data
    else
    {
        vector<string> values;
        values.push_back(data);
        while (firstFileStreamIn >> data)
        {
            values.push_back(data);
        }
        while (secondFileStreamIn >> data)
        {
            values.push_back(data);
        }

        firstFileStreamIn.close();
        secondFileStreamIn.close();
        cout << "Values before insertionSort:" << endl;
        display(values);
//        insertionSort(values);
        int stringsz = values.size();
        merge_sort(values, 0, stringsz);
        cout << "\nValues after insertionSort:" << endl;
        display(values);
    }
    return 0;
}

// Using insertion insertionSort O(n)
template <typename ItemType>
void insertionSort(vector<ItemType>& data)
{
    for (unsigned int i = 1; i < data.size(); i++)
    {
        ItemType key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

// Display the data to the console.
template <typename ItemType>
void display(vector<ItemType> data)
{
    for (unsigned int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}