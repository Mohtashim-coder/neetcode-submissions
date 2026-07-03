class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array (for efficiency)
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;  // Number of elements in left half
        
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition point in nums1
            int cut1 = left + (right - left) / 2;
            // Partition point in nums2
            int cut2 = half - cut1;
            
            // Handle edge cases with infinity
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            // Check if partition is correct
            if (left1 <= right2 && left2 <= right1) {
                // Found the correct partition!
                if (total % 2 == 1) {
                    // Odd length: median is max of left side
                    return max(left1, left2);
                } else {
                    // Even length: median is average of max left and min right
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
            else if (left1 > right2) {
                // cut1 is too far right, move left
                right = cut1 - 1;
            }
            else {
                // left2 > right1, cut1 is too far left, move right
                left = cut1 + 1;
            }
        }
        
        // Should never reach here
        return 0.0;
    }
};