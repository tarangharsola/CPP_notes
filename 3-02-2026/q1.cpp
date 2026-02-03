/*
Problem Statement:
You are given a single input line representing a student record in the following format:

<Full Name> | <Age> | <City> | <Course Code>

Example Input:
Rohit Kumar Sharma | 21 | Hyderabad | CSE101

Write a C++ program to perform the following operations using std::string methods.

Tasks:

1. Read the complete input line using getline.

2. Extract the following fields from the input string:

  Full Name
  Age
  City
  Course Code
     (Use appropriate string methods such as searching and substring extraction.)

3. Display the length of the full name.

4. Display the first and last character of the full name.

5. Convert the age from string format to integer and display it.

6. Append the course code to the city name using a hyphen as shown below:
   City-CourseCode
   Example: Hyderabad-CSE101

7. Replace all spaces in the full name with underscores.
   Example: Rohit_Kumar_Sharma

8. Check whether the course code contains the substring "CSE" and display an appropriate message.

9. Clear the course code string and verify whether it is empty.

10. Convert the age back to string format and append the word " years" to it.

11. Convert the final processed name into a C-style string and display it.

Sample Output (format may vary):

Name Length: 20
First Character: R
Last Character: a
Age (int): 21
City + Course: Hyderabad-CSE101
Processed Name: Rohit_Kumar_Sharma
CSE course detected
Course cleared successfully
Age as string: 21 years
C-style name: Rohit_Kumar_Sharma


*/