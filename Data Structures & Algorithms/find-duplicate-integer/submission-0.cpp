class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> seen;
        for(int num : nums)
        {
            if(seen.find(num) != seen.end())
            {
                return num;
            }
            seen[num]++;
        }
        return -1;
    }
};
