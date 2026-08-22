class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Case 1: Don't rob first house (rob 1 to n-1)
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 1; i < n; i++) {
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }
        int case1 = prev1;
        
        // Case 2: Don't rob last house (rob 0 to n-2)
        prev2 = 0;
        prev1 = 0;
        for (int i = 0; i < n - 1; i++) {
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }
        int case2 = prev1;
        
        return max(case1, case2);
    }
};