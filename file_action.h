/******************************************************************************************************
Program Filename: file_action.h
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: strip files and save 
Input: none
Output: none
******************************************************************************************************/

#ifndef FILE_ACTION_H
#define FILE_ACTION_H


void saveAs(std::ifstream& ifStream, std::ofstream& saveto, std::string filename);
void strip_file(std::ifstream& inStream, std::fstream& tempStream);
std::vector<int> lineToVector(std::fstream& inStream, std::string fileName, std::vector<int> bam, int thisArray);
int numofArrays(std::fstream& inStream, std::string fileName);

#endif