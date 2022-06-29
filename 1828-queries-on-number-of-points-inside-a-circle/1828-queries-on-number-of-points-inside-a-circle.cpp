class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int pt = points.size();
        
        int lenQuery = queries.size();
        vector<int> ans;
        for(int i=0; i<lenQuery; i++){
            int cnt = 0;
            for(int j=0; j<pt; j++){
                int x = (queries[i][0]-points[j][0])*(queries[i][0]-points[j][0]);
                int y = (queries[i][1]-points[j][1])*(queries[i][1]-points[j][1]);
                if(x+y<=pow(queries[i][2], 2))
                    cnt++;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};