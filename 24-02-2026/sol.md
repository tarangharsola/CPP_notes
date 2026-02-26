**q1.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int x;
    while (cin >> x) insert(x);
    reverse();
    display();
}
```

---

**q2.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(x);
    }

    int even = 0, odd = 0;
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data > temp->next->data) even++;
        else odd++;
        temp = temp->next->next;
    }

    if (even > odd) cout << "Even" << endl;
    else if (odd > even) cout << "Odd" << endl;
    else cout << "Tie" << endl;
}
```

---

**q3.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int x;
    while (cin >> x) insert(x);

    int n = 0;
    Node* temp = head;
    while (temp != NULL) { n++; temp = temp->next; }

    int arr[100001];
    int i = 0;
    temp = head;
    while (temp != NULL) { arr[i++] = temp->data; temp = temp->next; }

    int l = 0, r = n - 1;
    bool pal = true;
    while (l < r) {
        if (arr[l] != arr[r]) { pal = false; break; }
        l++; r--;
    }

    cout << (pal ? "true" : "false") << endl;
}
```

---

**q4.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int x;
    while (cin >> x) insert(x);

    Node* oddHead = NULL;
    Node* evenHead = NULL;

    Node* temp = head;
    int idx = 1;
    while (temp != NULL) {
        Node* newNode = new Node();
        newNode->data = temp->data;
        newNode->next = NULL;

        if (idx % 2 != 0) {
            if (oddHead == NULL) {
                oddHead = newNode;
            } else {
                Node* t = oddHead;
                while (t->next != NULL) t = t->next;
                t->next = newNode;
            }
        } else {
            if (evenHead == NULL) {
                evenHead = newNode;
            } else {
                Node* t = evenHead;
                while (t->next != NULL) t = t->next;
                t->next = newNode;
            }
        }
        idx++;
        temp = temp->next;
    }

    Node* t = oddHead;
    while (t->next != NULL) t = t->next;
    t->next = evenHead;

    Node* curr = oddHead;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}
```

---

**q5.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int x;
    while (cin >> x) insert(x);

    int freq[100001] = {0};
    Node* temp = head;
    while (temp != NULL) { freq[temp->data]++; temp = temp->next; }

    bool first = true;
    temp = head;
    while (temp != NULL) {
        if (freq[temp->data] == 1) {
            if (!first) cout << " ";
            cout << temp->data;
            first = false;
        }
        temp = temp->next;
    }
    cout << endl;
}
```

---

**q6.cpp**
```cpp
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;
Node* freqHead = NULL;

void insertList(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertFreq(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (freqHead == NULL) {
        freqHead = newNode;
    } else {
        Node* temp = freqHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertList(x);
    }

    map<int, int> freq;

    Node* temp = head;
    while (temp != NULL) {
        freq[temp->data]++;
        temp = temp->next;
    }

    for (auto i : freq) {
        insertFreq(i.second);
    }

    Node* p = freqHead;
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << " ";
        p = p->next;
    }
    cout << endl;
}
```

**How it works:**
```
Original list  : 1 -> 1 -> 2 -> 1 -> 2 -> 3
map after count: {1:3, 2:2, 3:1}
freq list      : 3 -> 2 -> 1
Output         : 3 2 1
```

---

**q7.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int x;
    char c;

    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            cin.putback(c);
            cin >> x;
            insert(x);
        }
    }

    bool inNums[10001] = {false};
    while (cin >> x) inNums[x] = true;

    int count = 0;
    bool inComp = false;
    Node* temp = head;
    while (temp != NULL) {
        if (inNums[temp->data]) {
            if (!inComp) { count++; inComp = true; }
        } else {
            inComp = false;
        }
        temp = temp->next;
    }

    cout << count << endl;
}
```

---

**q8.cpp**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(x);
    }

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->data > temp->next->data) {
                int tmp = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tmp;
                swapped = true;
            }
            temp = temp->next;
        }
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}
```