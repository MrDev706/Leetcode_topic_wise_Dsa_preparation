//LEETCODE: 

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<n; i+){
            fast = fast->next;
        }
        if(fast==NULL){
            return head;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }

}

//2nd approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* temp=head;
        while(temp!=nullptr){
            v.push_back(temp);
            temp=temp->next;
        }
        int size=v.size();
        int last_node_idx = size-n;
        if(last_node_idx==0) head=v[0]->next;
        else v[last_node_idx-1]->next=v[last_node_idx]->next;
        return head;
    }

};


