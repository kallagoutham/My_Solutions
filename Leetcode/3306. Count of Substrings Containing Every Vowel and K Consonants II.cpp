class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        int low = 0, j = 0; 
        int cons = 0;  
        vector<int> freq(26, 0);
        vector<int> prefixFreq(26, 0);
        long long res = 0;
        auto isVowel = [&](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        
        for (int high = 0; high < n; high++) {
            char ch = word[high];
            if (isVowel(ch))
                freq[ch - 'a']++;
            else
                cons++;
            while (cons > k) {
                char lch = word[low];
                if (isVowel(lch))
                    freq[lch - 'a']--;
                else
                    cons--;
                if(low < j) {
                    if(isVowel(lch))
                        prefixFreq[lch - 'a']--;
                } else {
                    j = low;
                    prefixFreq.assign(26, 0);
                }
                low++;
            }
            bool valid = (cons == k);
            for (char v : {'a','e','i','o','u'}) {
                if (freq[v - 'a'] <= 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            
            if(j < low) {
                j = low;
                prefixFreq.assign(26, 0);
            }
            while (j < high && isVowel(word[j]) && (freq[word[j]-'a'] - prefixFreq[word[j]-'a'] > 1)) {
                prefixFreq[word[j]-'a']++;
                j++;
            }
            res += (j - low + 1);
        }
        
        return res;
    }
};
