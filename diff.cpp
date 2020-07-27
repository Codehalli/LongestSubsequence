#include "file.hpp"
#include "lcs.hpp"
#include <iostream>
#include <fstream>

using namespace std;

//Main function to implement patching by finding difference

int main(int argc, char** argv)
{
    //declaring variable
    string original, new_F, out_P;
    //iniating
    original = argv[1];
    new_F = argv[2];
    out_P = argv[3];
    //File type
    File org, ne, ouput;
    //Org SetInput and Get
    org.setInput(original);
    org.getInput();
    //file SetInput and Get
    ne.setInput(new_F);
    ne.getInput();
    
    std::ofstream out(out_P);
    
    LCS<File>LCS (org,ne);
    Diff<File> dff = LCS.getDiff();
    
    int i= 0;
    //while loop condition for diff
    while(i<dff.obj_x.size())
    {
        if (dff.op[i] == "a")
        {
            out << dff.obj_x[i] << "a";
            out << dff.obj_y[i];
            
            int j = 1;
            //if condtion for size
            if(i + j < dff.obj_x.size())
            {
                while(dff.obj_x[i] == dff.obj_x[i+j])
                {
                    j++;
                    if(i+j >= dff.obj_x.size())
                        break;
                }
             }
            //if condtion  for size
            if (j!=1)
                out <<","<<dff.obj_y[i+j-1];
            out << endl;
            
            //when to stop
            for(int a = i; a<i+j;a++)
            {
                out<< "> " << dff.d[a]<<endl;
            }
            
            i = i + j;
        }
       //while loop condition continued for diff
        if(dff.op[i]=="d")
        {
            out <<dff.obj_x[i];
            int k =1;
            if((i + k) < dff.obj_x.size())
            {
                while(dff.obj_y[i] == dff.obj_y[i+k])
                {
                    k++;
                    if(i+k >= dff.obj_x.size())
                        break;
                }
            }
            //if statmetnt for d
            if(k==1)
            {
                out << "d" << endl;
            }
            else
            {
                out << "," << dff.obj_x[i+k-1] << "d" << endl;
            }
            //for statment for greater than.
            for(int a2 = i; a2 < i+k; a2++)
            {
                out<< "< " <<dff.d[a2]<<endl;
            }
            
            i = i + k;
         }
     }
}

