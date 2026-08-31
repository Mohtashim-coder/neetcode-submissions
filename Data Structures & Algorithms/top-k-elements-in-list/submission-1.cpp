 class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Create buckets (index = frequency)
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }
        
        // Step 3: Collect top k elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};