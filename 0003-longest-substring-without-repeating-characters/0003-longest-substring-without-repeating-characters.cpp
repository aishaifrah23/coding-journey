class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1);
        int max_len = 0;
        int start = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (last_seen[s[i]] >= start) {
                start = last_seen[s[i]] + 1;
            }
            last_seen[s[i]] = i;
            max_len = max(max_len, i - start + 1);
        }

        return max_len;
        
    }
};