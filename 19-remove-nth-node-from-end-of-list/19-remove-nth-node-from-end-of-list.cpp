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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            tmp = tmp->next;
            n++;
        }
        if(n==1)
            return NULL;
        if(k>=n)
            return head->next;
        n -= k+1;
        tmp = head;
        while(n--){
            tmp = tmp->next;
        }
        
        tmp->next = tmp->next->next;
        return head;
    }
};