#include <bits/stdc++.h>
using namespace std;

class maxHeap {
    vector<int> a;

    void bubbleUp(int i) {
        while(i > 0 && a[(i - 1) / 2] < a[i]) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void bubbleDown(int i) {
        int n = a.size();
        while(true) {
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n && a[l] > a[largest]) largest = l;
            if(r < n && a[r] > a[largest]) largest = r;

            if(largest == i) break;

            swap(a[i], a[largest]);
            i = largest;
        }
    }

public:
    void insert(int x) {
        a.push_back(x);
        bubbleUp(a.size() - 1);
    }

    int getmax() {
        if(a.empty()) return -1;
        return a[0];
    }

    void remove() {
        if(a.empty()) return;
        a[0] = a.back();
        a.pop_back();
        bubbleDown(0);
    }

    void deleteAt(int i) {
        if(i >= a.size()) return;

        a[i] = a.back();
        a.pop_back();

        if(i > 0 && a[i] > a[(i - 1) / 2])
            bubbleUp(i);
        else
            bubbleDown(i);
    }

    void print() {
        for(int x : a) cout << x << " ";
        cout << endl;
    }
};

int main() {
    maxHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    cout << "Max Heap: ";
    h.print();

    cout << "Max: " << h.getmax() << endl;

    h.remove();
    cout << "After remove: ";
    h.print();

    h.deleteAt(1);
    cout << "After deleteAt(1): ";
    h.print();
}