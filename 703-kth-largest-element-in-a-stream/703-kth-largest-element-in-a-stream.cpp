class KthLargest {
public:
    priority_queue<int> q;
    int k;
    KthLargest(int a, vector<int>& nums) {
        k = a;
        for(auto i:nums){
            q.push(-i);
            if(q.size()>k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(-val);
        if(q.size()>k) q.pop();
        
        return q.top() * (-1);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */