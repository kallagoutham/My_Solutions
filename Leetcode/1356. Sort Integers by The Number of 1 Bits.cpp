class Solution {
public:
    int number_of_bits(int number){
        int c=0;
        while(number){
            if(number & 1){
                c++;
            }
            number>>=1;
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> m;
        for(int i:arr){
            int t=number_of_bits(i);
            // cout<<t<<endl;
            if(m.find(t)!=m.end()){
                m[t].push_back(i);
            }else{
                vector<int> tmp;
                tmp.push_back(i);
                m[t]=tmp;
            }
        }
        vector<int> result;
        for (auto& [key, vec] : m) {
            sort(vec.begin(), vec.end());
            result.insert(result.end(), vec.begin(), vec.end());
        }
        return result;
    }
};
