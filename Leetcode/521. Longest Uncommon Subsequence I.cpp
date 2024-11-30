class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        if(a.size() == b.size()) return a.size();
        else return max(a.size(),b.size());
    }
};

/*Explaination*/

//If we analyze the problem carefully, it would seem much easier than it looks. All the three possible cases are as described below; 
//If both the strings are identical, for example: “ac” and “ac”, it is obvious that no subsequence will be uncommon. Hence, return 0.
//If length(a) = length(b) and a ? b, for example: “abcdef” and “defghi”, out of these two strings one string will never be a subsequence of other string. 
//Hence, return length(a) or length(b).
//If length(a) > length(b), for example: “abcdabcd” and “abcabc”, in this case we can consider bigger string as a required subsequence because bigger string can not be a subsequence of smaller string. Hence, return max(length(a), length(b)).
