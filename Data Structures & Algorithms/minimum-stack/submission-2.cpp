class MinStack {
private:
    stack<int> mainStack;   // Stores all elements
    stack<int> minStack;    // Stores minimums
    
public:
    MinStack() {
        // Constructor - nothing to initialize
    }
    
    void push(int val) {
        mainStack.push(val);
        
        // Push to minStack if it's empty or val is new minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // If top of mainStack is the current minimum, pop from minStack too
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};