class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
        {
            return false;
        }

        vector<int> freq(26, 0);

        // count frequencies in s
        for(char c : s)
        {
            freq[c - 'a']++;
        }

        // decrease frequencies for t
        for(char c : t)
        {
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
