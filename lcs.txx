/*
* The purpose of this program is to learn to focus on implement algorithms for the LCS problems.
* Name: Pranav Rao 
* Date: September 19, 2019
*/

#include <algorithm>
#include "lcs.hpp"
#include "file.hpp"

using namespace std;

//This is the Default Constructor
template<typename T> LCS<T>::LCS(const T& x, const T& y)
{
	//Defining the variables
	X = x;
	Y = y;
	//length m and n
	m = X.length();
	n = Y.length();
	//1D array
	C = new uint32_t*[m + 1]; 
	//For  loop to itterate the value of C;
	for (uint32_t i = 0; i <= m; i++)
	{
		C[i] = new uint32_t[n + 1];
	}
	//returns the Build
	BuildC();
}
//This functionis building the Table
template<typename T>  void LCS<T>::BuildC()
{
	//For loop from the algorithm given in assignment(except X and Y is minus 1 to start at 0)
	for (uint32_t i = 0; i <= m; i++) 
	{
		C[i][0] = 0;
	}
	for (uint32_t i = 0; i <= n; i++)
	{
		C[0][i] = 0;
	}
	for (uint32_t i = 1; i <= m; i++) 
	{
		for (uint32_t j = 1; j <= n; j++)
		{
			if (X[i-1] == Y[j-1]) 
				C[i][j] = C[i - 1][j - 1] + 1;
			else
				C[i][j] = max(C[i][j - 1], C[i - 1][j]);
		}
	}
	//boolean delclarations for the table
	table = true;
	sequence = false;
}

//Default destructor
template<typename T> LCS<T>::~LCS()
{
    delete[]C;
    C = nullptr;
}

//Constructor using the backtrack algorithm
template<typename T> T LCS<T>:: backtrack(uint32_t i, uint32_t j) const
{
	// This while loop starts from the right most bottom corner and 
   // backtracks one by one 4 3 2 1 0 
	T LCS = T();
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
        
			LCS = LCS + X[i-1] ;
            
			i--;   
			j--;
		}
		else if (C[i - 1][j] >= C[i][j - 1])
			i--;
		else
			j--;
	}
	//returns LCS;
	return LCS;
}


//This is the recurssion function
template<typename T> 
T LCS<T>::LCSRecursion(uint32_t i, uint32_t j) const
{
	//Algorithm provided by the assigment.
	if (i == 0 || j == 0)
	{
		return T();
	}
	if (X[i - 1] == Y[j - 1])
	{
		return LCSRecursion(i - 1, j - 1) + X[i - 1];
	}
	if (C[i][j - 1] > C[i - 1][j])
	{
		//returns LCS Recursion either j-1
		return LCSRecursion(i, j - 1);
	}
		//returns LCS recursion either i-1
		return LCSRecursion(i - 1, j);
}

//This function returns LCS with no recursion
template<typename T> T LCS<T>::get()
{
	return backtrack(m, n);
}

//This function returns the LCS with recursion
template<typename T> T LCS<T>::getRecur()
{
	return LCSRecursion(m, n);
}

//This functions returns the lenght of LCS
template<typename T> uint32_t LCS<T>::length()
{
    return LCSRecursion(m, n).length();
}

//This function prints the lCS
template<typename T> void LCS<T>::print()
{
	cout << getRecur();
}

//This function printsDiff
template<typename T> void LCS<T>::printDiff(uint32_t i, uint32_t j) const
{
	//print algorithm provided in the assignment 
	if (i > 0 && j > 0 && X[i-1] == Y[j-1]) 
	{
		printDiff(i - 1, j - 1);
		cout << " " << X[i-1];
	}
	else if (j > 0 && (i == 0 || C[i][j - 1] >= C[i - 1][j]))
	{
		printDiff(i, j - 1);
		cout << " +" << Y[j-1];
	}
	else if (i > 0 && (j == 0 || C[i][j - 1] < C[i - 1][j]))
	{
		printDiff(i - 1, j);
		cout << " -" << X[i-1];
	}
	else
		cout << "";
}

//This funciton call the printDiff function
template<typename T> void LCS<T>::printDiff()
{
	printDiff(m, n);
}

//This function to return x and y of diff structure
template <typename T>
void LCS<T>::getDiff(uint32_t i , uint32_t j)
{
    if (i > 0 && j > 0 && X[i-1] == Y[j-1])
    {
        getDiff(i - 1, j - 1);
        
    }
    
    else if (j > 0 && (i == 0 || C[i][j - 1] >= C[i - 1][j]))
    {
        getDiff(i, j - 1);
        
        DFF_XY.d = DFF_XY.d+Y[j-1];
        DFF_XY.obj_x.push_back(i);
        DFF_XY.obj_y.push_back(j);
        DFF_XY.op.push_back("a");
        
    }
    else if (i > 0 && (j == 0 || C[i][j - 1] < C[i - 1][j]))
    {
        getDiff(i - 1, j);

        DFF_XY.d = DFF_XY.d+X[i-1];
        DFF_XY.obj_x.push_back(i);
        DFF_XY.obj_y.push_back(j);
        DFF_XY.op.push_back("d");
    }
}

//This function is for getDiff
template <typename T>
Diff<T> LCS<T>::getDiff()
{
    getDiff(m,n);
    return DFF_XY;
}













