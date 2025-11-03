class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0,n=colors.size();
        stack<char> c;
        stack<int> t;
        if(n==1){return res;}
        c.push(colors[0]);
        t.push(neededTime[0]);
        for(int i=1;i<n;++i){
            if(c.top()==colors[i]){
                if(t.top()<=neededTime[i]){
                    res+=t.top();
                    t.pop();
                    t.push(neededTime[i]);
                }else{
                    res+=neededTime[i];
                }
            }else{
                c.push(colors[i]);
                t.push(neededTime[i]);
            }
        }
        return res;
    }
};
