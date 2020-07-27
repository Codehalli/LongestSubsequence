#define CATCH_CONFIG_MAIN

#define CATCH_CONFIG_MAIN

#include <string>

#include "catch.hpp"

#include "file.hpp"
#include "lcs.hpp"

/*TEST_CASE( "getDiff()", "[File]" )
{
    INFO("Hint: testing getDiff()");
    
    File f0, f1;
    
    REQUIRE(f0.setInput(std::string("tests/original.txt")));
    REQUIRE(f1.setInput(std::string("tests/new.txt")));
    
    REQUIRE(f0.getInput());
    REQUIRE(f1.getInput());
    
    // find LCS between files
    LCS<File> lcs_f0f1(f0,f1);
    
    // std::cout << "LCS print():" << std::endl;
    // lcs_f0f1.print();
    
    std::cout << std::endl << "LCS getDiff().d:" << std::endl;
    Diff<File> dff_f0f1 = lcs_f0f1.getDiff();
    std::cout << dff_f0f1.d;
    
    std::cout << std::endl << "LCS getDiff().obj/op:" << std::endl;
    for(int i = 0; i < dff_f0f1.obj_x.size(); i++)
        std::cout << dff_f0f1.obj_x[i] << " " << dff_f0f1.obj_y[i] << " " << dff_f0f1.op[i] << std::endl;
    
    REQUIRE(1 == 1);
} */

TEST_CASE( "File I/O for Grader", "[File]" )
{
    File f0, f1, f2;
    
    f0.setInput(std::string("../tests/test.txt"));
    f0.getInput();
    
    REQUIRE(f0[0] == std::string("XIII"));
    
    f1 = f0;
    f1.setOutput(std::string("../tests/test-out.txt"));
    f1.getOutput();
    
    f2.setInput(std::string("../tests/test-out.txt"));
    f2.getInput();
    
    REQUIRE(f0[0] == f2[0]);
}
/*
TEST_CASE( "File I/O for Local Tests (UNIX/OSX)", "[File]" )
{
    File f0, f1, f2;
    
    f0.setInput(std::string("tests/test.txt"));
    f0.getInput();
    
    REQUIRE(f0[0] == std::string("XIII"));
    
    f1 = f0;
    f1.setOutput(std::string("tests/test-out.txt"));
    f1.getOutput();
    
    f2.setInput(std::string("tests/test-out.txt"));
    f2.getInput();
    
    REQUIRE(f0[0] == f2[0]);
}

TEST_CASE( "File I/O for Local Tests (Windows)", "[File]" )
{
    File f0, f1, f2;
    
    f0.setInput(std::string("tests\test.txt"));
    f0.getInput();
    
    REQUIRE(f0[0] == std::string("XIII"));
    
    f1 = f0;
    f1.setOutput(std::string("tests\test-out.txt"));
    f1.getOutput();
    
    f2.setInput(std::string("tests\test-out.txt"));
    f2.getInput();
    
    REQUIRE(f0[0] == f2[0]);
} */

