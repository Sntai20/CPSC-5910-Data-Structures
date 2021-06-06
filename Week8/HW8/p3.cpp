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

/** Prints welcome message. */
void welcome();

/** Prints goodbye message. */
void goodbye();

/** Prints help menu. */
void help();

/** Process the line entered from the user or read from the file. */
bool processLine(string, PatientPriorityQueue &);

/** Adds the patient to the waiting room. */
void addPatientCmd(string, PatientPriorityQueue &);

/** Displays the next patient in the waiting room that will be called. */
void peekNextCmd(PatientPriorityQueue &);

/** Removes a patient from the waiting room and displays the name on the screen. */
void removePatientCmd(PatientPriorityQueue &);

/** Displays the list of patients in the waiting room. */
void showPatientListCmd(PatientPriorityQueue &);

/** Reads a text file with each command on a separate line and executes the
 * lines as if they were typed into the command prompt. */
void execCommandsFromFileCmd(string, PatientPriorityQueue &);

/** Delimits (by space) the string from user or file input. */
string delimitBySpace(string &);

int main(int argc, char** argv) {

    // declare variables
    string line ;

    cout << "You have entered " << argc
         << " arguments:" << endl;
    cout << argv[1] << endl;

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueue priQueue;
	do {
		cout << "\ntriage> ";
		getline(cin, line);
//	} while (processLine(line, priQueue));
    } while (processLine(argv[1], priQueue));


	// goodbye message
	goodbye();
}

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
    else if (cmd == "peek")
        peekNextCmd(priQueue);
    else if (cmd == "next")
        removePatientCmd(priQueue);
    else if (cmd == "list")
        showPatientListCmd(priQueue);
    else if (cmd == "load")
        execCommandsFromFileCmd(line, priQueue);
	else if (cmd == "quit")
		return false;
	else
		cout << "Error: unrecognized command: " << cmd << endl;

	return true;
}
void addPatientCmd(string line, PatientPriorityQueue &priQueue) {
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

void peekNextCmd(PatientPriorityQueue &priQueue)
{
    // TODO: shows next patient to be seen
    cout << "# patients waiting: " << priQueue.size() << endl;
    peekNextCmd(priQueue);
}

void removePatientCmd(PatientPriorityQueue &priQueue)
{
    // TODO: removes and shows next patient to be seen
    cout << "# patients waiting: " << priQueue.size() << endl;
}

void showPatientListCmd(PatientPriorityQueue &priQueue)
{
    cout << "# patients waiting: " << priQueue.size() << endl;
    cout << "  Arrival #   Priority Code   Patient Name\n"
         << "+-----------+---------------+--------------+\n";
    // TODO: shows patient detail in heap order

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



















