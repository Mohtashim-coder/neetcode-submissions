class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int> &nums, int target, int start, vector<int> &current, vector<vector<int>> &result)
    {
        // if we found the valid combination
        if(target == 0)
        {
            result.push_back(current);
            return;
        }

        if(target < 0) // if target becomes negative then this path is invalid
        {
            return;
        }

        for(int i=start; i<nums.size(); i++)
        {
            current.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, current, result);
            current.pop_back();
        }
    }
};
