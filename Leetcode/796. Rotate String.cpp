class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()){return false;}
        goal=goal+goal;
        size_t found = goal.find(s);
        return found != string::npos;

    }
};
