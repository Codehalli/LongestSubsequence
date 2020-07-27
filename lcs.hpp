#ifndef _LCS_HPP_
#define _LCS_HPP_

#include <iostream>

/**
 * This is a class to compute the longest common subsequence (LCS) between two sequences X and Y
 */

template<typename T>
struct Diff //a struct to store the diff in an easy to parse way (for diff.cpp)
{
  T d; //the differences (only) between sequences X & Y
  std::vector<uint32_t> obj_x; //index of object of X that the difference entry applies to (i.e., current i in Sequence X)
  std::vector<uint32_t> obj_y; //index of object of Y that the difference entry applies to (i.e., current j in sequence Y)
  std::vector<std::string> op; //operation (a or d) on the object of X/Y that the difference entry applies to (e.g., adding an object from Y)
};

template<typename T>
class LCS
{
private:
  //required variables
  T X; //sequence X
  T Y; //sequence Y
  uint32_t m,n; //length of sequences X and Y, respectively
  uint32_t **C; //X.length()-by-Y.length() 2d array
  
  //optional variables
  bool table; //true if we've built the C table
  bool sequence; //true if we've found the LCS of X & Y
  T LCS_XY; //LCS of X & Y
  Diff<T> DFF_XY;

  //optional functions
  void BuildC(); //build C table
  void FindLCS(); //determine LCS from C table
  T backtrack(uint32_t i, uint32_t j) const; //for backtracking over C table to find LCS
  T LCSRecursion(uint32_t i, uint32_t j) const; //recursive function to find LCS
  //std::pair<std::vector,T> backtrackDiff(uint32_t i, uint32_t j) const; //for backtracking over C table to find diff
  void printDiff(uint32_t i, uint32_t j) const; //for backtracking over C table to print diff
  void getDiff(uint32_t i, uint32_t j);
  
public:
  /**
   * Parameterized constructor. The user supplies the sequences we will calculate the LCS for
   */ 
  LCS(const T& x, const T& y);

  /**
   * Destructor because we're dynamically allocating memory (C)
   */  
  ~LCS();
  
  /**
   * Calculates the length of the LCS between X & Y using the dynamic programming approach
   * @return the length of the LCS
   */
  uint32_t length();

  /**
   *Return the LCS between X & Y using the recursive approach
   * @return the length in the container form of X & Y
   */
  T getRecur();
  
  /**
   * Return the LCS between X & Y
   * @return the LCS in the container form of X & Y
   */
  T get();

  /**
   * Display the LCS between X & Y to std::cout
   */
  void print();

  /**
   * Display the difference between X & Y using diff notation to std::cout
   */
  void printDiff();

  /**
   * Return the difference between X & Y in a Diff structure 
   * (i.e., only the objects that need to be added to/removed from X in order to 
   * transform it into Y)
   * @return the difference between X & Y, including objects the difference applies to and the difference operation
   */
  Diff<T> getDiff();
};

#include "lcs.txx"

#endif
