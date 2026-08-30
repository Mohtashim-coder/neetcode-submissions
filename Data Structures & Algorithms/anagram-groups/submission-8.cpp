class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // character frequency array as key
        unordered_map<string, vector<string>> mp;
        for(string s : strs)
        {
            vector<int> freq(26, 0);
            for(char c : s)
            {
                freq[c - 'a']++;
            }

            string key = " ";
            for(int i=0; i<26; i++)
            {
                key = key + to_string(freq[i]) + "#";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &pair : mp)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
