class Solution {
public:
    bool isDigit(const string& c) {
        return c >= "0" && c <= "9";
    }

    string decodeString(string s) {
        stack<string> st;

        for (char c : s) {
            if (c != ']') {
                st.push(string(1, c));
            } else {
                string temp = "";
                string num = "";

                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); 
                while (!st.empty() && isDigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }

                int number = stoi(num);

                string repeated = "";
                for (int i = 0; i < number; i++) {
                    repeated += temp;
                }

                st.push(repeated);
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
