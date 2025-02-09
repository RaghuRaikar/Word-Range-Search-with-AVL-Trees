#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include "bst.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        throw std::invalid_argument("Usage: ./wordrange <INPUT FILE> <OUTPUT FILE>");
    }

    ifstream input;
    ofstream output;

    input.open(argv[1]);
    output.open(argv[2]);

    string command;

    char *com, *dummy, *valstr, *op;

    BST myBST;

    while(getline(input,command))
    {
        if(command.length() == 0)
        {
            continue;
        }
        com = strdup(command.c_str());
        op = strtok(com, " \t");
        valstr = strtok(NULL, " \t");
        if(strcmp(op,"i")==0)
        {
            myBST.insert(valstr);
        }
        if(strcmp(op,"r")==0)
        {
            string valstr2 = strtok(NULL, " \t");
            int answer = myBST.range(valstr,valstr2);
            output << answer << endl;
        }
    }
    //myBST.preOrder();
    myBST.deleteBST();
    input.close();
    output.close();
    
}