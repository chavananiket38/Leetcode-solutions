class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<int> st;
        int i = 0;
        int n = s.size();
        
        while(i<n){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    s[i] = '@';
                }
            }
            i++;
        }
        i=0;
        while(!st.empty()){
            s[st.top()] = '@';
            st.pop();
        }
        
        while(i<n){
            if(s[i]!='@')res += s[i];
            i++;
        }
        
        return res;
    }
};