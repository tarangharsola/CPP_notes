#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int>v;
    
    // Check if the vector is empty
    if(v.empty()){
        cout<<"Vector is empty."<<endl;
    }
    
    // Add an element
    v.push_back(100);
    if(!v.empty()){
        cout<<"Vector is not empty. First element "<<v[0]<<endl;
    }
    return 0;
}