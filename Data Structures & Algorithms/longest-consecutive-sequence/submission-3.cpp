class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Store all numbers in a set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        
        for (int num : nums) {
            // Only start counting if num is the start of a sequence
            // (num - 1 doesn't exist in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                longest = max(longest, currentStreak);
            }
        }
        
        return longest;
    }
};
