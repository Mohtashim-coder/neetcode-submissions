class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &current, vector<vector<int>> &result)
    {

        // base case: all elements used
        if(current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        // try each unused element
        for(int i=0; i<nums.size(); i++)
        {
            if(used[i]) continue;

            // choose
            used[i] = true;
            current.push_back(nums[i]);

            // explore
            backtrack(nums, used, current, result);

            // backtrack (unchoose)
            current.pop_back();
            used[i] = false;
        }
    }
};
