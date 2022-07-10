class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> q;
        for(auto i:amount)
            q.push(i);
        
        int ans = 0;
        while(q.top()!=0){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a>0 and b>0){
                q.push(--a);
                q.push(--b);
                ans++;
            }else{
                q.push(--a);
                q.push(b);
                ans++;
            }
        }
        
        return ans;
    }
};