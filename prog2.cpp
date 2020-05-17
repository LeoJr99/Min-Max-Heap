// prog2.cpp

#include "minMaxHeap.h"
#include "string"
#include <fstream> 
#include <iostream> 


using namespace std; 

int main(int argc, char *argv[]) {
    
    minMaxHeap heapArray; 

    /*
    heapArray.insert(1);
    heapArray.insert(4);
    heapArray.insert(8);
    heapArray.insert(15);
    heapArray.insert(21);
    heapArray.insert(41);
    heapArray.insert(83);
    heapArray.insert(165);
    heapArray.insert(331);
    */


    ifstream textFile; 
    textFile.open("/autograder/submission/PA2_dataset.txt"); 
    //textFile.open("PA2_dataset.txt");
    char charNum[100];
    int count; 

    if (textFile.fail()) {
        std::cerr << "Could not open file 'PA2_dataset.txt.'";
        exit(1); 
    }

    while (!textFile.eof() && !textFile.fail() && count <= 10000) {
        count++; 
        textFile >> charNum; 
        int charToNum = stoi(charNum); 

        heapArray.insert(charToNum); 
    }
    textFile.close();


    string argument = argv[1] ; 
    string::iterator it = argument.begin(); 
    string subword, sub;  
    vector<string> commands; 

    for (it; it != argument.end(); it++) {
        if (subword.length() > 5)
            sub = subword.substr(subword.length() - 4, 4);  
        if (subword == "printHeap" || subword == "getMin" || subword == "getMax" || subword == "insert" ||
            subword == "deleteMin" || subword == "deleteMax") {
            commands.push_back(subword); 
            subword.clear();  
        }
        else {
            if(*it == ',') {
                commands.push_back(subword); 
                subword.clear(); 
                it++; 
            }
            else if (*it ==' ') {
                continue;
            }
            else 
                subword += *it; 
        }
    }
    commands.push_back(subword); 

    /*
    for (int i = 0; i < commands.size(); i++) {
        cout << commands[i] << endl; 
    }
    */

    for (int vecIt = 0; vecIt < commands.size(); vecIt++) {  
        if (commands[vecIt] == "printHeap") {
            heapArray.printHeap(); 
        }
        else if (commands[vecIt] == "getMin") {
           heapArray.getMin(); 
        }
        else if (commands[vecIt] == "getMax") {
           heapArray.getMax(); 
        }
        else if (commands[vecIt] == "insert") {
            heapArray.insertNew(stoi(commands[vecIt + 1])); 
        }
        else if (commands[vecIt] == "deleteMin") {
            heapArray.deleteMin(); 
        }
        else if (commands[vecIt] == "deleteMax") {
            heapArray.deleteMax(); 
        }
    }

}