class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right)
        {
            int mid = left + (right - left)/2;

            if(canEatAll(piles, h, mid))
            {
                right = mid;
            }

            else{
                left = mid + 1;
            }
        }
        return left;
    }

private:

    bool canEatAll(vector<int>& piles, int h, int k)
    {
        long long hours = 0;
        for(int pile : piles)
        {
            hours += (pile + k - 1)/k;

            if(hours > h)
            {
                return false;
            }
        }
        return hours <= h;
    }
};
