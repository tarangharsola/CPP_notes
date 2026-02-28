<div align="center">

# Data Structure Notes(CPP)

</div>

- CPP is used for building Performance critical System
- It brings speed + control 

---

## C++ EXECUTION MODEL

### Compilation Process

C++ source code is compiled into machine code before execution. The CPU executes this machine code directly, without any intermediate layer.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello C++";
    return 0;
}
```

---

### Compile-Time Translation

All type checking and code generation happen at compile time. There is no runtime translation.

```cpp
int x = 10;   // resolved at compile time
```

---

## COMPARISON WITH JAVA AND PYTHON

### Execution Model Comparison

| Feature          | C++      | Java      | Python |
| ---------------- | -------- | --------- | ------ |
| Interpreter      | No       | No        | Yes    |
| Virtual Machine  | No       | Yes (JVM) | No     |
| Bytecode         | No       | Yes       | No     |
| Runtime Overhead | Very Low | Medium    | High   |

---

### Performance Advantage

C++ executes native machine code, which makes it faster and more predictable than Java and Python.

```cpp
int multiply(int a, int b) {
    return a * b;
}
```

---

## TYPE CHECKING

### Compile-Time Type Checking

C++ detects type errors during compilation, reducing runtime failures.

```cpp
int a = 10;
// a = "hello";   // compile-time error
```

---

### Type Checking Comparison

| Language | Type Checking Time |
| -------- | ------------------ |
| C++      | Compile time       |
| Java     | Compile + Runtime  |
| Python   | Runtime            |

---

## MEMORY MANAGEMENT

### No Garbage Collection

C++ does not provide garbage collection. Memory management is explicitly handled by the programmer.

```cpp
int* p = new int(5);
delete p;
```

---

### Garbage Collection Comparison

| Feature               | C++ | Java / Python |
| --------------------- | --- | ------------- |
| Garbage Collector     | No  | Yes           |
| Manual memory control | Yes | No            |
| Runtime pauses        | No  | Yes           |

---

### Stack vs Heap

C++ allows control over stack and heap memory usage.

```cpp
int x = 10;           // stack
int* y = new int(20); // heap
```

---

### Stack vs Heap Comparison

| Aspect     | Stack       | Heap                  |
| ---------- | ----------- | --------------------- |
| Allocation | Automatic   | Manual                |
| Speed      | Fast        | Slower                |
| Lifetime   | Scope-based | Programmer-controlled |

---

## RUNTIME BEHAVIOR

### Minimal Runtime Overhead

C++ avoids garbage collection, dynamic typing, and background runtime services.

```cpp
int square(int x) {
    return x * x;
}
```

---

### Deterministic Execution

Resources are released at well-defined points in the program.

```cpp
void func() {
    int a = 10;
} // destroyed when scope ends
```

---

## RAII (RESOURCE ACQUISITION IS INITIALIZATION)

### RAII Concept

Resources are acquired during object initialization and released automatically when the object goes out of scope.

```cpp
#include <fstream>

void writeFile() {
    std::ofstream file("data.txt");
    file << "Hello";
} // file closed automatically
```

---

### RAII vs Garbage Collection

| Feature        | RAII (C++)    | Garbage Collection |
| -------------- | ------------- | ------------------ |
| Cleanup timing | Deterministic | Unpredictable      |
| Scope-based    | Yes           | No                 |
| Real-time safe | Yes           | No                 |

---

## MEMORY LAYOUT

### Class and Struct Size

The actual size of a class or struct may be larger than the sum of its members due to padding and alignment.

```cpp
class Student {
    int age;
    char gender;
};
```

---

### Struct Member Ordering

Placing larger data types first reduces padding and improves memory efficiency.

```cpp
struct Good {
    int i;
    char c;
};

struct Bad {
    char c;
    int i;
};
```

---

### Struct Ordering Comparison

| Order         | Padding | Memory Efficiency |
| ------------- | ------- | ----------------- |
| Large → Small | Less    | Better            |
| Small → Large | More    | Worse             |

---

## HEADER FILES

### Purpose of Header Files

Header files contain declarations and are included during compilation. Their contents are copied into the source file.

```cpp
#include <iostream>
```

---

## NAMESPACES

### Purpose of Namespaces

Namespaces prevent name conflicts between libraries or modules.

```cpp
namespace A {
    int value = 10;
}

namespace B {
    int value = 20;
}
```

---

### Scope Resolution Operator `::`

Used to access namespace members, class members, and global variables.

```cpp
std::cout << A::value;
```
___
```cpp
#include <iostream>
using namespace std;

namespace A {
    int value = 10;
}

namespace B {
    int value = 20;
}

int main() {
    cout << A::value << "\n";  // Access value from namespace A
    cout << B::value << "\n";  // Access value from namespace B
    return 0;
}
```
---

## POINTERS AND REFERENCES

### Pointers

Pointers store the address of a variable.

```cpp
int x = 10;
int* p = &x;
```

---

### Pointer Arithmetic

Pointer increments depend on the size of the data type.

```cpp
int arr[3];
int* p = arr;
p++;   // moves by sizeof(int)
```

---

### References

References act as aliases for existing variables.

```cpp
int a = 10;
int& ref = a;
```

---

### Pointer vs Reference

| Feature           | Pointer  | Reference |
| ----------------- | -------- | --------- |
| Can be null       | Yes      | No        |
| Can be reassigned | Yes      | No        |
| Dereferencing     | Required | Automatic |

---

## `this` POINTER

### Meaning of `this`

The `this` pointer stores the address of the current object.

```cpp
class Demo {
public:
    void show() {
        std::cout << this;
    }
};
```

---

## ADVANTAGES OF C++

### Why C++

C++ offers high performance, deterministic execution, direct memory control, and is ideal for system-level and real-time applications.

---
- for further clarity on above topic pls visit these [notes](./31-1-2026/). 
--- 
# Arrays- 
### methods - 
- 2 pointers 
- sliding window 
-
- 
___
# Questions - 
## Reverse of an array - 
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int i = 0, j = n - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    return 0;
}
```
___
## reversing group of k consicutive elements - 
```cpp
#include <iostream>
using namespace std;

void reverseK(int arr[], int n, int k) {
    for (int i = 0; i + k <= n; i += k) {
        int left = i;
        int right = i + k - 1;

        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    int k = 5;

    reverseK(arr, n, k);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

```
 ### Output - 
```
5 4 3 2 1 6 7 8 9
```
# String - 
- Header - 
```cpp
#include <string>
```
- Declaration -
```cpp
string s = "Hello World";
```
for string methods and questions refer [here](./3-02-2026/)
---
## Rotation of Array - 
Rotations can be done in 2 ways. They are - 
- left shift 
- right shift 
___
It can be done in 3 way. they are - 
- swapping 
- creation of new array and play with  indexes
- reverse of array 

questions on these topics are [here](./5-2-2026/)
___
# OOPS in CPP - 
- for notes and question go [here](./7%20-%202%20-%202026/)
---
## Operator overloading- 
### What is operator overloading and why is it important for data structure ??
- Operator overloading is the ability to redefine the behavior of built-in operators for user-defined types (classes/structs). Instead of calling a method explicitly, you can use natural syntax with your custom objects. Its important because it helps in making the code more accessible to read and make custom methods(sort,compare,etc).
- for question on this topic refer [here](./12-02-2026/).
- in the above code we have been given operator overloading for ++ and many other we need to do for other like --(both post and pre).

- private members of a class cannot be accessed outside the class.
- in C++ in order to access private members of class i have to declare a friend function. 
- a freind function needs to abstract inside the class.
- the implementation of friend function needs to be outside the class.
- while implimenting the function you will omit the keyword "friend".
## Vectors - 
for question on vector refer [here](./12-02-2026/vector/).
___
# Virtual function - 
- it enables runtime polymorphism in cpp.
## What is polymorphism ? 
- The word polymorphism means having many forms. 
- in java its method overloading and method overriding 
---
- questions on virtaul function are [here](./14-02-2026/)
---
## Linked List - 
- A linked list is defined as a collection of nodes where each node consists of two members which represents its value and a next/previous pointer which stores the address for the next/previous node.
# Printing of linked list(varios operations on them) - 
```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    float cgpa;
    Student* next;

    Student(string n, int r, float c) {
        name = n;
        rollNumber = r;
        cgpa = c;
        next = nullptr;
    }
};

void printList(Student* head) {
    Student* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name
             << ", Roll: " << temp->rollNumber
             << ", CGPA: " << temp->cgpa << endl;
        temp = temp->next;
    }
}

void addAtStart(Student* &head, string name, int roll, float cgpa) {
    Student* newNode = new Student(name, roll, cgpa);
    newNode->next = head;
    head = newNode;
}

void addAtEnd(Student* &head, string name, int roll, float cgpa) {
    Student* newNode = new Student(name, roll, cgpa);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Student* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void insertAfter(Student* head, int targetRoll, string name, int roll, float cgpa) {
    Student* temp = head;

    while (temp != nullptr && temp->rollNumber != targetRoll)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Roll number not found!" << endl;
        return;
    }

    Student* newNode = new Student(name, roll, cgpa);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(Student* &head, int targetRoll, string name, int roll, float cgpa) {

    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->rollNumber == targetRoll) {
        Student* newNode = new Student(name, roll, cgpa);
        newNode->next = head;
        head = newNode;
        return;
    }

    Student* temp = head;
    Student* prev = nullptr;

    while (temp != nullptr && temp->rollNumber != targetRoll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Roll number not found!" << endl;
        return;
    }

    Student* newNode = new Student(name, roll, cgpa);
    prev->next = newNode;
    newNode->next = temp;
}

void deleteAtStart(Student* &head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Student* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Student* &head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Student* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void deleteByRoll(Student* &head, int targetRoll) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->rollNumber == targetRoll) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Student* temp = head;
    Student* prev = nullptr;

    while (temp != nullptr && temp->rollNumber != targetRoll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Roll number not found!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}
int main() {

    Student* s1 = new Student("Ram",101,8.5);
    Student* s2 = new Student("Shyam",102,9.5);
    Student* s3 = new Student("Sita",103,8.7);
    Student* s4 = new Student("Gita",104,9.2);

    s1->next = s2;
    s2->next = s3;
    s3->next = s4;

    Student* head = s1;

    cout << "Original List:\n";
    printList(head);

    cout << endl << "After adding at end:" << endl;
    addAtEnd(head,"Ramesh",105,9.0);
    printList(head);

    cout << endl << "After adding at start:" << endl;
    addAtStart(head, "Krishna", 100, 9.8);
    printList(head);

    cout << endl << "After inserting AFTER Roll 102:" << endl;
    insertAfter(head,102,"Arjun",106,8.9);
    printList(head);

    cout << endl << "After inserting BEFORE Roll 101:" << endl;
    insertBefore(head,101,"Mohan",99,9.3);
    printList(head);
    
    cout << endl << "After deleting at start:" << endl;
    deleteAtStart(head);
    printList(head);

    cout << endl << "After deleting at end:" << endl;
    deleteAtEnd(head);
    printList(head);

    cout << endl << "After deleting Roll 102:" << endl;
    deleteByRoll(head,102);
    printList(head);


    return 0;
}
```
- questions on single linked list are [here](./24-02-2026/q1.cpp)
## Double linked list - 
```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    float cgpa;
    Student* next;
    Student* prev;

    Student(string n, int r, float c) {
        name = n;
        rollNumber = r;
        cgpa = c;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(Student* head) {
    Student* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Roll: " << temp->rollNumber << ", CGPA: " << temp->cgpa << endl;
        temp = temp->next;
    }
}

void addAtStart(Student* &head, string name, int roll, float cgpa) {
    Student* newNode = new Student(name, roll, cgpa);
    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
}

void addAtEnd(Student* &head, string name, int roll, float cgpa) {
    Student* newNode = new Student(name, roll, cgpa);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Student* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(Student* head, int targetRoll, string name, int roll, float cgpa) {
    Student* temp = head;
    while (temp != nullptr && temp->rollNumber != targetRoll)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Roll number not found!" << endl;
        return;
    }
    Student* newNode = new Student(name, roll, cgpa);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertBefore(Student* &head, int targetRoll, string name, int roll, float cgpa) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Student* temp = head;
    while (temp != nullptr && temp->rollNumber != targetRoll)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Roll number not found!" << endl;
        return;
    }
    Student* newNode = new Student(name, roll, cgpa);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != nullptr)
        temp->prev->next = newNode;
    else
        head = newNode;  // inserting before head
    temp->prev = newNode;
}

void deleteAtStart(Student* &head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Student* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}

void deleteAtEnd(Student* &head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Student* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void deleteByRoll(Student* &head, int targetRoll) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Student* temp = head;
    while (temp != nullptr && temp->rollNumber != targetRoll)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Roll number not found!" << endl;
        return;
    }
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;  // deleting head node
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    delete temp;
}

int main() {
    Student* s1 = new Student("Ram", 101, 8.5);
    Student* s2 = new Student("Shyam", 102, 9.5);
    Student* s3 = new Student("Sita", 103, 8.7);
    Student* s4 = new Student("Gita", 104, 9.2);

    // Linking nodes with both next and prev
    s1->next = s2; s2->prev = s1;
    s2->next = s3; s3->prev = s2;
    s3->next = s4; s4->prev = s3;

    Student* head = s1;

    cout << "Original List:\n";
    printList(head);

    cout << "\nAfter adding at end:\n";
    addAtEnd(head, "Ramesh", 105, 9.0);
    printList(head);

    cout << "\nAfter adding at start:\n";
    addAtStart(head, "Krishna", 100, 9.8);
    printList(head);

    cout << "\nAfter inserting AFTER Roll 102:\n";
    insertAfter(head, 102, "Arjun", 106, 8.9);
    printList(head);

    cout << "\nAfter inserting BEFORE Roll 101:\n";
    insertBefore(head, 101, "Mohan", 99, 9.3);
    printList(head);

    cout << "\nAfter deleting at start:\n";
    deleteAtStart(head);
    printList(head);

    cout << "\nAfter deleting at end:\n";
    deleteAtEnd(head);
    printList(head);

    cout << "\nAfter deleting Roll 102:\n";
    deleteByRoll(head, 102);
    printList(head);

    return 0;
}
```
## `map` and `set` 
---

### `set` — Collection of Unique Keys

Think of it as a **sorted bag where duplicates are rejected**.

```cpp
#include <set>
set<int> s;

s.insert(5);
s.insert(3);
s.insert(5);  // ignored, already exists
s.insert(1);

// s = {1, 3, 5}  → always sorted
```

**Internals:** Red-Black Tree (self-balancing BST)
- Every element is a **node in the tree**
- Automatically sorted on insertion
- No random access (`s[0]` ❌)

---

### `map` — Key-Value pairs with Unique Sorted Keys

Think of it as a **sorted dictionary**.

```cpp
#include <map>
map<string, int> m;

m["Alice"] = 95;
m["Bob"]   = 87;
m["Alice"] = 50;  // overwrites, doesn't duplicate

// m = { {Alice,50}, {Bob,87} }  → sorted by key
```

**Internals:** Also a Red-Black Tree, but each node stores a **pair(key, value)**

---

### Key Differences — `map` vs `set`

| Feature | `set` | `map` |
|---|---|---|
| Stores | only keys | key + value |
| Use case | membership check | lookup/dictionary |
| Access | `s.count(x)` | `m[key]`, `m.at(key)` |
| Duplicates | ❌ | ❌ (keys unique) |

---

### Important Methods

```cpp
set<int> s = {1, 2, 3, 4, 5};

s.insert(6);          // add element
s.erase(3);           // remove element
s.count(2);           // 1 if exists, 0 if not
s.find(2);            // iterator to element or s.end()
s.size();             // number of elements
s.empty();            // true if empty
s.clear();            // remove all

// Range queries (very powerful!)
s.lower_bound(3);     // iterator to first element >= 3
s.upper_bound(3);     // iterator to first element > 3
```

```cpp
map<string,int> m;

m["key"] = 10;        // insert or overwrite
m.at("key");          // throws if key missing (safe)
m.count("key");       // 1 or 0
m.find("key");        // iterator or m.end()
m.erase("key");       // remove by key
```

---

### `m["key"]` vs `m.at("key")`

```cpp
map<string,int> m;
m["Alice"] = 95;

cout << m["Bob"];     // ⚠️ inserts Bob with value 0 !
cout << m.at("Bob");  // ✅ throws std::out_of_range
```
> Always use `m.find()` or `m.count()` before accessing an uncertain key.

---

### Practical Example — using both together

```cpp
// Count frequency, then find chars appearing more than once
string s = "hello";
map<char,int> freq;

for(char c : s) freq[c]++;

set<char> duplicates;
for(auto &[key,val] : freq)
    if(val > 1) duplicates.insert(key);

// duplicates = {'l'}
```

---

### When to use what?

| Situation | Use |
|---|---|
| Just check if something exists | `set` |
| Store key → value mapping | `map` |
| Need sorted order | `map` or `set` |
| Need fast O(1) lookup, don't care about order | `unordered_map` / `unordered_set` |
| Need min/max quickly | `set` → `*s.begin()` / `*s.rbegin()` |

---

# Recursion -
## Iteration vs Recursion

---

### The Core Idea

**Iteration** — repeat using loops, you control the cycle explicitly
**Recursion** — function calls **itself**, you use it when you are unsure of the answer . Navigation through call stack becomes easy

---

### Same Problem, Both Ways — Factorial

**Iterative:**
```cpp
int factorial(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}
```

**Recursive:**
```cpp
int factorial(int n){
    if(n == 0) return 1;  // base case
    return n * factorial(n-1);  // recursive call
}
```

---

### What happens in memory?

**Iteration** — uses a fixed amount of memory, loop just updates variables:
```
factorial(5):
result = 1 → 2 → 6 → 24 → 120
```

**Recursion** — each call is pushed onto the **call stack**:
```
factorial(5)
  factorial(4)
    factorial(3)
      factorial(2)
        factorial(1)
          factorial(0) → returns 1
        returns 1
      returns 2
    returns 6
  returns 24
returns 120
```
Every function call waits for the next one to finish — stack builds up and unwinds.

---

### Key Differences

| | Iteration | Recursion |
|---|---|---|
| Uses | loops (`for`, `while`) | function calls itself |
| Memory | O(1) — fixed | O(n) — call stack grows |
| Speed | faster (no function call overhead) | slightly slower |
| Termination | loop condition | base case |
| Infinite loop risk | `while(true)` | stack overflow |
| Code simplicity | can get complex | often cleaner & elegant |
| Best for | simple repetition | tree/graph problems, divide & conquer |

---

### Recursion needs TWO things

```cpp
int factorial(int n){
    if(n == 0) return 1;       // 1. BASE CASE — stops recursion
    return n * factorial(n-1); // 2. RECURSIVE CASE — moves toward base case
}
```

Missing the base case → **infinite recursion → stack overflow crash**

---

### Where Recursion shines

Problems that are **naturally recursive** — trees, graphs, divide & conquer:

```cpp
// Fibonacci
int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

// Binary Search
int binarySearch(int arr[], int l, int r, int target){
    if(l > r) return -1;
    int mid = (l + r) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) return binarySearch(arr, l, mid-1, target);
    return binarySearch(arr, mid+1, r, target);
}
```

Doing binary search iteratively is possible but less intuitive.

---

### Stack Overflow — Recursion's danger

```cpp
void infinite(int n){
    return infinite(n+1);  // no base case → CRASH
}
```

Each call adds a **stack frame** — memory runs out → **Stack Overflow**

---