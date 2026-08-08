class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> suf(n + 1, m);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1;
        }

        vector<int> res;
        int k = 0;
        bool used = false;
        for (int i = 0; i < n; ++i) {
            if (k < m && word1[i] == word2[k]) {
                res.push_back(i);
                k++;
            } else if (!used && k < m && suf[i + 1] <= k + 1) {
                res.push_back(i);
                k++;
                used = true;
            }
        }

        if (res.size() == m) {
            return res;
        }
        return {};
    }
};