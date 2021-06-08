/*
 * Created by Antonio Santana on 6/8/2021
 * p3.cpp
 */

#include "PatientPriorityQueue.h"
#include "Patient.h"

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

/** Removes a patient from the waiting room and displays the _name on the screen. */
void removePatientCmd(PatientPriorityQueue &);

/** Displays the list of _patientsVector in the waiting room. */
void showPatientListCmd(PatientPriorityQueue &);

/** Reads a text file with each command on a separate line and executes the
 * lines as if they were typed into the command prompt. */
void execCommandsFromFileCmd(string, PatientPriorityQueue &);

/** Delimits (by space) the string from user or file input. */
string delimitBySpace(string &);

int main() {
    // declare variables
    string line ;

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueue priQueue;
	do {
		cout << "\ntriage> ";
		getline(cin, line);
	} while (processLine(line, priQueue));

	// goodbye message
	goodbye();
}

bool processLine(string line, PatientPriorityQueue &priQueue)
{
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
    string priority, name;

    // get priority and _name
    priority = delimitBySpace(line);
    if (priority.length() == 0) {
        cout << "Error: no priority code given.\n";
        return;
    }
    name = line;
    if (name.length() == 0) {
        cout << "Error: no patient _name given.\n";
        return;
    }
    if (priority == "emergency" || priority == "urgent" ||
        priority == "immediate" || priority == "minimal")
    {
        Patient newPatient(name, priority, ( priQueue.size() - 1));
        priQueue.add(newPatient);
    }
    else {
        cout<<"Error: invalid priority code given. \n";
    }
}

void peekNextCmd(PatientPriorityQueue &priQueue)
{
    cout << "# _patientsVector waiting: " << priQueue.size() << endl;
//    peekNextCmd(priQueue);
    if (priQueue.size() > 0) {
        cout<<"The patient in line is: " + priQueue.peek().getName() + "\n";
    }
    else{
        cout<< "Nobody is in the waiting room.\n";
    }
}

void removePatientCmd(PatientPriorityQueue &priQueue)
{
    if (priQueue.size() > 0)
    {
        cout<<"This patient will now be seen: "+ priQueue.remove().getName() +
              "\n";
    }
    else{
        cout<< "Nobody is in the waiting room.\n";
    }
}

void showPatientListCmd(PatientPriorityQueue &priQueue)
{
    cout << "# _patientsVector waiting: " << priQueue.size() << endl;
    cout << "  Arrival #   Priority Code   Patient Name\n"
         << "+-----------+---------------+--------------+\n";
    cout << priQueue.to_string();
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

/*
 * Changing the unsigned pos to unsigned long pos causes an issue when entering a command.
 * Leave the unsigned pos as is to avoid white space issues.
 */
string delimitBySpace(string &s)
{
	unsigned pos = 0;
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

void help(){
	cout << "add <priority-code> <patient-_name>\n"
<< "            Adds the patient to the triage system.\n"
<< "            <priority-code> must be one of the 4 accepted priority codes:\n"
<< "                1. immediate 2. emergency 3. urgent 4. minimal\n"
<< "            <patient-_name>: patient's full legal _name (may contain spaces)\n"
<< "next        Announces the patient to be seen next. Takes into account the\n"
<< "            type of emergency and the patient's arrival order.\n"
<< "peek        Displays the patient that is next in line, but keeps in queue\n"
<< "list        Displays the list of all _patientsVector that are still waiting\n"
<< "            in the order that they have arrived.\n"
<< "load <file> Reads the file and executes the command on each line\n"
<< "help        Displays this menu\n"
<< "quit        Exits the program\n";
}



















