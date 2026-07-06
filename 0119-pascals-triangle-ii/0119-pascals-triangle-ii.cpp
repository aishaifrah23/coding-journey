class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1); 
        
        long long current_val = 1;
        for (int r = 1; r <= rowIndex; ++r) {
            current_val = current_val * (rowIndex - r + 1) / r;
            row.push_back(current_val);
        }        
        return row;
    }
};