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

        // using binary-search
        // int left = 1;
        // int right = nums.size()-1;

        // while(left < right)
        // {
        //     int mid = left + (right - left)/2;
        //     int count = 0;

        //     for(int num : nums)
        //     {
        //         if(num <= mid)
        //         {
        //             count++;
        //         }
        //     }

        //     if(count > mid)
        //     {
        //         right = mid;
        //     }
        //     else{
        //         left = mid + 1;
        //     }
        // }
        // return left;
    }
};
