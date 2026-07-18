class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) pq.push(count);
        }
        
        int cycles = 0;
        
        while (!pq.empty()) {
            vector<int> temp;
            int cooldown = n + 1;  // Need n+1 different tasks
            
            // Execute up to n+1 tasks
            while (!pq.empty() && cooldown > 0) {
                int count = pq.top();
                pq.pop();
                count--;
                if (count > 0) temp.push_back(count);
                cooldown--;
                cycles++;
            }
            
            // Push remaining tasks back
            for (int count : temp) {
                pq.push(count);
            }
            
            // If there are still tasks, add idle cycles
            if (!pq.empty()) {
                cycles += cooldown;  // Add idle cycles
            }
        }
        
        return cycles;
    }
};