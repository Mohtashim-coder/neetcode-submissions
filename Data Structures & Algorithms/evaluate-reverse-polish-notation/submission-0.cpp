class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(string& token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = st.top(); // second operand
                st.pop();

                int a = st.top(); // first operand
                st.pop();

                if(token == "+")
                {
                    st.push(a + b);
                }

                else if(token == "-")
                {
                    st.push(a - b);
                }

                else if(token == "*")
                {
                    st.push(a * b);
                }

                else if(token == "/")
                {
                    st.push(a / b);
                }
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
