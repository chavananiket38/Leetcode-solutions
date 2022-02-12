class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        
        for(auto word:wordList){
            st.insert(word);
        }
        if(!st.count(endWord))return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            depth += 1;         
            int len = q.size();
            
            while(len--){
                string curr = q.front();
                q.pop();
                int size = curr.size();
                for(int i=0; i<size; i++){
                    string temp = curr;
                    
                    for(char c = 'a'; c<='z'; c++){
                        temp[i] = c;
                        
                        if(temp.compare(curr)==0)continue;//skip the same string
                        
                        if(temp==endWord)return depth+1;
                        
                        if(st.count(temp)){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};