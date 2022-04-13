class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral (n, vector<int> (n));
        
        int startRow = 0;
        int endRow = n-1;
        int startCol = 0;
        int endCol = n-1;
        
        int cnt = 0;
        int end = n*n;
        
        while(cnt<end){
            
            for(int i=startCol; cnt<end && i<=endCol; i++)
                spiral[startRow][i] = ++cnt;
            
            startRow++;
            
            for(int i=startRow; cnt<end && i<=endRow; i++)
                spiral[i][endCol] = ++cnt;
            
            endCol--;
            
            for(int i=endCol; cnt<end && i>=startCol; i--)
                spiral[endRow][i] = ++cnt;
            
            endRow--;
            
            for(int i=endRow; cnt<end && i>=startRow; i--)
                spiral[i][startCol] = ++cnt;
            
            startCol++;
        }
        
        return spiral;
    }
};