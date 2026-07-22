class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string current;
        backtrack(n, current, result, 0, 0);
        return result;
    }

private:
    void backtrack(int &n, string &current, vector<string> &result, int open, int close)
    {
        if(current.size() == n*2)
        {
            result.push_back(current);
        }

        if(open < n)
        {
            current.push_back('(');
            backtrack(n, current, result, open + 1, close);
            current.pop_back();
        }

        if(close < open)
        {
            current.push_back(')');
            backtrack(n, current, result, open, close + 1);
            current.pop_back();
        }
    }
};
