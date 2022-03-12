/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        
        temp = head;
        Node* res = new Node(-1);
        while(temp){
            res = mp[temp];
            res->next = mp[temp->next];
            res->random = mp[temp->random];
            
            res = res->next;
            temp = temp->next;
        }
        
        return mp[head];
    }
};