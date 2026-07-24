class Solution {
private:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= '0' && c <= '9');
    }

    char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }

public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }
            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }

            if (toLowerCase(s[left]) != toLowerCase(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};