class Solution {
private:
    long long getPerms(int L, const vector<int>& cnt, long long k) {
        long long res = 1;
        int current_L = 1;
        for (int c = 0; c < 26; ++c) {
            for (int j = 1; j <= cnt[c]; ++j) {
                res = res * current_L / j;
                current_L++;
                if (res >= k) return k;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<int> cnt(26, 0);
        int odd_char = -1;
        for (int c = 0; c < 26; ++c) {
            cnt[c] = freq[c] / 2;
            if (freq[c] % 2 != 0) {
                odd_char = c;
            }
        }

        int half = n / 2;
        long long target_k = k;
        if (getPerms(half, cnt, target_k) < target_k) {
            return "";
        }

        string first_half = "";
        for (int i = 0; i < half; ++i) {
            int remaining_len = half - 1 - i;
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0) continue;

                cnt[c]--;
                long long ways = getPerms(remaining_len, cnt, target_k);
                if (ways >= target_k) {
                    first_half += (char)('a' + c);
                    break;
                } else {
                    target_k -= ways;
                    cnt[c]++;
                }
            }
        }

        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        if (odd_char != -1) {
            return first_half + (char)('a' + odd_char) + second_half;
        }
        return first_half + second_half;
    }
};