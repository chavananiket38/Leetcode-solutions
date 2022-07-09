class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        priority_queue <int, vector<int>, greater<int>> bus;
        priority_queue <int, vector<int>, greater<int>> pass;
        
        for(int i=0; i<buses.size(); i++)
            bus.push(buses[i]);
        for(int i=0; i<passengers.size(); i++)
            pass.push(passengers[i]);

        set<int> st;
        for(int i=0; i<passengers.size(); i++)
            st.insert(passengers[i]);
        
        int lastPass = pass.top();
        int lastBus = bus.top();
        int lastCap = capacity;
        while(!bus.empty() and !pass.empty()){
            int temp = capacity;
            while(temp){
                if(!pass.empty() and bus.top()>=pass.top()){
                    lastPass = pass.top();
                    pass.pop();
                    temp--;
                    lastCap = temp;
                }else{
                    lastBus = bus.top();
                    bus.pop();
                    break;
                }
            }
            
            if(temp==0){
                lastBus = bus.top();
                bus.pop();
            }
        }
        
        cout<<lastBus<<" "<<lastPass<<" "<<lastCap;
        int ans;
        if(!bus.empty()){
            return bus.top();
        }
        if(lastCap==0 or lastBus==lastPass ){
            ans = lastPass;
            while(ans>0){
                if(!st.count(ans))
                    break;
                ans = ans-1;
            }
        }
        else if(lastCap>0){
            ans = lastBus;
            while(ans>lastPass){
                if(!st.count(ans))
                    break;
                ans = ans-1;
            }
        }
        
        return ans;
    }
};