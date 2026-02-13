#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> v = {'a', 'f', 'd'};
  
  	// Inserting 'z' at the back
  	v.push_back('z');
  
  	// Inserting 'c' at index 1
  	v.insert(v.begin() + 1, 'c');

  	for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}