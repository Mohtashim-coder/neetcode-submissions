class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";
        for(string s : strs)
        {
            int len = s.length();
            encoded += to_string(len) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> result;
        int i = 0;
        int n = s.length();
        while(i < n)
        {
            int j = i;
            while(j < n && s[j] != '#')
            {
                j++;
            }

            int len = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, len);
            result.push_back(str);

            i = j + 1 + len;
            
        }
        return result;
    }
};
