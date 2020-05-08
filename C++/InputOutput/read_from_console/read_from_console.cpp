/*
This code reads from the command line and prints it back on command line
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num;
    cout << "How many lines will you write? ";
    cin >> num;
    int temp = num;
    cout<<"Enter "<<num<< " lines of data below: "<<endl;
    string line;
    vector<string> vec;
    while(temp!=0){
        cin >> line;
        vec.push_back(line);
        temp--;
    }

    cout<<"Here is your data: "<<endl;
    int i = 0;
    while(i < num){
        cout<<vec[i]<<endl;
        i++;
    }

    return 0; //done so return 0
}