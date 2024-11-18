class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        bool r=false;
        if(k<0){
            reverse(code.begin(),code.end());
            k*=-1;
            r=true;
        }
        int s=accumulate(code.begin()+1,code.begin()+k+1,0);
        // cout<<s<<" ";
        code.insert(code.end(),code.begin(),code.end());
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(s);
            s-=code[i+1];
            s+=code[i+k+1];
        }
        if(r){
            reverse(res.begin(),res.end());
        }
        return res;
    }
};
