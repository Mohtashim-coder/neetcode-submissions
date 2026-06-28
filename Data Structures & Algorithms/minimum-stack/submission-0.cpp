class MinStack {

private:

    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
        // No initialization needed
    }
    
    void push(int val) {
        
        st.push(val);

        // push to minst if it's empty or val is new minimum
        if(minSt.empty() || val <= minSt.top())
        {
            minSt.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minSt.top())
        {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
