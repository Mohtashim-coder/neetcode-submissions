class Solution {
    public:
        int numDistinct(string s, string t) {
                int n = s.length();
                        int m = t.length();
                                
                                        // dp[i][j] = number of distinct subsequences of s[0...i-1] equal to t[0...j-1]
                                                vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
                                                        
                                                                // Base case: empty string t can be formed in 1 way
                                                                        for (int i = 0; i <= n; i++) {
                                                                                    dp[i][0] = 1;
                                                                                            }
                                                                                                    
                                                                                                            // Fill the DP table
                                                                                                                    for (int i = 1; i <= n; i++) {
                                                                                                                                for (int j = 1; j <= m; j++) {
                                                                                                                                                if (s[i - 1] == t[j - 1]) {
                                                                                                                                                                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                                                                                                                                                                                    } else {
                                                                                                                                                                                                        dp[i][j] = dp[i - 1][j];
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                            return (int)dp[n][m];
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                };

