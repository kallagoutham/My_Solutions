class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        unordered_set<char> s={'A','E','I','O','U','a','e','i','o','u'};
        string word;
        string temp="maa";
        string res;
        while(ss>>word){
            if(s.count(word[0])!=0){
                //Vowel
                res=res+word+temp;
            }else{
                //Consonant
                res=res+word.substr(1)+word[0]+temp;
            }
            res+=" ";
            temp+="a";
        }
        res.pop_back();
        return res;
    }
};
