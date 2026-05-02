// #include <bits/stdc++.h>
// using namespace std;

// class minHeap {
//     vector<int> a;

//     void bubbleUp(int i) {
//         while(i > 0 && a[(i - 1) / 2] > a[i]) {
//             swap(a[i], a[(i - 1) / 2]);
//             i = (i - 1) / 2;
//         }
//     }

//     void bubbleDown(int i) {
//         int n = a.size();
//         while(true) {
//             int smallest = i;
//             int l = 2*i + 1;
//             int r = 2*i + 2;

//             if(l < n && a[l] < a[smallest]) smallest = l;
//             if(r < n && a[r] < a[smallest]) smallest = r;

//             if(smallest == i) break;

//             swap(a[i], a[smallest]);
//             i = smallest;
//         }
//     }

// public:
//     void insert(int x) {
//         a.push_back(x);
//         bubbleUp(a.size() - 1);
//     }

//     int getmin() {
//         if(a.empty()) return -1;
//         return a[0];
//     }

//     void remove() {
//         if(a.empty()) return;
//         a[0] = a.back();
//         a.pop_back();
//         bubbleDown(0);
//     }

//     void deleteAt(int i) {
//         if(i >= a.size()) return;

//         a[i] = a.back();
//         a.pop_back();

//         if(i > 0 && a[i] < a[(i - 1) / 2])
//             bubbleUp(i);
//         else
//             bubbleDown(i);
//     }

//     void print() {
//         for(int x : a) cout << x << " ";
//         cout << endl;
//     }
// };

// int main() {
//     minHeap h;

//     h.insert(10);
//     h.insert(5);
//     h.insert(20);
//     h.insert(2);

//     cout << "Min Heap: ";
//     h.print();

//     cout << "Min: " << h.getmin() << endl;

//     h.remove();
//     cout << "After remove: ";
//     h.print();

//     h.deleteAt(1);
//     cout << "After deleteAt(1): ";
//     h.print();
// }