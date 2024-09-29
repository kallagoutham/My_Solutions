class Solution {
  public: int countOfSubstrings(string word, int k) {
    unordered_map<char,int> m;
    int c=0;
    int n=word.size();
    int low=0,high=0;
    int res=0;
    for (int high=0;high<n;high++) {
      if (word[high]=='a'||word[high]=='e'||word[high]=='i'||word[high]=='o'||word[high]=='u') {
        m[word[high]]++;
      } else {
        c++;
      }

      while(c>k){
        if (word[low]=='a'||word[low]=='e'||word[low]=='i'||word[low]=='o'||word[low]=='u') {
          m[word[low]]--;
          if (m[word[low]]==0){m.erase(word[low]);}
        } else {
          c--;
        }
        low++;
      }
      if (m.size()==5 && c==k) {
        int t=low;
        unordered_map<char,int> tempm=m;
        int tempc = c;

        while (t<=high&&tempm.size()==5&&tempc == k) {
          res++;
          if (word[t]=='a'||word[t]=='e'||word[t]=='i'||word[t]=='o'||word[t]=='u'){
            tempm[word[t]]--;
            if (tempm[word[t]]==0) {
              tempm.erase(word[t]);
            }
          } else {
            tempc--;
          }
          t++;
        }
      }
    }

    return res;
  }
};
