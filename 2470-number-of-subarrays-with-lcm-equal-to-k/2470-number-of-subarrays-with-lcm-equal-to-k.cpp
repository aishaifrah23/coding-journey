class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int current_lcm = nums[i];
            
            for (int j = i; j < n; ++j) {
                if (k % nums[j] != 0) {
                    break;
                }
                
                current_lcm = std::lcm(current_lcm, nums[j]);
                
                if (current_lcm > k) {
                    break;
                }
                
                if (current_lcm == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
};