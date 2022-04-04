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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int kTemp = k;
        int count = 0;
        
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        
        ListNode* first = head;
        while(--kTemp){
            first = first->next;
        }
        // cout<<first->val;
        
        ListNode* second = head;
        int lastCnt = count - k;

        while(lastCnt--){
            second = second->next;
        }
        cout<<second->val<<" "<<first->val;
        swap(first->val, second->val);
        
        return head;
    }
};