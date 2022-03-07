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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while(temp1!=NULL && temp2!=NULL){
            ListNode* temp = new ListNode();
            
            if(temp1->val < temp2->val){
                temp->val = temp1->val;
                temp1 = temp1->next;
            }else{
                temp->val = temp2->val;
                temp2 = temp2->next;
            }
            
            ans->next = temp;
            ans = ans->next;
        }
        
        while(temp1!=NULL){
            ListNode* temp = new ListNode();
            temp->val = temp1->val;
            temp1 = temp1->next;
            ans->next = temp;
            ans = ans->next;
        }
            
        while(temp2!=NULL){
            ListNode* temp = new ListNode();
            temp->val = temp2->val;
            temp2 = temp2->next;
            ans->next = temp;
            ans = ans->next;
        }
            
        return head->next;
    }
};