/******************************************************************************************************
Program Filename: algorithms.cpp
Project 2
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/19/2015
Description: In this file are the 3 Coin Change algorithms 
Input: none
Output: none
******************************************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <limits>
#include "algorithms.h"

/******************************************************************************************************
Function: struct coinChange bruteForce(const std::vector<int>& coins, int value, int sizeOfArray)

Description: Algorithm 1: Brute Force method 

Parameters: const std::vector<int>& coins, int value, int sizeOfArray

Pre-Conditions: none
Post-Conditions: Returns number of coins used to make sum 
******************************************************************************************************/
struct coinChange bruteForce(const std::vector<int>& coins, int value, int sizeOfArray)
{
    int numCoins;//track min # of coins
    int best = -1;//helps determine min # of coins
    struct coinChange coinTrack;//track # of coins to find value
    struct coinChange coinAdd;//add to # of coins to find value
    struct coinChange numOfCoins;//track numOfCoins of all coins in array
    coinTrack.num = coinAdd.num = numOfCoins.num = 0;//initialize num var in structs
	//reset coin counts
    for (int i = 0; i < sizeOfArray; i++)
    {
	   coinTrack.coinCount[i] = coinAdd.coinCount[i] = numOfCoins.coinCount[i] = 0;
    }
	//base case
    if (value == 0)
    {
	   return numOfCoins;
    }
	//see if value is same as any coin denominations
    for (int i = 0; i < sizeOfArray; i++)
    {
	   if (coins[i] == value)
	   {
		  //if the same then return that value with denomiation count incremented
		  numOfCoins.coinCount[i]++;
		  return numOfCoins;
	   }
    }

	//loop to find min coins and # of coins for each denomination
    for (int i = 0; i < sizeOfArray; i++)
    {
	   if (coins[i] < value)
	   {
		  coinTrack = bruteForce(coins, value - coins[i], sizeOfArray);//recursion
		  coinAdd = bruteForce(coins, coins[i], sizeOfArray);//recursion
		  //loop to find # of coins for each denomination
		  for (int j = 0; j < sizeOfArray; j++)
		  {
			 coinTrack.coinCount[j] = coinTrack.coinCount[j] + coinAdd.coinCount[j];
		  }
		  //summing the number of coins
		  numCoins = arraySum(coinTrack.coinCount, sizeOfArray);
		  //conditional statement to find min # of coins
		  if (best == -1 || numCoins < best)
		  {
			 best = numCoins;

			 //loop to save # of each coin used to find value
			 for (int k = 0; k < sizeOfArray; k++)
			 {
				numOfCoins.coinCount[k] = coinTrack.coinCount[k];
			 }
		  }
	   }
    }
    return numOfCoins;//return the numOfCoins
}
/************************************Greedy**************************************************/




/************************************DP**************************************************/





/******************************************************************************************************
Function: int arraySum(int arr[], int sizeOfArray)

Description: Calculates the number of coins used

Parameters: int arr[], int sizeOfArray

Pre-Conditions: none.
Post-Conditions: Returns sum of total coins used
******************************************************************************************************/
int arraySum(int arr[], int sizeOfArray){

    int sum = 0;
    int i;

    for (i = 0; i < sizeOfArray; i++)
    {
	   sum = sum + arr[i];
    }
    return sum;
}
