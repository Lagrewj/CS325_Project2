/******************************************************************************************************
Program Filename: file_check.cpp
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: checking files
Input: none
Output: none
******************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "file_check.h"

/******************************************************************************************************
Function: void if_file_check(std::ifstream& inStream, std::string filename)

Description: Checks to make sure input file opens.

Parameters: std::ifstream& inStream, std::string filename

Pre-Conditions: Must be attempting to open input file
Post-Conditions: Input/output file will be opened.
******************************************************************************************************/
void if_file_check(std::ifstream& inStream, std::string filename)
{
    inStream.open(filename.c_str(), std::ios::in);
    if (inStream.fail())
    {
	   std::cout << "Error opening file.\n";
	   exit(1);
    }
}

/******************************************************************************************************
Function: void output_file_check(std::ofstream& outStream, std::string filename);

Description: Checks to make sure output file opens.

Parameters: std::ofstream& outStream, std::string filename

Pre-Conditions: Must be attempting to open output file
Post-Conditions: Output file will be opened.
******************************************************************************************************/
void output_file_check(std::ofstream& outStream, std::string filename)
{
    outStream.open(filename.c_str(), std::ios::out | std::ios::app);
    if (outStream.fail())
    {
	   std::cout << "Output file opening failed.\n";
	   exit(1);
    }

}

/******************************************************************************************************
Function: void f_file_check(std::fstream& inStream, std::string filename)

Description: Checks to make sure input/output file opens.

Parameters: std::fstream& inStream, std::string filename

Pre-Conditions: Must be attempting to open input/output file
Post-Conditions: Input/output file will be opened.
******************************************************************************************************/
void f_file_check(std::fstream& fStream, std::string filename)
{
    fStream.open(filename.c_str(), std::ios::out | std::ios::in | std::ios::trunc);
    if (fStream.fail())
    {
	   std::cout << "Error opening file.\n";
	   exit(1);
    }
}


