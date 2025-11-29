//COMSC-210|Ethan Aylard|Lab-36

#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

int SZ_CODES = 20000, START_AMOUNT = 10; bool debug = true;

void addNode(string[], IntBinaryTree&);

int main() {
    srand(time(0));

    string randString[SZ_CODES];
    IntBinaryTree stringTree;

    //opening the codes for the array
    ifstream iFile("codes.txt");
    if(!iFile){
        cout << "file failed to open\n";
    }

    if(debug){
        cout << "file opens!\n";
    }
    //using a for loop to read the file to the array:
    for(int i = 0; i < SZ_CODES; i++){

        getline(iFile, randString[i]);

    }

    iFile.close();

    if(debug){
        cout << "file closes!\n";
    }

    if(debug){
        for(int i = 0; i < START_AMOUNT; i++){
            cout << randString[i] << endl;
        }
    }

    //Adding some basic codes to the tree:
    for(int i = 0; i < START_AMOUNT; i++){
        addNode(randString, stringTree);
    }

    
    //displaying the codes in the tree:
    cout << "Initial Codes in the Tree in order:\n";
    stringTree.displayInOrder();

    cout << "Initial Codes in the Tree in Postorder:\n";
    stringTree.displayPostOrder();

    cout << "Initial Codes in the Tree in Preorder:\n";
    stringTree.displayPreOrder();




    //deleting the stringTree at the end of program:
    stringTree.~IntBinaryTree();

    return 0;
}

void addNode(string randS[], IntBinaryTree& ST){
    string tempString;

    tempString = randS[rand()% SZ_CODES];
    ST.insertNode(tempString);
}
