//COMSC-210|Ethan Aylard|Lab-36

#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

int SZ_CODES = 20000, START_AMOUNT = 10; bool debug = true;

void addNode(string[], IntBinaryTree&);
void deleteString(IntBinaryTree&);
void searchString(IntBinaryTree&);
void modifyString(IntBinaryTree&);
int menu();

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


    deleteString(stringTree);

    cout << "Initial Codes in the Tree in order:\n";
    stringTree.displayInOrder();

    searchString(stringTree);




    //deleting the stringTree at the end of program:
    stringTree.~IntBinaryTree();

    return 0;
}

//addNode() will add a new node to BST with a random string
//requires: a IntBinaryTree passed by reference and an array of strings
//returns: nothing
void addNode(string randS[], IntBinaryTree& ST){
    string tempString;
    //using a random number between 0 and SZ_CODES(20000) to get a random code as the string
    tempString = randS[rand()% SZ_CODES];
    ST.insertNode(tempString);
}

//deleteString() will search for a string in the string and delete it if found:
//requires: a IntBinaryTree passed by reference
//returns: nothing
void deleteString(IntBinaryTree& ST){
    string target;
    //asking the user what they would like deleted:
    cout << "What string would you like to delete?: ";
    
    getline(cin, target);
    //if the target is in the tree:
    if(ST.searchNode(target)){
        ST.remove(target); // delete the node from the tree
    }
    else{//if the node is not in the tree:
        cout << target << " was not found in the Tree.\n";
    }
    cout << endl;
}

//searchString() will search for a string in the string and say if it is found:
//requires: a IntBinaryTree passed by reference
//returns: nothing
void searchString (IntBinaryTree& ST){
    string target;
    //asking the user what they would like to search for:
    cout << "What string would you like to search for?: ";
    
    getline(cin, target);
    //if the target is in the tree:
    if(ST.searchNode(target)){
        cout << target << " is inside the Tree.\n";
    }
    else{//if the node is not in the tree:
        cout << target << " was not found in the Tree.\n";
    }
    cout << endl;
}


void modifyString(IntBinaryTree& ST){
    string target;
    //asking the user what they would like deleted:
    cout << "What string would you like to modify?: ";
    
    getline(cin, target);
    //if the target is in the tree:
    if(ST.searchNode(target)){
        
        
        
        ST.remove(target); // delete the node from the tree
    }
    else{//if the node is not in the tree:
        cout << target << " was not found in the Tree.\n";
    }
    cout << endl;

}
