/******************************************************************************************************
Program Filename: file_check.h
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: checking files
Input: none
Output: none
******************************************************************************************************/
#ifndef FILE_CHECK_H
#define FILE_CHECK_H

void if_file_check(std::ifstream& inStream, std::string filename);
void output_file_check(std::ofstream& outStream, std::string filename);
void f_file_check(std::fstream& fStream, std::string filename);

#endif