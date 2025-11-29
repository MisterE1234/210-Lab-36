//COMSC-210|Ethan Aylard|Lab-36

#include <iostream>
#include <fstream>
#include <array>
#include "IntBinaryTree.h"
using namespace std;

int SZ_CODES = 20000; bool debug = true;

void addNode(string[], IntBinaryTree&);

int main() {
    string tempString;
    string randString[SZ_CODES];
    IntBinaryTree stringTree();

    //opening the codes for the array
    ifstream iFile("codes.txt");

    //using a for loop to read the file to the array:
    for(int i = 0; i < SZ_CODES; i++){

        getline(iFile, randString[i]);

    }

    iFile.close();

    if(debug){
        for(int i = 0; i < 10; i++){
            cout << randString[i] << endl;
        }
    }


    return 0;
}
