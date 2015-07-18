/******************************************************************************************************
Program Filename: file_action.cpp
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: strip files and save  
Input: none
Output: none
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "file_check.h"
#include "file_action.h"

/******************************************************************************************************
Function: void saveAs(std::ifstream& ioStream, std::ofstream& saveto, std::string filename);

Description:Saves numOfCoins to a output file.

Parameters: std::ifstream& ioStream, std::ofstream& saveto, std::string filename

Pre-Conditions: Must have an input and output file.
Post-Conditions: The ifstream file is copied to ofstream file.
******************************************************************************************************/
void saveAs(std::ifstream& ifStream, std::ofstream& saveto, std::string filename)
{
    output_file_check(saveto, filename);

    std::string line;//Holds each line of text from the input file.

    getline(ifStream, line);
    while (ifStream)
    {
	   saveto << line << std::endl;//Copies input file text to output file.

	   getline(ifStream, line);
    }
    ifStream.clear();//clears the end of file flag (eof).
    ifStream.seekg(0L, std::ios::beg);//Move back to the beginning of the input file stream.
}

/******************************************************************************************************
void strip_file(std::ifstream& inStream, std::string fileName)

Description: Opens a input file and strips symbols and outputs to temp file.

Parameters: std::ifstream& inStream, std::string fileName

Pre-Conditions: Input file must be opened.
Post-Conditions: Input file will be stripped of symnbols and output to temp file.
******************************************************************************************************/
void strip_file(std::ifstream& inStream, std::fstream& tempStream)
{
    std::vector<char> lines;//create a vector to hold characters.

    while (inStream)//iterate through each line in file.
    {
	   char ch;
	   int count = 0;
	   ch = inStream.get();//Get character from line.
	   while (ch != EOF)//While not end of line.
	   {
		  if (ch != ',' && ch != '[' && ch != ']')//Do not add these symbols.
		  {
			 lines.push_back(ch);//Push character to vector.
			 count++;//inc count, used to loop through vector.
		  }
		  ch = inStream.get();//get next char in line.
	   }
	   for (int i = 0; i < count; i++)
	   {

		  //std::cout << lines[i];  //Outputs each line in file to console.
		  tempStream << lines[i];//Outputs to temp.txt file

	   }
	   lines.clear();//Clears the vector of all values.
    }
    inStream.clear();//clears the end of file flag (eof).
    inStream.seekg(0L, std::ios::beg);//Move back to the beginning of the input file stream.
    tempStream.clear();//clears the end of file flag (eof).
    tempStream.seekg(0L, std::ios::beg);//Move back to the beginning of the input file stream.

}//end strip_file

/******************************************************************************************************
std::vector<int> lineToVector(std::fstream& inStream, std::string fileName, std::vector<int> bam, int thisArray)

Description: Pushes numbers from a line in a file to a vector.

Parameters: std::fstream& inStream, std::string fileName, std::vector<int> bam, int thisArray

Pre-Conditions: Input file must be opened.
Post-Conditions: Line from file will be pushed to a vector and returned.
******************************************************************************************************/
std::vector<int> lineToVector(std::fstream& inStream, std::string fileName, std::vector<int> bam, int thisArray)
{
    int arrayCount = 0;//Counts the number of lines iterated through file.
    std::vector<std::string> lines;//create a vector to hold current line in file.

    getline(inStream, fileName);//Get first line in file.

    while (inStream)//iterate through each line in file.
    {
	   arrayCount++;//Line currently on in file.
	   lines.push_back(fileName);//push line in file to lines vector to hold.
	   std::istringstream iss(fileName);

	   int next = 0;//next number in line.

	   if (arrayCount == thisArray)//if the line of file is equal to the line we want push data to vector.
	   {
		  while (iss >> next)//next number
		  {
			 bam.push_back(next);//Input number into vector.
		  }

		  return bam; // return the vector.
	   }
	   else
	   {
		  lines.clear();//Clears the lines vector of all values.
	   }
    }

}
/******************************************************************************************************
int numofArrays(std::fstream& inStream, std::string fileName)

Description: Counts the number of lines that are in a file.

Parameters: std::fstream& inStream, std::string fileName

Pre-Conditions: Input file must be opened.
Post-Conditions: Returns the number of lines in a file.
******************************************************************************************************/
int numofArrays(std::fstream& inStream, std::string fileName)
{
    int count = 0;
    getline(inStream, fileName);//Get first line in file.

    // GotoLine(inStream, thisArray);
    while (!inStream.eof())//iterate through each line in file.
    {
	   count++;
	   getline(inStream, fileName);//Get next line in file.
    }
    inStream.clear();//clears the end of file flag (eof).
    inStream.seekg(0L, std::ios::beg);//Move back to the beginning of the input file stream.

    return count;
}