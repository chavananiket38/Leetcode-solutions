class Solution {
public:
    int largestInteger(int num) {
        
        string s = to_string(num);
        
        vector<char> odd;
        vector<char> even;
        
        for(auto i:s){
            if((i-'0')%2) odd.push_back(i);
            else even.push_back(i);
        }
        
        sort(odd.begin(), odd.end()); reverse(odd.begin(), odd.end());
        sort(even.begin(), even.end());reverse(even.begin(), even.end());
        
        int oddItr = 0, evenItr = 0;
        for(int i=0; i<s.size(); i++){
            if((s[i]-'0')%2) s[i] = odd[oddItr++];
            else s[i] = even[evenItr++];
        }
        
        return stoi(s);
    }
};