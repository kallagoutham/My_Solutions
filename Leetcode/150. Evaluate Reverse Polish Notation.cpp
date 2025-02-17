class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        unordered_map<string,int> m;
        m["+"]=1;m["-"]=2;m["*"]=3;m["/"]=4;
        for(string token:tokens){
            if(token=="*"||token=="+"||token=="-"||token=="/"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                switch(m[token]){
                    case 1:st.push(to_string(a+b));break;
                    case 2:st.push(to_string(a-b));break;
                    case 3:st.push(to_string(a*b));break;
                    case 4:st.push(to_string(a/b));break;
                }
            }else{
                st.push(token);
            }
        }
        return stoi(st.top());
    }
};
