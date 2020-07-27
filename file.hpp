#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <string>
#include <vector>

/*
 * A simple C++ class for reading/writing lines from/to files
 */ 
class File
{
private:
  //Required variables: your code must make use of these
  std::vector<std::string> lines; //the lines of the file (one line per vector element)
  std::string ifile; //input filename
  std::string ofile; //output filename
  
public:
  /*
   * Constructor to set defaults for File (allocate a vector with space for 100 entries, ifile and ofile empty strings)
   */ 
  File();

  /*
   * Destructor: clean-up dynamically allocated memory
   */ 
  ~File();

  /*
   * Set the file to read lines from into lines
   * @return if true the file can be read from
   */
  bool setInput(const std::string& fin);

  /*
   * Set the file to write the lines contained in lines to   
   * @return if true file can be written to
   */
  bool setOutput(const std::string& fout);

  /*
   * Read the contents of the input file into lines
   * @return if true file was successfully read into lines (i.e., a line/lines were read from it and no errors encountered). Note: empty file does not produce error.
   */
  bool getInput();
  
  /*
   * Write the contents of lines to the output file
   * @return if true lines were successfully written to the file (i.e., a line/lines were written to it and no errors encountered). Note: empty lines does not produce error.
   */
  bool getOutput()const;

  /*
   * Return the number of lines in File
   * @return the number of lines in lines (return zero if lines is empty)
   */
  std::size_t length() const;
  
  /*
   * Operator to add a line (as std::string) to the end of a File
   * @return a File object with string rhs appended to lhs
   */ 
  File operator+(const std::string& rhs) const;

  /*
   * Operator to add one file to another (appends rhs to end of lhs)
   * @return a File object with rhs appended to lhs
   */ 
  File operator+(const File& rhs) const;

  /*
   * Operator to return a line (as std::string) of a File (uses zero indexing)
   * @return the line at pos in File (return an empty string if line doesn't exist at pos)
   */
  std::string operator[](std::size_t pos) const;

  /*
   * Operator to print the contents of a File to std::cout (useful for debugging)
   */
  friend std::ostream& operator<<(std::ostream& os, const File& f);
};

#endif //_FILE_HPP_
