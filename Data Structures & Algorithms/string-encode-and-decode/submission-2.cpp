class Solution {
public:

    // encodes a list of strings to a single string
    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string &s : strs)
        {
            encoded = encoded + to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i < s.length())
        {
            int j=i;
            while(j < s.length() && s[j] != '#')
            {
                j++;
            }

            // extract the length
            int length = stoi(s.substr(i, j-i));

            // extract the string
            string str = s.substr(j+1, length);
            decoded.push_back(str);

            // move to the next string 
            i = j + 1 + length;
        }
        return decoded;
    }
};
