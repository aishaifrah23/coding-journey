class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, max_len = 0;
        int count[26] = {0};
        
        for (int right = 0; right < s.length(); ++right) {
            int char_idx = s[right] - 'a';
            count[char_idx]++;
            
            while (count[char_idx] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};