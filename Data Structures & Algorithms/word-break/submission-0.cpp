class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        // dp[i] = true if first i characters can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string can be segmented
        
        // Put dictionary words in a set for O(1) lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // For each position in the string
        for (int i = 1; i <= n; i++) {
            // Try all possible starting positions j
            for (int j = 0; j < i; j++) {
                // If s[0..j-1] can be segmented AND
                // s[j..i-1] is in the dictionary
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // No need to check further
                }
            }
        }
        
        return dp[n];
    }
};