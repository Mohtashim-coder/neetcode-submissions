class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length() < t.length())
        {
            return "";
        }

        // frequency of char in t
        unordered_map<char, int> need;
        for(char c : t)
        {
            need[c]++;
        }

        int needed = need.size();
        int formed = 0;

        // frequency of characters in current window
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        int minLen = INT_MAX, minStart = 0;
 
        while(right < s.length())
        {
            char c = s[right];
            window[c]++;

            // if the current frequency meets the requirement
            if(need.count(c) && window[c] == need[c])
            {
                formed++;
            }

            // try to shink window from left while condition holds
            while(left <= right && formed == needed)
            {
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // remove leftmost character
                char leftchar = s[left];
                window[leftchar]--;

                if(need.count(leftchar) && window[leftchar] < need[leftchar])
                {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
