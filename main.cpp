/******************************************************************************************************
Program Filename: main.cpp
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: main
Input: none
Output: none
******************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include "file_action.h"
#include "file_check.h"
#include "algorithms.h"

int main(int argc, char* argv[])
{
    if (argc < 3)//cmd line arguments 
    {
	   std::cout << "Error! Error!" << std::endl;
	   std::cout << "Argument 1 is the program name" << std::endl;
	   std::cout << "Argument 2 is input file for greedy and dynamic programming algorithms." << std::endl;
	   std::cout << "Argument 3 is input file for brute force algorithm" << std::endl;
	   return 1;
    }
    
    //Hold input and output file names
    std::string input_filename;//Holds filename of first input file.
    std::string output_filename;//Holds filename of first output file.
    std::string input_filename2;//Holds filename of second input file.
    std::string output_filename2;//Holds filename of second output file.

    //Modify first output file name
    input_filename = argv[1];//Getting the first input filename via command line
    output_filename = input_filename;//Getting name for first output file
    output_filename.erase(output_filename.end() - 4, output_filename.end() - 0);//remove .txt from filename
    output_filename.append("change.txt");//appending change.txt to output_filename

    //Modify second output file name
    input_filename2 = argv[2];//Getting the second input filename via command line
    output_filename2 = input_filename2;//Getting name for second output file
    output_filename2.erase(output_filename2.end() - 4, output_filename2.end() - 0);//remove .txt from filename
    output_filename2.append("change.txt");//appending change.txt to output_filename

    std::cout << "1st INPUT FILE " << input_filename << std::endl;
    std::cout << "1st OUTPUT FILE " << output_filename << std::endl;
    std::cout << std::endl;
    std::cout << "2nd INPUT FILE " << input_filename2 << std::endl;
    std::cout << "2nd OUTPUT FILE " << output_filename2 << std::endl;
    std::cout << std::endl;

    std::string inputFile = input_filename;//first Input file name.
    std::ifstream if_inputStream;//input stream for first input file.

    std::string inputFile2 = input_filename2;//second Input file name.
    std::ifstream if_inputStream2;//input stream for second input file.

    //For first input file
    std::string tempFile = "temp.txt";//temp file name.
    std::fstream f_tempStream;//temp stream for temp file.

    //For second input file
    std::string tempFile2 = "temp2.txt";//temp2 file name.
    std::fstream f_tempStream2;//temp2 stream for temp file.

    std::string outputFile = output_filename;//first output file name.
    std::ofstream outputStream;//first output stream for output file.

    std::string outputFile2 = output_filename2;//second output file name.
    std::ofstream outputStream2;//second output stream for output file.

    output_file_check(outputStream, output_filename);//Checks if first output file is opened.
    output_file_check(outputStream2, output_filename2);//Checks if second output file is opened.
    if_file_check(if_inputStream, inputFile);//Checks to see if first input file is opened.
    if_file_check(if_inputStream2, inputFile2);//Checks to see if second input file is opened.
    f_file_check(f_tempStream, tempFile);//Check if temp file is opened
    f_file_check(f_tempStream2, tempFile2);//Check if temp2 file is opened

    std::vector<int> relay;// Holds values from array in first input file.
    std::vector<int> relay2;// Holds values from array in second input file.
    std::vector<int> coins;// Coins to calculate value from first input file.
    std::vector<int> coins2;// Coins to calculate value from second input file.
    int value;// Value to find with coins from first input file.
    int value2;// Value to find with coins from second input file.
    int arrayCount = 0;//Number of arrays in first input file.
    int arrayCount2 = 0;//Number of arrays in second input file.

    double time = 0; //Holds time for each array to be processed, used for greedy and DP algorithm run time
    double greedyTotalTime = 0;//Total run time for greedy algorithm
    double dpTotalTime = 0;//Total run time for DP algorithm

    //Variables used for brute force algorithm
    coinChange answer;//Keeps track of number of each coin used
    answer.num = 0;
    int minCoin;//Keeps track of total coins used.
    std::vector<int> storeCoin;//Vector to hold amount of each coin used.
    double bruteForceTotalTime = 0;//Total run time for brute force algorithm
    clock_t start, stop;//Used for calculating run time for brute force algorithm.

    //Strip first input file
    strip_file(if_inputStream, f_tempStream); //stripping first input file of [] and ,
    arrayCount = numofArrays(f_tempStream, tempFile);//Get count of number of arrays in first file.

    //Strip second input file
    strip_file(if_inputStream2, f_tempStream2); //stripping second input file of [] and ,
    arrayCount2 = numofArrays(f_tempStream2, tempFile2);//Get count of number of arrays in second file.

    //Iterate through the first input file for each array. Runs Greedy and DP algorithms
    for (int i = 1; i <= arrayCount + 1; i++)
    {
	   //First input file
	   relay = lineToVector(f_tempStream, tempFile, relay, i);//Populates relay vector with values.

	   if (i % 2 != 0)
	   {
		  coins = relay;//Set coins vector equal to relay.
		  relay.clear();//Clears the relay vector of all values.
	   }
	   else
	   {
		 value = relay[0];//Set value to the only index with a value in relay

		 /***************************GREEDY ALGORITHM**********************************/
		 //time = name_for_greedy_algorithm_function(outputStream, coins, value);
		 //greedyTotalTime += time;
		 //time = 03
		 
		 /***************************DP ALGORITHM**************************************/
		 //time = name_for_dp_algorithm_function(outputStream, coins, value);
		 //dpTotalTime += time;
		 //time = 0;

		 relay.clear();//Clears the relay vector of all values.
		 coins.clear();//Reset coins vector
		 value = 0;//Reset value
	   }
    }

    //Iterate through the second input file for each array. Runs brute force algorithm
    for (int i = 1; i <= arrayCount2 + 1; i++)
    {
	   //Reset timers;
	   start = 0;
	   stop = 0;
	   //Second input file
	   relay2 = lineToVector(f_tempStream2, tempFile2, relay2, i);//Populates relay vector with values.

	   if (i % 2 != 0)
	   {
		  coins2 = relay2;//Set coins vector equal to relay.
		  relay2.clear();//Clears the relay vector of all values.
	   }
	   else
	   {
		  value2 = relay2[0];//Set value to the only index with a value in relay

		  int arraySize2 = coins2.size();
		  start = clock();//Start timer
		  answer = bruteForce(coins2, value2, arraySize2);
		  stop = clock();//stop timer
		  bruteForceTotalTime += (stop - start) / double(CLOCKS_PER_SEC);

		  storeCoin.resize(arraySize2);//Sets the size of the amount of coins vector

		  for (int i = 0; i < arraySize2; i++)
		  {
			 storeCoin[i] = answer.coinCount[i];
		  }

		  minCoin = arraySum(answer.coinCount, arraySize2);

		  outputStream2 << "Brute Force Algorithm" << std::endl;
		  outputStream2 << "[";
		  for (int i = 0; i < arraySize2; i++)
		  {
			 if (i < (arraySize2 - 1))
			 {
				outputStream2 << storeCoin[i] << ", ";
			 }
			 else
			 {
				outputStream2 << storeCoin[i];
			 }
		  }
		  outputStream2 << "]";
		  outputStream2 << '\r' << '\n';
		  outputStream2 << minCoin << std::endl;
		  outputStream2 << '\r' << '\n';
		  outputStream2 << '\r' << '\n';

		  relay2.clear();//Clears the relay vector of all values.
		  coins2.clear();//Reset coins vector
		  value2 = 0;//Reset value
	   }
    }
    std::cout << "Alg1: Brute Force Run-time is: " << bruteForceTotalTime << std::endl;
    std::cout << "Alg2: Greedy Run-time is: " << greedyTotalTime << std::endl;
    std::cout << "Alg3: Dynamic Programming Run-time is: " << dpTotalTime << std::endl;

    //Closing file streams
    if_inputStream.close();
    if_inputStream2.close();
    f_tempStream.close();
    f_tempStream2.close();
    outputStream.close();
    outputStream2.close();

    return 0;

};//end main


