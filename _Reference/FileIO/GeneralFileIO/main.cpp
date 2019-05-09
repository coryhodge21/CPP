//
//  main.cpp
//  KonradProgram
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    //store data in a string (char array)
    char charDataArr[100];
    
    // open a file in write mode.
    ofstream fileHandle;
    fileHandle.open("afile.dat");   // <-   ?.dat
    
    //get info from user and store in charDataArr
    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(charDataArr, 100);
    
    // write inputted data into the file.
    fileHandle << charDataArr << endl;
    
    //get more input from user and store in charDataArr
    cout << "Enter your age: ";
    cin >> charDataArr;
    //discards unused charachters from charDataArr
    cin.ignore();
    
    // again write inputted data into the file.
    fileHandle << charDataArr << endl;
    
    // close the opened file.
    fileHandle.close();
    
    
    
    
    
    //create array to store data gathered from file charDataArray
    char charDataArray[100];
    
    // open a file in read mode.
    ifstream file2ReadHandle;
    file2ReadHandle.open("afile.dat");  // <-   ?.dat
    
    //display warning
    cout << "Reading from the file" << endl;
    
    //put data from fileHandle into charDataArray for display
    file2ReadHandle >> charDataArray;
    
    // write the data at the screen.
    cout << charDataArray << endl;
    
    // again read the data from the file and display it.
    file2ReadHandle >> charDataArray;
    cout << charDataArray << endl;
    
    // close the opened file.
    file2ReadHandle.close();

    
    cout << "\n\n\n";
    return 0;
}
