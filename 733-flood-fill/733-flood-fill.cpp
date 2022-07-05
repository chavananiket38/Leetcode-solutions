class Solution {
public:
    
    void floodFill(vector<vector<int>>& image, int i, int j, int val, int color){
        if(i<0 or i>=image.size() or j<0 or j>=image[0].size() or image[i][j]!=val or image[i][j]==color)
            return;
        
        image[i][j] = color;
        floodFill(image, i+1, j, val, color);
        floodFill(image, i-1, j, val, color);
        floodFill(image, i, j+1, val, color);
        floodFill(image, i, j-1, val, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        floodFill(image, sr, sc, val, color);
        return image;
    }
};