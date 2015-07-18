/******************************************************************************************************
Program Filename: algorithms.h
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: In this file are the 3 Coin Change algorithms 
Input: none
Output: none
******************************************************************************************************/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

struct coinChange {
    int num;
    int coinCount[20];
};


struct coinChange bruteForce(const std::vector<int>& coins, int value, int sizeOfArray);
int arraySum(int arr[], int sizeOfArray);

#endif