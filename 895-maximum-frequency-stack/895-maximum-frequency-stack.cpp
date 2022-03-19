class FreqStack {
public:
    
    map<int,int> freMap;
    map<int, stack<int>> stackMap;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = freMap[val]+1;
        freMap[val] = freq;
        
        if(freq>maxFreq)
            maxFreq = freq;
        
        stackMap[freq].push(val);
    }
    
    int pop() {
        int top = stackMap[maxFreq].top();
        stackMap[maxFreq].pop();
        
        freMap[top]--;
        
        if(stackMap[maxFreq].size()==0)
            --maxFreq;
        
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */