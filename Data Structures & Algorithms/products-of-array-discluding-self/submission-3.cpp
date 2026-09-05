class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // using prefix suffix array
        int n = nums.size();

        // prefix product: product of all element before i
        vector<int> prefix(n, 1);
        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        // suffix product: product of all elements after i
        vector<int> suffix(n, 1);
        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        // result: product of prefix and suffix
        vector<int> result(n);
        for(int i=0; i<n; i++)
        {
            result[i] = prefix[i]*suffix[i];
        }
        return result;
    }
};
