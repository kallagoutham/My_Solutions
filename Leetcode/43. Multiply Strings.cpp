class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){return "0";}
        vector<vector<int>> muls;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry=0;
        int step=0;
        int maxIndex=INT_MIN;
        for(char i:num2){
            vector<int> t;
            t.assign(step,0);
            for(char j:num1){
                int product= (i-'0') * (j -'0') + carry;
                carry = product/10;
                t.push_back(product%10);
            }
            while(carry>0){
                t.push_back(carry%10);
                carry/=10;
            }
            muls.push_back(t);
            step++;
            int tmp=t.size();
            if(tmp>maxIndex){
                maxIndex=tmp;
            }
        }
        cout<<maxIndex<<endl;
        string res="";
        carry=0;
        for(int i=0;i<maxIndex;i++){
            int sum=0;
            for(vector<int> j:muls){
                try {
                    sum+=j.at(i);
                } catch (const out_of_range& e) {
                    continue;
                }
            }
            sum+=carry;
            res+=(to_string(sum%10));
            carry=sum/10;
        }
        while(carry>0){
            res+=(to_string(carry%10));
            carry/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
