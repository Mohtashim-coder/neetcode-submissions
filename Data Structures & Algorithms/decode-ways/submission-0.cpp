class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        if (s[0] == '0') return 0;
        
        // dp[i] = number of ways to decode s[0..i-1]
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Empty string: 1 way
        dp[1] = 1;  // First character (already validated)
        
        for (int i = 2; i <= n; i++) {
            // Take 1 digit: s[i-1]
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Take 2 digits: s[i-2..i-1]
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};