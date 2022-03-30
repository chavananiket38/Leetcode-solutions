class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n==0 || m==0)
            return false;
        
        int start = 0;
        int end = m*n-1;
        
        // binary search on matrix
        while(start<=end){
            int mid = start + (end-start)/2;
            
            int val = matrix[mid/m][mid%m];
            if(val==target)
                return true;
            
            if(target>val)
                start = mid+1;
            else 
                end = mid-1;
        }
        return false;
    }
};