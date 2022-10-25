/* project3_May_Wdm0032.cpp
 * Will May: Program that merges the numbers in two files 
 * and writes all the numbers into a third file. 
 * COMPILER: Standard Compiler
 *
 * Sources: 
 * Dr. Li's project 3 hints
 * Piazza Questions
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

//Initializes all of the methods.
int toString(string stringNumber);
int getSize(string fileName);
int readFile(int inputArray[], string fileName);
void writeToFile(int outputArray[], int outputArray_size, string outputName);
int sort(int inputArary1[], int inputArray1_size, int inputArray2[],int inputArray2_size, int outputArray[]);


//Main method/driver for program.
int main() {
	string i1;
	string i2;
	string outputName;

	cout << "*** Welcome to Will's sorting program ***\n";
	
	//Deals with the first input file.
	cout << "Enter the first input file name: ";
	cin >> i1; 
	int a1[getSize(i1)];
	int a1Size = readFile(a1, i1);

	//Deals with the second input file.
	cout << "\nEnter the second input file name: ";
	cin >> i2;
	int a2[getSize(i2)];
	int a2Size = readFile(a2, i2);

	//Sorts the list
	int a3[a1Size + a2Size];
	int a3Size = sort(a1, a1Size, a2, a2Size, a3);
	cout << "\nThe sorted list of " << a3Size << " is: ";

	for(int i = 0; i < a3Size; i++){
		cout << a3[i] << " ";
	}

	//Asks for output file name.
	cout << endl << "Enter the output file name: ";
	cin >> outputName;
	
	//Writes the data to the output file.
	writeToFile(a3, a3Size, outputName);
	cout << "\n*** Please check the new file - " << outputName << " ***\n";
	cout << "*** Goodbye. ***\n";

	return 0;
}

//Method for toString.
int toString(string stringNumber) {
	stringstream stream(stringNumber);
	int num;
	stream >> num;
	return num;
}

//Method for getSize.
int getSize(string fileName) {
	ifstream inFile(fileName.c_str());
	int size = 0;
	if(inFile.is_open()) {
		string line;
		getline(inFile, line);
		while(!inFile.eof()) {
			size++;
			getline(inFile, line);
		}
	}			
	return size;
}

//Method for readFile.
int readFile(int inputArray[], string fileName) {
	ifstream inFile(fileName.c_str());
	int size = 0; 
	if(inFile.fail()) {
		cout << "Input file opening failed!\n";
		exit(1);
	}
	if (inFile.is_open()) {
		string line;
		getline(inFile, line);
		while(!inFile.eof()) {
			inputArray[size++] = toString(line);
			getline(inFile, line);
		}
	}
	cout << "The list of " << size << " numbers in file " << fileName << " is: \n";
	for(int i = 0; i < size; i++) {
		cout << inputArray[i] << endl;
	}
	return size;
}

//Method for writeToFile.
void writeToFile(int outputArray[], int outputArray_size, string outputName) {
        ofstream outFile;
        outFile.open(outputName.c_str());
        for(int count = 0; count < outputArray_size; count++){
                outFile << outputArray[count] << endl;
        }
        outFile.close();
}

//Method for sort.
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
	int outputArray_size = inputArray1_size + inputArray2_size;
	for(int a1Count = 0; a1Count < inputArray1_size; a1Count++) {
		outputArray[a1Count] = inputArray1[a1Count];
	}
	for(int a2Count = 0; a2Count < inputArray2_size; a2Count++) {
		outputArray[inputArray1_size + a2Count] = inputArray2[a2Count];
	}
	for(int i = 0; i < outputArray_size; i++) {
		int gg = outputArray[i];
		int j = 1; 
		while(j > 0 && gg < outputArray[j - 1]) {
			outputArray[j] = outputArray[j - 1];
			j--;
		}
		outputArray[j] = gg;
	}
	cout << endl;
	return inputArray1_size + inputArray2_size;
}

 
