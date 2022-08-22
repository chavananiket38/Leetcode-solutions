class MinStack {
public:
    stack<int> st1;
    map<int,int> mp;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        mp[val]++;
    }
    
    void pop() {
        int k = st1.top();
        st1.pop();
        if(mp[k]==1)
            mp.erase(k);
        else mp[k]--;
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        for(auto i:mp)
            return i.first;
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */