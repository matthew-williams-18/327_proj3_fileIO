/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>

#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//tries to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream inputFile;
	inputFile.open(filename);

	if(!inputFile.is_open()){
		contents = "";
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	//else, it is open
	string line;
	while (!inputFile.eof()){
		getline(inputFile, line);
		contents += line;
	}
	inputFile.close();
	return SUCCESS;
}

//tries to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outputFile;
	outputFile.open(filename);

	if(!outputFile.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	//else, it is open to write

	for (auto s: myEntryVector){
		outputFile << s + "\n";
	}
	outputFile.close();

	return SUCCESS;
}




