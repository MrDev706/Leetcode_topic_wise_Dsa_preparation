


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
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode *  prev = nullptr;
        while(start!=end){
            ListNode* temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sentim = new ListNode(0), *slow = sentim, *fast = head;
        sentim->next = head;
        while(fast){
            for(int i=0; i<k; i++){
                if(!fast) return sentim->next;
                fast = fast->next;
            }
            ListNode *temp = slow->next;
            slow->next = reverse(slow->next, fast);
            slow = temp;
            slow->next = fast;
        }
        return sentim->next;
    }
};