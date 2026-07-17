class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while(pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();

            int second_top = pq.top();
            pq.pop();

            if(top > second_top)
            {
                pq.push(top - second_top);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
