class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false;
        
        std::vector<int> count1(26, 0);
        std::vector<int> count2(26, 0);
        
        // Initialize frequency array for s1 and the first window of s2
        for (int i = 0; i < n1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        // Slide the window of length n1 across s2
        for (int i = 0; i < n2 - n1; ++i) {
            if (count1 == count2) {
                return true;
            }
            
            // Slide window: include s2[i + n1] and exclude s2[i]
            count2[s2[i + n1] - 'a']++;
            count2[s2[i] - 'a']--;
        }
        
        // Check the final window
        return count1 == count2;
    }
};