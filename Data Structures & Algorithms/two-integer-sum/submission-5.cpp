class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // hash map using two pass
        unordered_map<int, int> mp;

        // first pass: store numbers with their index
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        // second pass: find complement
        for(int i=0; i<nums.size(); i++)
        {
            int complement = target - nums[i];
            if(mp.count(complement))
            {
                return {i, mp[complement]};
            }
        }
        return {};
    }
};
