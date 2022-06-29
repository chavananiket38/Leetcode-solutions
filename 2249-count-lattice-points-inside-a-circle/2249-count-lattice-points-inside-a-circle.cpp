class Solution {
public:
    int countLatticePoints(vector<vector<int>>& cir) {
        int len = cir.size();
        set<pair<int,int>> st;
        
        for(int i=0; i<len; i++){
            
            int x,y,z;
            x = cir[i][0];
            y = cir[i][1];
            z = cir[i][2];
            
            int a1 = x-z;
            int b1 = y+z;
            
            int a2 = x+z;
            int b2 = y-z;
            ;
            for(int j=a1; j<=a2; j++){
                for(int k=b2; k<=b1; k++){
                    if((pow(j-x,2)+pow(k-y,2))<=(z*z))
                       st.insert({j,k}); 
                }
            }
        }
        
        return st.size();
    }
};