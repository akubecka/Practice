/*
This code reads from a text file and prints it on command line
*/

#include <iostream>
#include <fstream>//File i/o

using namespace std;

int main(int argc, const char *argv[]){
    //Make sure the correct number of command line args are given
    if(argc !=2){
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    //Create ifstream object
    ifstream input_file(argv[1]);
    //If it does not exist, error
    if(!input_file){
        cerr << "Error: Cannot open file '" << argv[1] << "'." << endl;
        return 1;
    }

    //Add read errors to the list of exceptions the ifstream will handle
    input_file.exceptions(ifstream::badbit); //don't worry about this

    //Time to actually get the data
    string line;
    try{
        unsigned int line_number = 1;
        //Use getline to read in a line, it gets a line and sticks the string into "line" in this case
        while(getline(input_file, line)){
            cout << line_number << ":\t" << line << endl; //Print line_number:    line string
            ++line_number; //increment line_number by 1
        }
        input_file.close(); //We are done reading so close the file
    }catch(const ifstream::failure &f){//Throw error if invalid data(this should never really happen)
        cerr << "Error: An I/O error occured reading '" << argv[1] << "'.";
        return 1;
    }

    return 0; //done so return 0
}