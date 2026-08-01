class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            if ((665772 >> __builtin_popcount(i)) & 1) {
                count++;
            }
        }
        return count;
    }
};