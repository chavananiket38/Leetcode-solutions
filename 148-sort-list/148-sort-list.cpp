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
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        
        while(head!=NULL){
            vec.push_back(head->val);
            head = head->next;
        }
        
        sort(vec.begin(), vec.end());
        
        ListNode* head1 = new ListNode(-1, NULL);
        head = head1;
        for(auto i:vec){
            ListNode* temp = new ListNode(i);
            head1->next = temp;
            head1 = head1->next;
        }
        head = head->next;
        return head;
    }
};