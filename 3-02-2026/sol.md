## Q1 
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Read the complete input line
    string input;
    getline(cin, input);

    // Variables to store extracted fields
    string fullName, ageStr, city, courseCode;

    // 2. Extract fields using string methods
    int pos1 = input.find('|');
    int pos2 = input.find('|', pos1 + 1);
    int pos3 = input.find('|', pos2 + 1);

    fullName = input.substr(0, pos1 - 1);
    ageStr = input.substr(pos1 + 2, pos2 - pos1 - 3);
    city = input.substr(pos2 + 2, pos3 - pos2 - 3);
    courseCode = input.substr(pos3 + 2);

    // 3. Display length of full name
    cout << "Name Length: " << fullName.length() << endl;

    // 4. Display first and last character of full name
    cout << "First Character: " << fullName.front() << endl;
    cout << "Last Character: " << fullName.back() << endl;

    // 5. Convert age string to integer
    int age = stoi(ageStr);
    cout << "Age (int): " << age << endl;

    // 6. Append course code to city
    string cityCourse = city + "-" + courseCode;
    cout << "City + Course: " << cityCourse << endl;

    // 7. Replace spaces in full name with underscores
    for (char &c : fullName) {
        if (c == ' ')
            c = '_';
    }
    cout << "Processed Name: " << fullName << endl;

    // 8. Check if course code contains "CSE"
    if (courseCode.find("CSE") != string::npos) {
        cout << "CSE course detected" << endl;
    } else {
        cout << "CSE course not detected" << endl;
    }

    // 9. Clear course code and verify
    courseCode.clear();
    if (courseCode.empty()) {
        cout << "Course cleared successfully" << endl;
    }

    // 10. Convert age back to string and append " years"
    string ageWithText = to_string(age) + " years";
    cout << "Age as string: " << ageWithText << endl;

    // 11. Convert processed name to C-style string
    const char* cStyleName = fullName.c_str();
    cout << "C-style name: " << cStyleName << endl;

    return 0;
}
```
## Q2 
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string result = "";
    int i = s.length() - 1;

    while (i >= 0) {
        // Skip spaces
        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        string word = "";

        // Collect characters of a word
        while (i >= 0 && s[i] != ' ') {
            word = s[i] + word;
            i--;
        }

        // Append word to result
        if (!result.empty())
            result += " ";
        result += word;
    }

    cout << result;
    return 0;
}
```
# Q3
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string result = "";
    string word = "";

    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {
            // Reverse the current word
            for (int j = word.length() - 1; j >= 0; j--) {
                result += word[j];
            }

            // Add space if not end of string
            if (i < s.length())
                result += " ";

            word = "";
        } else {
            word += s[i];
        }
    }

    cout << result;
    return 0;
}
```