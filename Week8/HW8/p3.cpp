/*
 * Created by Antonio Santana on 6/8/2021
 * p3.cpp
 */
// TODO: add functional documentation (and inline comments, as necessary)

#include "PatientPriorityQueue.h"
//#include "Patient.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void welcome();
// Prints welcome message.

void goodbye();
// Prints goodbye message.

void help();
// Prints help menu.

bool processLine(string, PatientPriorityQueue &);
//bool processLine(string);
// Process the line entered from the user or read from the file.

void addPatientCmd(string, PatientPriorityQueue &);
//void addPatientCmd(string line);
// Adds the patient to the waiting room.

void execCommandsFromFileCmd(string, PatientPriorityQueue &);
//void execCommandsFromFileCmd(string);
// Reads a text file with each command on a separate line and executes the
// lines as if they were typed into the command prompt.

string delimitBySpace(string &);
// Delimits (by space) the string from user or file input.

//void PatientPriorityQueue::enqueue(Patient &newEntry) {
//    patientsVector.push_back(newEntry);
//}

PatientPriorityQueue::PatientPriorityQueue() = default;

int main(int argc, char** argv) {

    // declare variables
    string line ;

    cout << "You have entered " << argc
         << " arguments:" << "\n";

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueue priQueue;
	do {
		cout << "\ntriage> ";
		getline(cin, line);
//	} while (processLine(line, priQueue));
//    } while (processLine(argv[1]));
    } while (processLine(argv[1], priQueue));

	// goodbye message
	goodbye();
}
//bool processLine(string line) {
bool processLine(string line, PatientPriorityQueue &priQueue) {
	// get command
	string cmd = delimitBySpace(line);
	if (cmd.length() == 0) {
		cout << "Error: no command given.";
		return false;
	}
	
	// process user input
	if (cmd == "help")
		help();
	else if (cmd == "add")
		addPatientCmd(line, priQueue);
    else if (cmd == "load")
        execCommandsFromFileCmd(line, priQueue);
	else if (cmd == "quit")
		return false;
	else
		cout << "Error: unrecognized command: " << cmd << endl;

	return true;
}
void addPatientCmd(string line, PatientPriorityQueue &priQueue) {
//void addPatientCmd(string line) {
	string priority, name, arrivalOrder;
	int priorityLevel;

	// get priority and name
	priority = delimitBySpace(line);
	if (priority.length() == 0) {
		cout << "Error: no priority code given.\n";
		return;
	}
	name = line;
	if (name.length() == 0) {
		cout << "Error: no patient name given.\n";
		return;
	}

	// TODO: add logic to remove leading/trailing spaces
	// TODO: validate priority is between 1 and 4
	if (priority == "immediate") priorityLevel = 1;
    if (priority == "emergency") priorityLevel = 2;
    if (priority == "urgent") priorityLevel = 3;
    if (priority == "minimal") priorityLevel = 4;

	// TODO: add patient
    Patient newPatient(name, priority, arrivalOrder);
	priQueue.enqueue(newPatient);

    // Added for testing
    arrivalOrder = "0";
    cout << "\nArrivalOrder: " << arrivalOrder <<
         " PriorityCode: " << priority << " Name: " << name <<
         " priorityLevel: " << priorityLevel << endl;
}

void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue)
{
	ifstream infile;
	string line;

	// open and read from file
	infile.open(filename);
	if (infile) {
		while (getline(infile, line))
		{
			cout << "\ntriage> " << line;
			processLine(line, priQueue);
		} 
	} else {
		cout << "Error: could not open file.\n";
	}
	// close file
	infile.close();
}

string delimitBySpace(string &s)
{
	unsigned long pos = 0;
	char delimiter = ' ';
	string result = ""; 

	pos = s.find(delimiter);
	if (pos != string::npos) {
		result = s.substr(0, pos);
		s.erase(0, pos + 1);
	}
	return result;
}

void welcome()
{
	cout << "Welcome function: The following is a section of the console window: " << endl;
}

void goodbye()
{
	// TODO
    cout << "// TODO goodbye function." << endl;
}	

void help()
{
	cout << "add <priority-code> <patient-name>\n"
<< "            Adds the patient to the triage system.\n"
<< "            <priority-code> must be one of the 4 accepted priority codes:\n"
<< "                1. immediate 2. emergency 3. urgent 4. minimal\n"
<< "            <patient-name>: patient's full legal name (may contain spaces)\n"
<< "next        Announces the patient to be seen next. Takes into account the\n"
<< "            type of emergency and the patient's arrival order.\n"
<< "peek        Displays the patient that is next in line, but keeps in queue\n"
<< "list        Displays the list of all patients that are still waiting\n"
<< "            in the order that they have arrived.\n"
<< "load <file> Reads the file and executes the command on each line\n"
<< "help        Displays this menu\n"
<< "quit        Exits the program\n";
}

bool PatientPriorityQueue::isEmpty() {
    return patientsVector.size() == 0 ;
}

void PatientPriorityQueue::enqueue(Patient &newEntry) {
    patientsVector.push_back(newEntry);
    // TODO Return a bool instead.
}

bool PatientPriorityQueue::dequeue() {
    patientsVector.back();
    // TODO Remove the last element and resize.
    return true;
}




















