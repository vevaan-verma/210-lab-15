// COMSC-210 | Lab 15 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <climits> // for INT_MAX constant

class Movie; // forward declaration of the Movie class so it is recognized in the readMovies() function

/* FUNCTION PROTOTYPES */
vector<Movie> readMovies();
string getStringInput();
int getIntInput();

/* CONSTANTS */
const string FILE_PATH = "input.txt"; // name of the input file

/* GLOBAL VARIABLES */
ifstream fin; // global input file stream

class Movie {

private:
	string title;
	int yearReleased;
	string screenWriter;

public:
	// getter and setter for title
	string getTitle() const { return title; };
	void setTitle(string title) { this->title = title; };

	// getter and setter for year released
	int getYearReleased() const { return yearReleased; };
	void setYearReleased(int yearReleased) { this->yearReleased = yearReleased; };

	// getter and setter for screen writer
	string getScreenWriter() const { return screenWriter; };
	void setScreenWriter(string screenWriter) { this->screenWriter = screenWriter; };

	void print() const {

		cout << "Movie Information:" << endl;
		cout << "Title: " << title << endl;
		cout << "Year Released: " << yearReleased << endl;
		cout << "Screen Writer: " << screenWriter << endl;

	}
};

// main() is the entry point of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	fin.open(FILE_PATH);

	if (!fin.good()) { // if the file does not exist

		cout << "File " << FILE_PATH << " not found" << endl; // output error message
		return 1; // return an error code

	}

	readMovies(); // read the movies from the input file

	fin.close(); // close the file at the end
	return 0;

}

// readMovies() reads the movies from the input file
// arguments: none
// returns: none
void readMovies(vector<Movie>& movies) {

	vector<Movie> movies; // create a vector of movies

	// to make this function more scalable, the movie count shouldn't be hardcoded

	while (!fin.eof()) { // while the file has not reached the end

		string title, screenWriter;
		int yearReleased;

		title = getStringInput(); // get the title
		yearReleased = getIntInput(); // get the year released
		screenWriter = getStringInput(); // get the screen writer

		Movie movie; // create a new movie object
		movie.setTitle(title); // set the title
		movie.setScreenWriter(screenWriter); // set the screen writer
		movie.setYearReleased(yearReleased); // set the year released

		movies.push_back(movie); // add the movie to the vector

	}
}

// getValidatedString() gets the string input from a file stream; it will also exit the program if the file is not formatted as expected
// arguments: none
// returns: string - the validated string input
string getStringInput() {

	string inputStr; // variable to store the input (of type string)
	getline(fin, inputStr); // get the input from the input file stream

	if (inputStr.empty()) { // if the input is empty

		cout << "Invalid input. File does not contain valid formatting." << endl; // output an error message (this makes sure the program does not continue if the file is not formatted as expected)
		exit(1); // exit the program with an error code

	}

	return inputStr;

}

// getValidatedInt() gets the integer input from a file stream and ignores any invalid input
// arguments: none
// returns: int - the validated integer input
int getIntInput() {

	int inputInt; // variable to store the input (of type int)
	fin >> inputInt; // get the input from the input file stream
	fin.ignore(INT_MAX, '\n'); // ignore the invalid input

	return inputInt;

}