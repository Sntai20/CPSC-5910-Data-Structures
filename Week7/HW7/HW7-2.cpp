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
 *
 * The sorting method implemented in HW7-2 is merge sort. Merge sort follows divide-and-conquer approach. It divides
 * an array of n elements into two subarrays of n/2 elements each. Then it sort the two subarrays recursively
 * using merge sort. And then these subarrays are merged to produce a single sorted array. The additional memory
 * needed for merge sort is array of size n for merging any of two sorted vectors produced on any step of the
 * algorithm. The first merge it allocates two vectors of n/2 length , then it will be four vectors of n/4 and the
 * given time complexity (average case) is n * log(n).
 *
 */
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;

template <typename T>
void display(vector<T> data);
template <typename ItemType>
void outputFile(vector<ItemType> data);
bool fileExists(string filePath);
template<class T>
void merge(std::vector<T>& v, int p, int q, int r);
template<class T>
void merge_sort(std::vector<T>& v, int p, int r);

int main()
{
    string firstFileName, secondFileName, data, word, dataWord;
    bool isInt = true;

    //Prompt for file names
    cout << "Enter file names with space: ";
    cin >> firstFileName >> secondFileName;

    // File open error check
    if (!fileExists(firstFileName))
    {
        cout << "File not found\n";
        exit(0);
    } else if (!fileExists(secondFileName)) {
        cout << "File not found\n";
        exit(0);
    }

    ifstream firstFileStreamIn(firstFileName);
    ifstream secondFileStreamIn(secondFileName);

    // Check for integer
    firstFileStreamIn >> data;
    vector<int> values;
    vector<string> words;
    int number;

    for (long unsigned int i = 0; i < data.length(); i++)
    {
        if (!isdigit(data[i]))
        {
            isInt = false;
            break;
        }
    }

    // If integer read into a int vector
    if (isInt)
    {
        stringstream ss(data); // To grab the first value.
        ss >> number;
        values.push_back(number);
        while (firstFileStreamIn >> data)
        {
            stringstream ss1(data);
            ss1 >> number;
            values.push_back(number);
        }
        while (secondFileStreamIn >> dataWord)
        {
            stringstream ss2(dataWord);
            ss2 >> word;
            words.push_back(word);
        }
        firstFileStreamIn.close();
        secondFileStreamIn.close();

    }
    // String data
    else
    {
        words.push_back(data);
        while (firstFileStreamIn >> dataWord)
        {
            stringstream ss1(dataWord);
            ss1 >> word;
            words.push_back(word);
        }
        while (secondFileStreamIn >> data)
        {
            stringstream ss2(data);
            ss2 >> number;
            values.push_back(number);
        }

        firstFileStreamIn.close();
        secondFileStreamIn.close();
    }

    // Display before Sort
    cout << "\nValues before Sort:" << endl;
    display(values);
    cout << endl;
    display(words);

    cout << "\nValues after Merge Sort:" << endl;
    int vsz = values.size();
    //int wsz = words.size();
    merge_sort(values, 0, vsz);
    //merge_sort(words, 0, wsz);
    display(values);
    display(words);

    outputFile(values);
    outputFile(words);
    return 0;
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

template <typename ItemType>
void outputFile(vector<ItemType> data)
{
    std::ofstream myfile;
    myfile.open ("output.txt", std::ios::app);

    for (unsigned int i = 0; i < data.size(); i++)
    {
        myfile << data[i] << " ";
    }
    myfile.close();
}

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