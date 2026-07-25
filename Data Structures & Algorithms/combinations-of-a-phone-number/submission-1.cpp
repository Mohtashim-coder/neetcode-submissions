class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return {};
        }

        vector<string> mapping = {" ", // 0
                                  " ", // 1
                                  "abc", // 2
                                  "def", // 3
                                  "ghi", // 4
                                  "jkl", // 5
                                  "mno", // 6
                                  "pqrs", // 7
                                  "tuv", // 8
                                  "wxyz" // 9
    };

        vector<string> result;
        string current;
        backtrack(digits, mapping, current, 0, result);
        return result;
    }

private:
    void backtrack(string &digits, vector<string> &mapping, string &current, int index, vector<string> &result)
    {
        if(index == digits.size())
        {
            result.push_back(current);
            return;
        }

        // get the decimal digit from digits
        int digit = digits[index] - '0';
        string letter = mapping[digit];
        for(char c : letter)
        {
            current.push_back(c);
            backtrack(digits, mapping, current, index+1, result);
            current.pop_back();
        }
    }
};
