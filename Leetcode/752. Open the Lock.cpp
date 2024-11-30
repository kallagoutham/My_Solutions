#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_ends(deadends.begin(), deadends.end());
        if (dead_ends.find("0000") != dead_ends.end()) return -1; 
        
        unordered_set<string> visited;
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        
        int res = 0;
        while (!q.empty()) {
            int c = q.size();
            while (c--) {
                string lock = q.front(); q.pop();
                if (lock == target) return res;
                
                for (int i = 0; i < 4; ++i) {
                    string s1 = lock, s2 = lock;
                    s1[i] = (lock[i] - '0' + 1) % 10 + '0'; 
                    s2[i] = (lock[i] - '0' - 1 + 10) % 10 + '0'; 
                    
                    if (visited.find(s1) == visited.end() && dead_ends.find(s1) == dead_ends.end()) {
                        q.push(s1);
                        visited.insert(s1);
                    }
                    if (visited.find(s2) == visited.end() && dead_ends.find(s2) == dead_ends.end()) {
                        q.push(s2);
                        visited.insert(s2);
                    }
                }
            }
            res++;
        }
        return -1; 
    }
};
