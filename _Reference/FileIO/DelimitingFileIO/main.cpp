//
//  main.cpp
//  readFileMixedDataSave
//
//  Created by Cory on 7/20/17.
//  Copyright © 2017 Cory. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[]) {
    
    //local Varibales
    string buffer;
    string dataArray[20];

    
    //Open File
    ifstream fileHandle;
    fileHandle.open("data.txt");
    
    
    //Display funciton working
    cout<< "Reading the file\n";
    
    //counter for reading
    int i = 0;
    
    //grab first line
    while( getline(fileHandle, buffer)){
        
        //convert buffer to string streeam ss
        stringstream ss(buffer);
        
        //grab elements comma seperated
        while(getline(ss, buffer, ',')){
            
            //store contents of ss into intArray
            dataArray[i] = buffer;
            
            //display contents of array
            cout << "dataArray["<< i << "]: " << dataArray[i] << "\n";
            
            //inc index
            i++;
        
        }
    }
    
    //convert first char aray to an int array
    
    
    //add integers in incriments off 3
    
    
    //display each string in the stringArray of arrays
    //  the number off times corolating to its position
    
    
    
    
    return 0;
}
