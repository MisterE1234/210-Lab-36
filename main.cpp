//COMSC-210|Ethan Aylard|Lab-36

#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

//universal variables:
int SZ_CODES = 20000, START_AMOUNT = 10; bool debug = false;

//The function Prototypes
void addNode(string[], IntBinaryTree&);
void deleteString(IntBinaryTree&);
void searchString(IntBinaryTree&);
void modifyString(IntBinaryTree&);
int menu();

int main() {
    //seeding the randomizer to be true random:
    srand(time(0));

    string randString[SZ_CODES];  //declaing a string array to carry the codes
    IntBinaryTree stringTree; //declaring the BST
    bool exit = false; //declaring a bool to control if the menu should be exited from

    //opening the codes for the array
    ifstream iFile("codes.txt");
    if(!iFile){ //checking to see if the file opened:
        cout << "file failed to open\n";
        return -1;
    }

    if(debug){
        cout << "file opens!\n";
    }
    //using a for loop to read the file to the array:
    for(int i = 0; i < SZ_CODES; i++){

        getline(iFile, randString[i]);

    }

    //closing the file
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

    //Using a switch and a while loop to act as the menu:
    while(!exit){
        switch(menu()){
            case 0: //Exiting program:
                cout << "Exiting Program...";
                exit = true;
                break;
            case 1: //Display the BST
                stringTree.displayInOrder();
                break;
            case 2: // Add a new Node to BST
                addNode(randString, stringTree);
                break;
            case 3: // delete a node form the BST
                deleteString(stringTree);
                break;
            case 4:// determine if a string is in the BST
                searchString(stringTree);
                break;
            case 5: // modiify a string in the BST:
                modifyString(stringTree);
                break;
            default: // error contegency
                cout << "Error: no case number\n";

        }
    }

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

//deleteString() will search for a string in the tree and delete it if found:
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

//searchString() will search for a string in the tree and say if it is found:
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

//modifyString() will search for a string in the stree and ask the user what would they like instead:
//requires: a IntBinaryTree passed by reference
//returns: nothing
void modifyString(IntBinaryTree& ST){
    string target;
    string newValue;
    //asking the user what they would like deleted:
    cout << "What string would you like to modify?: ";
    
    getline(cin, target);
    //if the target is in the tree:
    if(ST.searchNode(target)){
        
        cout << "What would you like to change it to?: ";
        
        getline(cin, newValue);
        
        ST.remove(target); // delete the node from the tree
        ST.insertNode(newValue);//adding the new node into the tree
    }
    else{//if the node is not in the tree:
        cout << target << " was not found in the Tree.\n";
    }
    cout << endl;

}

//menu() displays the menu for the program. It will also prompt the user to choose.
//requires: nothing
//returns: an int value
int menu(){
    int choice = 0;
    bool valid = false;

    cout << "BST Menu: \n"
    << "[1] Display Tree\n"
    << "[2] Add New Node\n"
    << "[3] Delete Node\n"
    << "[4] Search For Node\n"
    << "[5] Modify Node\n"
    << "[0] End Program\n";

    //using a while loop to validate the user's response:
    while(!valid){
        cout << "Which would you like (0-5)?: ";
        cin >> choice;

        if(cin.fail()){ //if not an integer:
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid Entry. Not an Integer. Try again\n";
        }
        else if(choice > 5 || choice < 0){ // if not an option in the menu:
            cout << "Invalid Entry. Not within range. Try again\n";
        }
        else{// if correct:
            valid = true;
        }

    }
    //using cin.ignore so that any future getlines are not messed up.
    cin.ignore(10000,'\n');


    return choice;
}
