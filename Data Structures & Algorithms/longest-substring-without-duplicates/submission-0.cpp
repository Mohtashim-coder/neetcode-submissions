class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // using sliding window
        vector<int> lastIndex(256, -1);
        int left = 0;
        int maxLen = 0;

        for(int right=0; right<s.length(); right++)
        {
            char c = s[right];
            if(lastIndex[c] >= left)
            {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right;
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
