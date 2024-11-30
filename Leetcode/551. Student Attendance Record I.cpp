class Solution {
public:
    bool checkRecord(string s) {
        bool eligible = true;
        int absentCount = 0, consecutiveLateDays=0;; 
        for(char c:s){
            if(c=='L'){consecutiveLateDays++; if(consecutiveLateDays>=3){eligible=false;}}
            else if(c=='A'){absentCount++;consecutiveLateDays=0;if(absentCount>1){eligible=false;}}
            else{consecutiveLateDays=0;}
        }
        return eligible;
    }
};
