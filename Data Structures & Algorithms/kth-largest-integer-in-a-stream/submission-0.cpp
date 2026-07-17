class KthLargest {

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addToHeap(int num)
    {
        if(minHeap.size() < k)
        {
            minHeap.push(num);
        }

        else if(num > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(num);
        }
    }
public:
    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;
        for(int num : nums)
        {
            addToHeap(num);
        }
    }
    
    int add(int val) {
        addToHeap(val);
        return minHeap.top();
    }
};
