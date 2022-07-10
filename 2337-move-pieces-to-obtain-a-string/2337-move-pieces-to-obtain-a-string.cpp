class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char, int>> lhs, rhs;
        
        for(int i=0; i<start.size(); i++){
            if(start[i]!='_')
                lhs.push({start[i], i});
        }
        
        for(int i=0; i<target.size(); i++){
            if(target[i]!='_')
                rhs.push({target[i], i});
        }
        
        if(lhs.size()!=rhs.size())
            return false;
        
        while(!lhs.empty()){
            pair<char, int> lt, rt;
            
            lt = lhs.front();
            rt = rhs.front();
            
            lhs.pop();
            rhs.pop();
            if(lt.first!=rt.first)
                return false;
            else if(lt.first=='L' && lt.second<rt.second)
                return false;
            else if(lt.first=='R' && lt.second>rt.second)
                return false;
            
        }
        
        return true;
    }
};