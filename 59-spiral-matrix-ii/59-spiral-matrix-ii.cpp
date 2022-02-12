class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int> (n));
        if(n==0) return spiral;
        
        int startRow = 0;
        int startCol = 0;
        int endRow = n-1;
        int endCol = n-1;
        
        int cnt = 0;
        int size = n*n;
        
        while(cnt<size){
            
            for(int i=startCol; cnt<size && i<=endCol; i++){
                
                cnt++;
                spiral[startRow][i] = cnt;
                
            }
            startRow++;
            
            for(int i=startRow; cnt<size && i<=endRow; i++){
                cnt++;
                spiral[i][endCol] = cnt;
               
            }
            endCol--;
            
            for(int i=endCol; cnt<size && i>=startCol; i--){
                cnt++;
                spiral[endRow][i] = cnt;
                
            }
            endRow--;
            
            for(int i=endRow; cnt<size && i>=startRow; i--){
                cnt++;
                spiral[i][startCol] = cnt;
                
            }
            startCol++;
            
        }
        
        return spiral;
    }
};