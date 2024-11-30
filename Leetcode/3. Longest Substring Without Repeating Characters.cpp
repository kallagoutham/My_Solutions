class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int currentLength = 0;
        int maxLength = 0;
        int presence[128] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            currentLength = min(i + 1 - presence[s[i]], currentLength + 1);
            maxLength = max(currentLength, maxLength);
            presence[s[i]] = i + 1;
        }

        return maxLength;
    }
};
