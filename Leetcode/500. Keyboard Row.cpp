class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> m;
        m['q']=m['w']=m['e']=m['r']=m['t']=m['y']=m['u']=m['i']=m['o']=m['p']=
        m['Q']=m['W']=m['E']=m['R']=m['T']=m['Y']=m['U']=m['I']=m['O']=m['P']=1;
        m['a']=m['s']=m['d']=m['f']=m['g']=m['h']=m['j']=m['k']=m['l']=
        m['A']=m['S']=m['D']=m['F']=m['G']=m['H']=m['J']=m['K']=m['L']=2;
        m['z']=m['x']=m['c']=m['v']=m['b']=m['n']=m['m']=
        m['Z']=m['X']=m['C']=m['V']=m['B']=m['N']=m['M']=3;
        vector<string> res;
        for(int i=0;i<words.size();i++){
            bool flag=true;
            int row=m[words[i][0]];
            for(int j=1;j<words[i].size();j++){
                if(m[words[i][j]]!=row){
                    flag=false;
                }
            }
            if(flag){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
