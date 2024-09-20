#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Structure for student data holding the first and last names of the students
struct STUDENT_DATA {
	string firstName;
	string lastName;
};

// Function to parse the data and return the STUDENT_DATA object
STUDENT_DATA parseStudentData(const string& line) {
	STUDENT_DATA student;
	stringstream ss(line);

	// Parse the first names
	getline(ss, student.firstName, ',');

	// Parse the last names
	getline(ss, student.lastName, ',');

	return student;
}

int main() {

	// Creates a vector based object of the struct object students
	vector<STUDENT_DATA> students;

	// Reads the file, StudentData.txt
	ifstream inFile("StudentData.txt");

	// If file doesn't open, prints message that it doesn't open
	if (!inFile) {
		cerr << "Error opening file!" << endl;
		return 1;
	}

	string line;

	// In the file, it loops each line reading each student's names
	while (getline(inFile, line)) {

		// To parse the line and store it in the vector
		STUDENT_DATA student = parseStudentData(line);
		students.push_back(student);
	}

	// Closes the file after reading it
	inFile.close();

#ifdef _DEBUG

	// TO output the students data for debugging
	cout << "Debug mode: printing student information:" << endl;

	// Output the student for verification
	for (const auto& student : students) {
		cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << endl;
	}
#endif

	return 0;
}