class Solution {
public:
    int bitwiseComplement(int N) {
        int allOnes = 1;
        while(allOnes < N){
            allOnes = allOnes * 2 + 1;
        }
        return allOnes - N;

    }
};
