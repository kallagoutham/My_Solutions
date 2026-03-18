class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++; 
            if (i >= n) break;

            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            st.push(word);
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += " ";
        }

        return res;
    }
};
