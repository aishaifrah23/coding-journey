class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        
        vector<bool> present(mx + 1, false);
        for (int x : nums) {
            present[x] = true;
        }
        
        vector<int> missing;
        for (int i = mn; i <= mx; i++) {
            if (!present[i]) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};