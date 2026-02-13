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