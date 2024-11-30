class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> m;
        for(int i=0;i<candyType.size();i++){
            m[candyType[i]]++;
        }
        return min(m.size(),candyType.size()/2);
    }
};

--------------------------------------------------------------------------------
//Using the bitset of the c++ bitset header file
    
class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    bitset<200001> bitset;

    for (const int candy : candies)
      bitset.set(candy + 100000);

    return min(candies.size() / 2, bitset.count());
  }
};
