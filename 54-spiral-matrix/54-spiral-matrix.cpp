class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        if(matrix.empty())return spiral;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        
        int cnt = 0;
        int size = row*col;
        
        while(cnt<size){
            
            for(int i=startCol; cnt<size && i<=endCol; i++){
                spiral.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;
            
            for(int i=startRow; cnt<size && i<=endRow; i++){
                spiral.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;
            
            for(int i=endCol; cnt<size && i>=startCol; i--){
                spiral.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;
            
            for(int i=endRow; cnt<size && i>=startRow; i--){
                spiral.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;
            
        }
        
        return spiral;
    }
};