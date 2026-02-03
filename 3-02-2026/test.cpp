#include <iostream>
#include <string>
using namespace std;

int main() {

    // Declaration & Initialization
    string s1 = "Hello";
    string s2("World");
    string s3 = s1 + " " + s2;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // Size & Capacity
    cout << "\nSize of s3: " << s3.size() << endl;
    cout << "Length of s3: " << s3.length() << endl;
    cout << "Is s3 empty? " << s3.empty() << endl;
    cout << "Capacity of s3: " << s3.capacity() << endl;

    // Access characters
    cout << "\nFirst char: " << s3.front() << endl;
    cout << "Last char: " << s3.back() << endl;
    cout << "Char at index 1: " << s3.at(1) << endl;

    // Modify string
    s3.append("!");
    cout << "\nAfter append: " << s3 << endl;

    s3.push_back('?');
    cout << "After push_back: " << s3 << endl;

    s3.pop_back();
    cout << "After pop_back: " << s3 << endl;

    // Insert & Erase
    s3.insert(5, " C++");
    cout << "\nAfter insert: " << s3 << endl;

    s3.erase(5, 4);
    cout << "After erase: " << s3 << endl;

    // Substring
    string sub = s3.substr(0, 5);
    cout << "\nSubstring (0,5): " << sub << endl;

    // Find operations
    size_t pos = s3.find("World");
    if (pos != string::npos)
        cout << "\n'World' found at position: " << pos << endl;

    // Replace
    s3.replace(6, 5, "Everyone");
    cout << "\nAfter replace: " << s3 << endl;

    // Comparison
    string a = "Apple";
    string b = "Banana";

    if (a.compare(b) < 0)
        cout << "\nApple comes before Banana" << endl;

    // Clear string
    string temp = "Temporary";
    temp.clear();
    cout << "\nAfter clear, is temp empty? " << temp.empty() << endl;

    //Input with spaces
    string name;
    cout << "\nEnter your full name: ";
    getline(cin, name);
    cout << "You entered: " << name << endl;

    //String Number conversion
    string numStr = "123";
    int num = stoi(numStr);
    cout << "\nString to int: " << num << endl;

    int x = 456;
    string strNum = to_string(x);
    cout << "Int to string: " << strNum << endl;

    //C-style string conversion
    const char* cstr = s3.c_str();
    cout << "\nC-style string: " << cstr << endl;

    return 0;
}