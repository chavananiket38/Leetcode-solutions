class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0; i<n; i++){
            int num = arr[i];
            int start, end;
            if(num>0){
                start = i+1; end = n-1;
            }else{
                start = 0; end = i-1;
            }
            while(start<=end){
                int mid = (start+end)/2;
                if(arr[mid]==num*2)
                    return true;
                else if(arr[mid]>num*2)
                    end = mid-1;
                else start = mid+1;
            }
        }
        
        
        return false;
    }
};