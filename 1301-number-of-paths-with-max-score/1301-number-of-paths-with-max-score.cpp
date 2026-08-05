class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        
        vector<vector<long long>> dpSum(n, vector<long long>(n, -1));
        vector<vector<long long>> dpCount(n, vector<long long>(n, 0));
        
        dpSum[n - 1][n - 1] = 0;
        dpCount[n - 1][n - 1] = 1;
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || (dpSum[r][c] == -1 && dpCount[r][c] == 0)) continue;
                
                int dirs[3][2] = {{0, -1}, {-1, 0}, {-1, -1}};
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        int score = (board[nr][nc] == 'E' || board[nr][nc] == 'S') ? 0 : board[nr][nc] - '0';
                        long long newSum = dpSum[r][c] + score;
                        
                        if (newSum > dpSum[nr][nc]) {
                            dpSum[nr][nc] = newSum;
                            dpCount[nr][nc] = dpCount[r][c];
                        } else if (newSum == dpSum[nr][nc]) {
                            dpCount[nr][nc] = (dpCount[nr][nc] + dpCount[r][c]) % MOD;
                        }
                    }
                }
            }
        }
        
        if (dpSum[0][0] == -1) return {0, 0};
        return {(int)dpSum[0][0], (int)dpCount[0][0]};
    }
};