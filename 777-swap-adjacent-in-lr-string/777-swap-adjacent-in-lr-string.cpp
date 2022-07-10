class Solution {
public:
    bool canTransform(string start, string end) {
        queue<pair<char, int>> ls, rs;
        
        for(int i=0; i<start.size(); i++){
            if(start[i]!='X')
                ls.push({start[i], i});
        }
        
        
        for(int i=0; i<end.size(); i++){
            if(end[i]!='X')
                rs.push({end[i], i});
        }
        
        if(ls.size()!=rs.size())
            return false;
        
        while(!ls.empty()){
            pair<char, int> s, e;
            s = ls.front();
            e = rs.front();
            ls.pop();
            rs.pop();
            
            if(s.first!=e.first)
                return false;
            else if(s.first=='L' && s.second<e.second)
                return false;
            else if(s.first=='R' && s.second>e.second)
                return false;
        }
        
        return true;
    }
};