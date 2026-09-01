class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // using bucket sort
        // count frequencies
        unordered_map<int, int> freq;
        for(int num : nums)
        {
            freq[num]++;
        }

        // create bucket (frequency = index)
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto &pair : freq)
        {
            bucket[pair.second].push_back(pair.first);
        }

        // k most frequent element
        vector<int> result;
        for(int i=n; i>=0 && result.size() < k; i--)
        {
            for(int num : bucket[i])
            {
                result.push_back(num);
                if(result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};
