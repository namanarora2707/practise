#include <bits/stdc++.h>
using namespace std;
class cmp {
public:
    bool operator()(int a, int b) {
        return a > b; // For min-heap
    }
};
int main() {
    priority_queue<int, vector<int>, cmp> minheap;
    minheap.push(5);
    minheap.push(3);
    minheap.push(8);
    minheap.push(1);
    while (!minheap.empty()) {
        cout << minheap.top() << " ";
        minheap.pop();
    }
    return 0;
}