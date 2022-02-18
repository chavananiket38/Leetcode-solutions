class Solution {
public:
    bool isConditionTrue(vector<int>& baskets, int minMF, int b)
    {
        int balls = 1, last_pos = baskets[0];
        for(int i = 1; i < baskets.size(); i++)
        {
            int diff = baskets[i] - last_pos;
            if(diff>=minMF){
                balls++;
                if(balls==b)
                    return true;
                last_pos = baskets[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n = pos.size();
        int lo = 1, hi = pos[n-1] - pos[0], ans = -1;
        while(lo<=hi)
        {
            int mid = lo + (hi - lo)/2;
            if(isConditionTrue(pos,mid,m))
            {
                lo = mid + 1;
                ans = mid;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};