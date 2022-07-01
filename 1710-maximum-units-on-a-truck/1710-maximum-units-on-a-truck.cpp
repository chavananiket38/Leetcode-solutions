class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v;
        
        for(int i=0; i<boxTypes.size(); i++){
            v.push_back({boxTypes[i][1], boxTypes[i][0]});
            cout<<v[i].first<<" "<<v[i].second;
        }
        
        sort(v.begin(), v.end());
        long long int res = 0;
        for(int i=v.size()-1; i>=0; i--){
            if(truckSize>=v[i].second){
                res += v[i].second * v[i].first;
                truckSize -= v[i].second;
            }else if(truckSize<v[i].second){
                res += v[i].first * truckSize;
                break;
            }
        }
        
        return res;
    }
};