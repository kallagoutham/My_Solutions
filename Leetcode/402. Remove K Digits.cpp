class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit : num){
            while(k>0 && !st.empty() && st.top()>digit){
                st.pop();
                k-=1;
            }
            st.push(digit);
            
        }
        while(k>0){
            st.pop();
            k-=1;
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int nonZeroIdx = 0;
        while (nonZeroIdx < res.length() && res[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }
        res = res.substr(nonZeroIdx);
        return res.empty() ? "0" : res;
    }
};
