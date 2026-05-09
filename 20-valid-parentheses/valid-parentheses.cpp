class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            // Push opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            else {

                // If stack empty
                if(st.empty()) {
                    return false;
                }

                // Check matching
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.empty();
    }
};