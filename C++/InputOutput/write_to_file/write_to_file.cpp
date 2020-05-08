/*
This code writes command line input a text file
*/

#include <iostream>
#include <fstream>//File i/o

using namespace std;

int main(int argc, const char *argv[]){
    //Make sure the correct number of command line args are given
    if(argc !=1){
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    int num;
    cout << "How many lines will you write? ";
    cin >> num;

    ofstream myfile;
    myfile.open("test.txt");
    cout<<"Enter "<<num<< " lines of data below: "<<endl;
    string line;
    while(num!=0){
        cin >> line;
        myfile << line << "\n";
        num--;
    }
    myfile.close();
    return 0; //done so return 0
}