#include <bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int d){
        val=d;
        next=nullptr;
    }
};
ListNode* reverseKGroup(ListNode* head, int k) {
    // 2 linked list
    ListNode* temp=head;
    ListNode* temp1=head;
    stack<int> st;
    while(temp){
        st.push(temp->val);
        if(st.size()==k){
            int step=k;
            while(step--){
                temp1->val=st.top();
                st.pop();
                temp1=temp1->next;
            }
        }
        temp=temp->next;
    }
    return head;
}
