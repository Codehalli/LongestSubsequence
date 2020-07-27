#include <iostream>
#include <fstream>
#include "file.hpp"

using namespace std;
//Operator Function for rhs
File File::operator+(const std::string& rhs) const
{
    File lhs = *this;
    
    lhs.lines.push_back(rhs);
    
    return lhs;
}

//Operator Function for file of rhs
File File::operator+(const File& rhs) const
{
    File lhs = *this;
    std::size_t i;
    
    for(i = 0; i < rhs.lines.size(); i++)
        lhs.lines.push_back(rhs.lines[i]);
    
    return lhs;
}
//Operator Function for pos
std::string File::operator[](std::size_t pos) const
{
    if(pos < lines.size())
        return lines[pos];
    else
        return std::string();
}
//Operator Function for file function
std::ostream& operator<<(std::ostream& os, const File& f)
{
    for(int i = 0; i < f.lines.size(); i++)
        os << f.lines[i] << std::endl;
    return os;
}

//File function Constructor
File::File()
{
    lines.reserve(100); //vector of size 100 to hold lines of the type string
    
    ofile = "";
    ifile = "";
}

//this function is the destructor for file
File::~File()
{
    lines.clear();
    
}
// Bool Function for set Input from a file
bool File::setInput(const std::string &fin)
{
    std::ifstream in(fin);
    
    if(in.is_open())
    {
        ifile = fin;
        return true;
    }
    in.close();
    return false;
}

//Bool Function for output
bool File::setOutput(const std::string &fout)
{
    std::ofstream out(fout);
    
    if(out.is_open())
    {
        ofile = fout;
        return true;
    }
    out.close();
    return false;
}

//Bool Function for input
bool File::getInput()
{
    //setting input file stream
    ifstream in;
    in.open(ifile);
    string line;
    
    if(in.is_open())
    {
        
        while(!in.fail())
        {
            getline(in,line);
            lines.push_back(line);
        }
        
        return  true;
    }
    in.close();
    return false;
}
//Bool Function for output
bool File::getOutput() const
{
    //setting output file stream
    ofstream out;
    out.open(ofile);
    
    if(out.is_open())
    {
        
        for( int i = 0; i< lines.size(); i++)
        {
            out << lines[i] << endl;
        }
        
       /* int i=0;
        while (i < lines.size())
        {
            out << lines[i] << endl;
            i++;
        } */
        return true;
    }
    out.close();
    return false;
}
//Function for lenght
size_t File::length() const
{
    if(lines[lines.size()-1]=="")
    {
        return lines.size()-1;
    }
    return lines.size();
}


