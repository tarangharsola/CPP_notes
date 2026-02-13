#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};
    
    // Accessing using operator[]
    cout << "Element at index 2 using []: " << v[2] << endl;
    
    // Accessing using at()
    cout << "Element at index 3 using at(): " << v.at(3) << endl;
    
    // Uncommenting the next line will throw an 
    // out_of_range exception 
    // cout v.at(10)<<endl;
    return 0;
}