#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
ListNode* deleteKthElement(ListNode* head, int k) {
     if (head==nullptr) return nullptr;
        int cnt=0; 
        ListNode* kNode =head;
        while(kNode!=nullptr){
            cnt++;
            if(cnt==k) break;
            kNode=kNode->next;
        }
        if(kNode==nullptr) return head;

        ListNode* prev=kNode->prev;
        ListNode* front=kNode->next;

        if(prev==nullptr && front == nullptr){
            delete kNode;
            return nullptr;
        }

        else if(prev==nullptr){
            head=front;
            front->prev=nullptr;
        }

        else if(front== nullptr){
            prev->next=nullptr;
        }
        else{
            prev->next=front;
            front->prev=prev;
        }
        delete kNode;
        return head;
}
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    int k = 2; 
    ListNode* updatedHead = solution.deleteKthElement(head, k);
    
    ListNode* current = updatedHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    
    return 0;
}