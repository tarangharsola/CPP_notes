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
- Recursion are of 3 type - head , tail and branch(will be discussed later).
---

### Head Recursion

The recursive call happens **before** any processing — the function calls itself first, then does work on the way **back up**.

```cpp
void head(int n){
    if(n == 0) return;  // base case
    head(n-1);          // recursive call FIRST
    cout << n << " ";   // work happens AFTER
}

head(5);
// Output: 1 2 3 4 5
```

**Call stack:**
```
head(5) → head(4) → head(3) → head(2) → head(1) → head(0)
                                                    returns
                                         prints 1
                              prints 2
                   prints 3
        prints 4
prints 5
```
Work happens on the way **back up** — so output is in reverse of call order.

---

### Tail Recursion

The recursive call happens **after** all processing — it's the **last thing** the function does.

```cpp
void tail(int n){
    if(n == 0) return;  // base case
    cout << n << " ";   // work happens FIRST
    tail(n-1);          // recursive call LAST
}

tail(5);
// Output: 5 4 3 2 1
```

**Call stack:**
```
tail(5) → prints 5 → tail(4) → prints 4 → tail(3) → ...
```
Work happens on the way **down** — no pending work left when returning.

---

### Key Difference

| | Head Recursion | Tail Recursion |
|---|---|---|
| Recursive call | first | last |
| Work done | on way back (unwinding) | on way down |
| Stack needed | yes, must remember state | can be optimized away |
| Output order | reversed | natural |

---

### Simple way to remember

> **Head** — recurse first, work later → like reading a book backwards
>
> **Tail** — work first, recurse later → like reading normally, no looking back
___
# Stack

- Follows **LIFO** (Last In, First Out) — the last element pushed is the first to be popped
- You cannot traverse through the stack; only the **top element** is accessible at any time
- It is both an **ADT** (Abstract Data Type) and a **Data Structure**

---

## Stack as an ADT (Abstract Data Type)

An ADT defines **what** operations are supported, not **how** they are implemented.
The Stack ADT only specifies the behavior/interface — the internal implementation is hidden.

### ADT Definition

```
ADT Stack:
    Data:
        - A collection of elements in LIFO order

    Operations:
        - push(x)  → inserts x onto the top
        - pop()    → removes the top element
        - top()    → returns the top element without removing
        - empty()  → returns true if stack has no elements
        - size()   → returns the number of elements
```

### Why ADT Matters

- The user only knows **what** the stack does, not **how** it works internally
- The same Stack ADT can be implemented using:
  - **Arrays**
  - **Linked Lists**
  - **Dynamic arrays (vectors)**
- This separation is called **abstraction**

---

## Operations & Time Complexity

| Operation  | Description               | Time Complexity |
|------------|---------------------------|-----------------|
| `push(x)`  | Add element to top        | O(1)            |
| `pop()`    | Remove top element        | O(1)            |
| `top()`    | Access top element        | O(1)            |
| `empty()`  | Check if stack is empty   | O(1)            |
| `size()`   | Return number of elements | O(1)            |
| Traversal  | ❌ Not supported          | —               |

> All core operations are O(1) — this is what makes stacks efficient.

---

## Declaration (STL)

```cpp
#include <stack>

stack<int>    s;  // stack of integers
stack<string> s;  // stack of strings
stack<char>   s;  // stack of characters
```

The STL `stack` is a **template container** — it works with any type, including custom classes:

| Type      | Example                |
|-----------|------------------------|
| Primitive | `stack<int>`           |
| String    | `stack<string>`        |
| Object    | `stack<Student>`       |
| Pointer   | `stack<Student*>`      |
| Pair      | `stack<pair<int,int>>` |
| Vector    | `stack<vector<int>>`   |

---

## Example

```cpp
stack<int> s;

s.push(10);   // stack: [10]
s.push(20);   // stack: [10, 20]
s.push(30);   // stack: [10, 20, 30]

s.top();      // returns 30  (does NOT remove)
s.pop();      // stack: [10, 20]
s.top();      // returns 20

s.size();     // returns 2
s.empty();    // returns false
```

---

## Stack of Objects

You can push any custom class onto a stack just like a primitive type.

```cpp
#include <stack>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) : name(n), age(a) {}
};

int main() {
    stack<Student> s;

    s.push(Student("Alice", 20));
    s.push(Student("Bob", 22));
    s.push(Student("Charlie", 21));

    cout << s.top().name << endl;  // Charlie
    cout << s.top().age  << endl;  // 21

    s.pop();

    cout << s.top().name << endl;  // Bob
}
```

### Accessing Members

Use `.` on `top()` to reach the object's fields:

```cpp
s.top().name;
s.top().age;
```

### Modifying the Top Object

`top()` returns a **reference**, so you can mutate it directly:

```cpp
s.top().age = 25;  // modifies the top Student in-place
```

### Using `emplace()` Instead of `push()`

`emplace()` constructs the object directly in-place — more efficient as it avoids a copy:

```cpp
s.emplace("Diana", 23);  // constructs Student directly onto the stack
```

---

## Stack vs Other Data Structures

| Feature       | Stack     | Queue      | Array     |
|---------------|-----------|------------|-----------|
| Order         | LIFO      | FIFO       | —         |
| Traversal     | ❌        | ❌         | ✅        |
| Insert        | Top only  | Rear only  | Any index |
| Delete        | Top only  | Front only | Any index |
| Random Access | ❌        | ❌         | ✅        |

---

## Use Cases

| Use Case                  | Description                               |
|---------------------------|-------------------------------------------|
| **Undo / Redo**           | Editors push states onto a stack          |
| **Balanced parentheses**  | Checking validity of `{[()]}` expressions |
| **Expression evaluation** | Infix → postfix conversion                |
| **DFS**                   | Depth-First Search in graphs and trees    |
| **Function call stack**   | How recursion works internally            |
| **Browser history**       | Back button uses a stack                  |
| **Syntax parsing**        | Used in compilers                         |
--- 
## what is meant by stack underflow and stack overflow ?
### stack overflow

- when we try to keep doing stack.push() until there is no more space, so that there is no more space to push more elements, we get a stack overflow error.

### stack underflow

- when we try to keep doing stack.pop() until there are no more elements left to remove, we get a stack underflow error.
---
## creation of stack using arrays - 
```cpp
#include<iostream>
using namespace std;

class Stack {
    int* arr;
    int t;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        t = -1;
    }

    void push(int x) {
        if (t == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++t] = x;
        cout << "Pushed: " << x << endl;
    }

    void pop() {
        if (t == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << arr[t--] << endl;
    }

    int top() {
        if (t == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[t];
    }

    bool empty() {
        return t == -1;
    }

    int size() {
        return t + 1;
    }

    void display() {
        if (t == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack (top -> bottom): ";
        for (int i = t; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s(5);

    cout << "empty: " << (s.empty() ? "Yes" : "No") << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "top: " << s.top() << endl;
    cout << "size: " << s.size() << endl;

    s.pop();
    s.pop();

    s.display();

    cout << "empty: " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
```
---
## Queqe - 

### What is a Queue?

A **queue** follows **FIFO** — First In, First Out. Like a line at a counter: first person in, first person out.

---

### Basic Usage (STL `queue`)

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Back:  " << q.back()  << endl; // 30
    cout << "Size:  " << q.size()  << endl; // 3

    q.pop(); // removes 10
    cout << "After pop, Front: " << q.front() << endl; // 20

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
```

---

### All Operations

| Operation | Description | Example |
|-----------|-------------|---------|
| `push(x)` | Add to back | `q.push(5)` |
| `pop()` | Remove from front | `q.pop()` |
| `front()` | View front element | `q.front()` |
| `back()` | View back element | `q.back()` |
| `empty()` | Is queue empty? | `q.empty()` |
| `size()` | Number of elements | `q.size()` |

> ⚠️ `pop()` does **not** return the value — call `front()` before popping if you need it.

---

### Types of Queues in STL

**1. Simple Queue**
```cpp
queue<int> q;
q.push(1); q.push(2);
q.pop(); // removes 1
```

**2. Deque** — push/pop from **both ends**
```cpp
#include <deque>
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

**3. Priority Queue** — highest value comes out first
```cpp
priority_queue<int> pq;       // max-heap (default)
pq.push(5); pq.push(9); pq.push(1);
cout << pq.top(); // 9

// Min-heap — lowest value first
priority_queue<int, vector<int>, greater<int>> minPQ;
```

---
## creation of queqe using arrays - 
```cpp
#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    void push(int val) {
        if (rear == 100) { cout << "Queue is full!\n"; return; }
        arr[rear++] = val;
    }

    void pop() {
        if (front == rear) { cout << "Queue is empty!\n"; return; }
        front++;
    }

    int getFront() { return arr[front]; }
    int getBack()  { return arr[rear - 1]; }
    bool empty()   { return front == rear; }
    int size()     { return rear - front; }

    void display() {
        for (int i = front; i < rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();                              // 10 20 30
    cout << "Front: " << q.getFront() << endl; // 10
    cout << "Back:  " << q.getBack()  << endl; // 30

    q.pop();
    q.display();                              // 20 30
}
```
___
## Queue - 
- It follows the the principle of **FIFO** - **F**irst **I**n , **F**irst **O**ut.
### Making of Queue using vector- 
```cpp
#include <iostream>
#include <vector>

using namespace std;

class Queue {
    vector<int> arr; 

public:
    bool isEmpty() {
        return arr.empty(); 
    }

    void enqueue(int data) {
        arr.push_back(data);
        cout << data << " enqueued." << endl;
    }

    int dequeue() {
        if (isEmpty()) { 
            cout << "Queue is empty!\n"; 
            return -1;
        }
        int dequeuedValue = arr.front();
        arr.erase(arr.begin());
        
        cout << dequeuedValue << " dequeued." << endl;
        return dequeuedValue;
    }
    void printQueue() {
        if (isEmpty()) { 
            cout << "Queue is empty!\n"; 
            return; 
        }
        cout << "Current Queue: ";
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q; 
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.printQueue();                                 
    cout << "Is Empty: " << (q.isEmpty() ? "True" : "False") << endl;      
    return 0;
}
```
### Making of Queue using single linked list- 
```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << data << " enqueued." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        
        Node* temp = front;
        int dequeuedValue = temp->data;
        
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        
        cout << dequeuedValue << " dequeued." << endl;
        return dequeuedValue;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Current Queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q; 
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.printQueue();                                 
    cout << "Is Empty: " << (q.isEmpty() ? "True" : "False") << endl;      
    return 0;
}
```
___
## Working of a brower - 
### methods(ADT) - 
- go 
- back 
- forward 
--- 
- as we can see this is a clear implimentation of stack 
- similarly we can do for undo and redo. 
## code for browser - 
```cpp
#include <iostream>
#include <stack>
#include <string>

class Browser {
private:
    std::stack<std::string> backStack;
    std::stack<std::string> forwardStack;
    std::string currentPage;

public:
    Browser(const std::string& homepage) : currentPage(homepage) {
        std::cout << "Opened: " << currentPage << "\n";
    }
    void go(const std::string& url) {
        backStack.push(currentPage);
        while (!forwardStack.empty())
            forwardStack.pop();
        currentPage = url;
        std::cout << "Navigated to: " << currentPage << "\n";
    }

    void back() {
        if (backStack.empty()) {
            std::cout << "Nothing to go back to.\n";
            return;
        }
        forwardStack.push(currentPage);    
        currentPage = backStack.top();
        backStack.pop();
        std::cout << "Back to: " << currentPage << "\n";
    }
    void forward() {
        if (forwardStack.empty()) {
            std::cout << "Nothing to go forward to.\n";
            return;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();
        std::cout << "Forward to: " << currentPage << "\n";
    }

    void current() {
        std::cout << "Current page: " << currentPage << "\n";
    }
};

int main() {
    Browser b("google.com");
    b.go("github.com");
    b.go("reddit.com");
    b.back();          //  github.com
    b.back();          //  google.com
    b.forward();       //  github.com
    b.go("stackoverflow.com");  // clears forward stack
    b.forward();       // "Nothing to go forward to"
    return 0;
}
```
**note** - I used stack library but we can also manually impliment it. 
- try question number 155,735,844 from leetcode 
---
# Trees - 
- notes on trees are [here](./2-4-2026/DS-UNIT-45.pptx)
### defining tree without map- 
```cpp
#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int value) {
        data = value;
    }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    TreeNode* child1 = new TreeNode(2);
    TreeNode* child2 = new TreeNode(3);
    TreeNode* child3 = new TreeNode(4);
    TreeNode* child4 = new TreeNode(5);
    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);
    child1->addChild(child4);

    return 0;
}
```
### defining tree using map - 
```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TreeNode {
public:
    char data;
    TreeNode(char value) {
        data = value;
    }
};

int main() {
    TreeNode *a = new TreeNode('A');
    TreeNode *b = new TreeNode('B');
    TreeNode *c = new TreeNode('C');
    TreeNode *d = new TreeNode('D');
    TreeNode *e = new TreeNode('E');
    TreeNode *f = new TreeNode('F');
    TreeNode *g = new TreeNode('G');
    TreeNode *h = new TreeNode('H');
    
    map<TreeNode *, vector<TreeNode*>> tree;
    
    tree[a].push_back(b);
    tree[a].push_back(c);
    
    tree[b].push_back(d);
    tree[b].push_back(e);
    
    tree[c].push_back(f);
    
    tree[d].push_back(g);
    tree[d].push_back(h);
    
    return 0;
}
```
## defining binary tree -
```cpp
#include <iostream>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};


int main() {

    TreeNode *a = new TreeNode('A');
    TreeNode *b = new TreeNode('B');
    TreeNode *c = new TreeNode('C');
    TreeNode *d = new TreeNode('D');
    TreeNode *e = new TreeNode('E');
    TreeNode *f = new TreeNode('F');
    TreeNode *g = new TreeNode('G');
    TreeNode *h = new TreeNode('H');
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    d->left = g;
    d->right = h;

    return 0;
}
```
- for all the tree codes discussed on 4th and 7th april are [here](./Tree/)
- for the notes on 9-4-2026 check [here](./09-04-2026/)
## Binary Search Tree - 
```cpp
// C++ Program to implement binary search tree

#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { // If the tree is empty, return a
                           // new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

// Function to do inorder traversal of BST
void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key);
    }

    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // if data is same as root's data, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate the operations of BST
int main()
{

    Node* root = nullptr;
    // create a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search "
            "Tree is: ";
    inorderTraversal(root);
    cout << endl;

    // delete a node in BST
    root = deleteNode(root, 20);
    cout << "After deletion of 20: ";
    inorderTraversal(root);
    cout << endl;

    // Insert a node in BST
    root = insertNode(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout << endl;

    // Search a key in BST
    Node* found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr) {
        cout << "Node 25 found in the BST." << endl;
    }
    else {
        cout << "Node 25 not found in the BST." << endl;
    }

    return 0;
}
```
### output - 
```txt
Inorder traversal of the given Binary Search Tree is: 20 30 40 50 60 70 80 
After deletion of 20: 30 40 50 60 70 80 
After insertion of 25: 25 30 40 50 60 70 80 
Node 25 found in the BST.
```
- note the above code is taken from [GFG](https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/)
- whenever you do inorder traversal of a BST you get sorted values.
- left most node is the smallest node and the right most value is largest node in terms of value. 
### All the type of traversal in a BST - 
```cpp
#include<iostream>
#include<vector>
using namespace std;

class bst{
public:
    int data;
    bst* right;
    bst* left;
};

bst* createNode(int data){
    bst* newNode = new bst();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    cout<<"node created"<<endl;
    return newNode;
}

bst* insertNode(bst* root, int data){
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(bst* root){
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(bst* root){
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(bst* root){
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

void searchNode(bst* root, int key){
    if (root == nullptr){
        cout << "Node " << key << " not found in the BST." << endl;
        return;
    }

    if (root->data == key){
        cout << "Node " << key << " found in the BST." << endl;
        return;
    }

    if (key < root->data){
        searchNode(root->left, key);
    }
    else{
        searchNode(root->right, key);
    }
}

int main(){
    bst* root = nullptr;

    root = insertNode(root,12);
    root = insertNode(root,6);
    root = insertNode(root,1);
    root = insertNode(root,89);
    root = insertNode(root,4);
    root = insertNode(root,36);
    root = insertNode(root,8);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    searchNode(root, 25);
}
```
___
### Deletion from BST - 
```cpp

```