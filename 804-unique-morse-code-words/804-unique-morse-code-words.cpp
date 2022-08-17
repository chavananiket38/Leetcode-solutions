class Solution {
public:
    vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        
        for(int i=0; i<words.size(); i++){
            string s = "";
            for(auto k : words[i])
                s += v[k-'a'];
            cout<<s<<" ";
            st.insert(s);
        }
        
        return st.size();
    }
};