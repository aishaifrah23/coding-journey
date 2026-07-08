class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        long long number = 0; 
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } 
            else if (c == '+') {
                result += sign * number;
                number = 0;   
                sign = 1;     
            } 
            else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;    
            } 
            else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * number;
                number = 0;

                int incomingSign = st.top(); st.pop();
                result *= incomingSign;

                int oldResult = st.top(); st.pop();
                result += oldResult;
            }
        }

        if (number != 0) {
            result += sign * number;
        }

        return result;
    }
};