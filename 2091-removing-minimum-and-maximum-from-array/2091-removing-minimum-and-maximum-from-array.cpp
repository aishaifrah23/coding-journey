class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int a = minIdx, b = maxIdx;
        if (a > b) swap(a, b);
        
        int removeFromFront = b + 1;
        int removeFromBack = n - a;
        int removeBothWays = (a + 1) + (n - b);
        
        return min({removeFromFront, removeFromBack, removeBothWays});
    }
};