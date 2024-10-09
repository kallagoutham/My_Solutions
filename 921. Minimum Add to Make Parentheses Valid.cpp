class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int res=0;
        for(char i:s){
            if(i=='('){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    res++;
                }
            }
        }
        while(!st.empty()){
            st.pop();
            res++;
        }
        return res;
    }
};
