class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == 1) {
            unordered_map<int, int> count;
            for (int x : nums) count[x]++;
            int ans = -1;
            for (auto& [val, freq] : count) {
                if (freq == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }
        
        if (k == n) {
            int ans = -1;
            for (int x : nums) ans = max(ans, x);
            return ans;
        }
        
        int count0 = 0, countN = 0;
        for (int x : nums) {
            if (x == nums[0]) count0++;
            if (x == nums[n - 1]) countN++;
        }
        
        if (nums[0] == nums[n - 1]) {
            return count0 == 1 ? nums[0] : -1;
        }
        
        int ans = -1;
        if (count0 == 1) ans = max(ans, nums[0]);
        if (countN == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};