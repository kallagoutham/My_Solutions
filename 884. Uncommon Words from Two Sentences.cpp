class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        stringstream ss(s1);
        string temp;
        while (ss >> temp) {
            m1[temp]++;
        }

        // Clear and reassign the stringstream for the second string (s2)
        ss.clear();           // Clear any error flags
        ss.str(s2);           // Assign the new string s2 to stringstream
        while (ss >> temp) {
            m2[temp]++;
        }
        vector<string> res;
        ss.clear();
        ss.str(s1); 
        while (ss >> temp) {
            if (m1[temp] == 1 && m2.find(temp) == m2.end()) {
                res.push_back(temp);
            }
        }
        ss.clear();
        ss.str(s2); 
        while (ss >> temp) {
            if (m2[temp] == 1 && m1.find(temp) == m1.end()) {
                res.push_back(temp);
            }
        }

        return res;
    }
};


// **********************************************************************************************//


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        string s=s1+" "+s2;
        stringstream ss(s);
        unordered_map<string,int> m;
        string temp;
        while(ss>>temp){
            m[temp]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second==1){
                res.push_back(i->first);
            }
        }
        return res;
    }
};
