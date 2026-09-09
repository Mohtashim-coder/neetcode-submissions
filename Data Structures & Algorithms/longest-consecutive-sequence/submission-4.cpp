class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty())
        {
            return 0;
        }

        int longest = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for(int num : nums)
        {
            if(numSet.find(num-1) == numSet.end())
            {
                int currentNum = num;
                int currentStreak = 1;

                while(numSet.find(currentNum+1) != numSet.end())
                {
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);

            }
            
        }
        return longest;
    }
};
