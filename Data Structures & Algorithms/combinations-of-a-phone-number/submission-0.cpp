class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Phone keypad mapping
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string current;
        backtrack(digits, mapping, 0, current, result);
        return result;
    }
    
private:
    void backtrack(string& digits, vector<string>& mapping, 
                   int index, string& current, vector<string>& result) {
        // Base case: processed all digits
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get letters for current digit
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        // Try each letter for this digit
        for (char c : letters) {
            // Choose
            current.push_back(c);
            
            // Explore
            backtrack(digits, mapping, index + 1, current, result);
            
            // Backtrack (unchoose)
            current.pop_back();
        }
    }
};