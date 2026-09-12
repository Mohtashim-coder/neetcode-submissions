class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
                int n = nums.size();
                        // memo[i][sum] — but sum can be negative, so offset it
                                // Max possible sum = 1000 * 20 = 20000, so range is [-20000, 20000]
                                        unordered_map<long long, int> memo;
                                                return dfs(nums, 0, 0, target, memo);
                                                    }
                                                        
                                                        private:
                                                            int dfs(vector<int>& nums, int i, int sum, int target, unordered_map<long long, int>& memo) {
                                                                    if (i == nums.size()) {
                                                                                return sum == target ? 1 : 0;
                                                                                        }
                                                                                                long long key = ((long long)i << 32) | (sum + 20000);
                                                                                                        if (memo.count(key)) return memo[key];
                                                                                                                
                                                                                                                        int ways = dfs(nums, i + 1, sum + nums[i], target, memo)
                                                                                                                                         + dfs(nums, i + 1, sum - nums[i], target, memo);
                                                                                                                                                 memo[key] = ways;
                                                                                                                                                         return ways;
                                                                                                                                                             }
                                                                                                                                                             }; 

