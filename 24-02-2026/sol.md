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
#include <set>
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

    set<int> seen;
    set<int> duplicate;

    Node* temp = head;
    while (temp != NULL) {
        if (seen.count(temp->data)) {
            duplicate.insert(temp->data);
        } else {
            seen.insert(temp->data);
        }
        temp = temp->next;
    }

    bool first = true;
    temp = head;
    while (temp != NULL) {
        if (duplicate.count(temp->data) == 0) {
            if (!first) cout << " ";
            cout << temp->data;
            first = false;
        }
        temp = temp->next;
    }
    cout << endl;
}
```

**q6.cpp**
```cpp
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* p=nullptr;

    Node(int d) {
      data=d;
    }
};

class SLL {
    public:
    Node* sp = nullptr;

    void addAtEnd(Node* newobj) {
        Node* tp = sp;
        if (sp==nullptr) {
            sp=newobj;
            return;
        }
        while(tp->p!=nullptr) {
            tp=tp->p;
        }
        tp->p=newobj;
    }

    unordered_map<int,int> freqReturn() {
        Node* tp = sp;
        unordered_map<int,int> returnMap;

        while(tp != nullptr) {
            returnMap[tp->data]++;
            tp=tp->p;
        }
        return returnMap;
    }

    void printLL() {
        Node* tp = sp;

        while(tp!=nullptr) {
            cout << tp->data << " ";
            tp=tp->p;
        }
    }
};

int main() {
    SLL* linkedlist = new SLL();
    int num;
    cin>>num;
    for (int i=0; i<num; i++) {
        int tempnum;
        cin>>tempnum;
        Node* temp = new Node(tempnum);
        linkedlist->addAtEnd(temp);
    }

    SLL* returnList = new SLL();
    auto maps = linkedlist->freqReturn();

    for (auto x:maps) {
        Node* temp1 = new Node(x.second);
        returnList->addAtEnd(temp1);
    }
    returnList->printLL();
}

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