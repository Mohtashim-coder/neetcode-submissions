class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // using maxHeap
        // count frequencies
        unordered_map<int, int> freq;
        for(int num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for(auto &pair : freq)
        {
            maxHeap.push({pair.second, pair.first});
        }

        vector<int> result;
        for(int i=0; i<k; i++)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
