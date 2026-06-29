class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++)
        {
            for(int j=i+1; j<temperatures.size(); j++)
            {
                if(temperatures[i] < temperatures[j])
                {
                    result[i] = j-i;
                    break;
                }
            }
        }
        return result;
    }
};
