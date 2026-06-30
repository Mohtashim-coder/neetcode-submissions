class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, double>> cars;

        // array of (position, time) pairs
        for(int i=0; i<n; i++)
        {
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // sort by position (closest to target first)
        sort(cars.begin(), cars.end(), [](auto& a, auto& b)
        {
            return a.first > b.first;
        });

        int fleets = 0;
        double maxTime = -1.0;
        
        // Process cars from closest to target to farthest
        for (const auto& car : cars) {
            double time = car.second;
            
            // If this car takes longer than all cars ahead,
            // it cannot catch up → forms a new fleet
            if (time > maxTime) {
                fleets++;
                maxTime = time;
            }
            // Else: it catches up to a fleet ahead
        }
        
        return fleets;
    }
};
