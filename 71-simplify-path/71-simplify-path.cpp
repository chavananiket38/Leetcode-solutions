class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res = "", temp;
        
        for(int i=0; i<path.size(); i++){
            temp = "";
            if(path[i]=='/')
                continue;
            
            while(i<path.size() && path[i]!='/'){
                temp += path[i];
                i++;
            }
            
            if(temp==".")
                continue;
            else if(temp==".."){
                if(!st.empty())
                    st.pop();
            }else{
                st.push(temp);
            }
        }
        
        if(st.empty()){
            res += '/';
            return res;
        }
        
        while(!st.empty()){
            res = '/' + st.top() + res;
            st.pop();
        }
        
        return res;
    }
};