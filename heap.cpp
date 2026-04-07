#include <bits/stdc++.h>
using namespace std;
class minheap{
private:
    vector<int> v;
    void heapify(int i){
        int mi=i;
        int left=2*i;
        int right=2*i+1;
        if(left<v.size() && v[left]<v[mi]){
            mi=left;
        }
        if(right<v.size() && v[right]<v[mi]){
            mi=right;
        }
        if(mi!=i){
            swap(v[i],v[mi]);
            heapify(mi);
        }
    }
public:
    minheap(){
        v.push_back(-1);
    }
    void push(int data){
        v.push_back(data);
        int index=v.size()-1;
        int parent=index/2;
        while(index>1 && v[parent]>v[index]){
            swap(v[parent],v[index]);
            index=parent;
            parent=index/2;
        }
    }
    void pop(){
        if(v.size()<=1){
            cout<<"Heap is empty"<<endl;
            return;
        }
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    int top(){
        if(v.size()<=1){
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        return v[1];
    }
    bool empty(){
        return v.size()<=1;
    }
};
int main() {
    minheap h;
    h.push(5);
    h.push(3);
    h.push(8);  
    h.push(1);
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
    return 0;
}