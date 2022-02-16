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
    ListNode* swapPairs(ListNode* head) {
        ListNode* nextPtr = head;
        ListNode* prev = nullptr;
        
        while(nextPtr!=nullptr){
            if(prev!=nullptr){
                swap(nextPtr->val, prev->val);
                nextPtr = nextPtr->next;
                prev = nullptr;
                continue;
            }
            
            prev = nextPtr;
            nextPtr = nextPtr->next;
        }
        
        return head;
    }
};