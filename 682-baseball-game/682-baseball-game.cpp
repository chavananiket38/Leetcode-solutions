class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(auto i:ops){
            if(i=="+"){
                int a = st.top();
                st.pop();
                int b = a + st.top();
                st.push(a);
                st.push(b);
            }
            else if(i=="D"){
                int a = st.top();
                st.push(a*2);
            }else if(i=="C"){
                st.pop();
            }else{
                st.push(stoi(i));
            }
        }
        
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};