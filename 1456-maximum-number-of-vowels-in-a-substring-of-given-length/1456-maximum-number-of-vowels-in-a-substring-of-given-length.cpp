class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int count = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) count++;
        }

        int max_count = count;
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i - k])) count--;
            
            max_count = max(max_count, count);
            if (max_count == k) return k;
        }

        return max_count;
    }
};