class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       int n = s.length();
        string ans = "";
        int min_len = n + 1;
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '1') count++;
                if (count == k) {
                    string sub = s.substr(i, j - i + 1);
                    int len = sub.length();
                    if (len < min_len) {
                        min_len = len;
                        ans = sub;
                    } else if (len == min_len) {
                        if (ans == "" || sub < ans) {
                            ans = sub;
                        }
                    }
                    break;
                }
            }
        }
        return ans; 
    }
};