class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vec(26,0);
        
        int n = s.size();
        for(int i=0; i<n; i++){
            vec[s[i]-'a'] = i;
        }
        
        vector<int> res;
        int start = 0, end = 0;
        
        for(int i=0; i<n; i++){
            end = max(end, vec[s[i] - 'a']);
            
            if(i==end){
                res.push_back(i-start+1);
                start = i + 1;
            }
        }
        
        return res;
    }
};