class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size(), c[26] = {0};
        for (int i = 0; i < n / 2; i++) {
            c[s[i] - 'a']++;
        }
        int l = 0;
        int r = n - 1;
        for (int i = 0; i < 26; i++) {
            while (c[i] > 0) {
                char ch = i + 'a';
                s[l++] = ch;
                s[r--] = ch;
                c[i]--;
            }
        }
        return s;
    }
};
