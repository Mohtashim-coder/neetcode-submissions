class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, current, 0, result);
        return result;
    }

private:
    void backtrack(string &s, vector<string> &current, int start, vector<vector<string>> &result)
    {
        if(start == s.length())
        {
            result.push_back(current);
            return;
        }

        for(int end=start; end<s.length(); end++)
        {
            if(isPalindrome(s, start, end))
            {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, current, end+1, result);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int left, int right)
        {
            while(left < right)
            {
                if(s[left] != s[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
};
