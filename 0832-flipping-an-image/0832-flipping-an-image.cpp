class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image[0].size();
        
        for (auto& row : image) {
            for (int i = 0; i < (n + 1) / 2; ++i) {
                if (row[i] == row[n - 1 - i]) {
                    row[i] ^= 1; 
                    row[n - 1 - i] = row[i];
                }
            }
        }
        
        return image;
    }
};