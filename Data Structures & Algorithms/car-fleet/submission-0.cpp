class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, double>> cars;

        // array of (position, time) pairs
        for(int i=0; i<n; i++)
        {
            double time = (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // sort by position (closest to target first)
        sort(cars.begin(), cars.end(), [](auto& a, auto& b)
        {
            return a.first > b.first;
        });

        // use stack to count fleet
        stack<double> st;
        for(auto& car : cars)
        {
            double time = car.second;

            // if curr car takes longer than the car ahed, it forms a new fleet
            if(st.empty() || time > st.top())
            {
                st.push(time);
            }
        }
        return st.size();
    }
};
