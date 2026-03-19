class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(char c:s){
            if(c=='#'){
                (!st1.empty()) ? st1.pop() : void();
            }else{
                st1.push(c);
            }
        }
        for(char c:t){
            if(c=='#'){
                (!st2.empty()) ? st2.pop() : void();
            }else{
                st2.push(c);
            }
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()==st2.top()){
                st1.pop();
                st2.pop();
                continue;
            }
            return false;
        }   
        if(!st2.empty() || !st1.empty()){
            return false;
        }
        return true;
    }
};
