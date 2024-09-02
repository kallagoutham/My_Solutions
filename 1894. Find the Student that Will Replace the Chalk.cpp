class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for(int i:chalk){sum+=i;}
        if(k%sum == 0){return 0;}
        else{
            k=k%sum;
            for(int i=0;i<chalk.size();++i){
                k-=chalk[i];
                if(k<0){return i;}
            }
        }
        return 0;
    }
};
