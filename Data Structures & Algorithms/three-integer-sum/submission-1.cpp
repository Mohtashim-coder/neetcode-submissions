class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            if(nums[i] > 0)
            {
                break;
            }

            int low = i + 1;
            int high = n - 1;
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0)
                {
                    result.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1])
                    {
                        low++;
                    }

                    while(low < high && nums[high] == nums[high-1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(sum < 0)
                {
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return result;
    }
};
