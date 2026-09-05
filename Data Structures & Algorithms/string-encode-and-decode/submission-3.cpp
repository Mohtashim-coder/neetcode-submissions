class Solution {
public:

    string encode(vector<string>& strs) {
        // merge all the sub strings with some special characters between them such as delimetry element
        string encoded = "";
        for(const string &s : strs)
        {
            encoded = encoded + to_string(s.length()) + "#" + s;
        }
        return encoded;
        // for ex-1: output as 5#Hello5#World
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.length())
        {
            int j = i;
            while(j < s.length() && s[j] != '#')
            {
                j++;
            }
            // extract length from string
            int length = stoi(s.substr(i, j-i));

            // extract string 
            decoded.push_back(s.substr(j+1, length));

            i = j + 1 + length;
        }
        return decoded;
    }
};
