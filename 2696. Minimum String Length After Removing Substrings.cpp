class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char cur_char = s[i];
            if (st.empty()) {
                st.push(cur_char);
                continue;
            }
            if (cur_char == 'B' && st.top() == 'A') {
                st.pop();
            }
            else if (cur_char == 'D' && st.top() == 'C') {
                st.pop();
            }
            else {
                st.push(cur_char);
            }
        }
        return st.size();
    }
};
