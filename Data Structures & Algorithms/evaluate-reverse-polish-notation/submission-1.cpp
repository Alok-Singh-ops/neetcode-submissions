class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for (auto it : tokens) {

            if (it == "+" || it == "-" || it == "*" || it == "/") {

                int topEle1 = stoi(st.top());
                st.pop();

                int topEle2 = stoi(st.top());
                st.pop();

                if (it == "+") {
                    st.push(to_string(topEle2 + topEle1));
                }
                else if (it == "-") {
                    st.push(to_string(topEle2 - topEle1));
                }
                else if (it == "*") {
                    st.push(to_string(topEle2 * topEle1));
                }
                else if (it == "/") {
                    st.push(to_string(topEle2 / topEle1));
                }
            }
            else {
                st.push(it);
            }
        }

        return stoi(st.top());
    }
};