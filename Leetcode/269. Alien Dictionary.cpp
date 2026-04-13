class Solution {
public:

    bool dfs(int node, set<int>& visited, set<int>& path, stack<int>& st,
             unordered_map<int, vector<int>>& adj) {
        visited.insert(node);
        path.insert(node);

        for (int i : adj[node]) {
            if (path.count(i)) return false; // cycle
            if (!visited.count(i)) {
                if (!dfs(i, visited, path, st, adj)) return false;
            }
        }

        path.erase(node);
        st.push(node);
        return true;
    }

    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<int, vector<int>> adj;
        set<int> chars;

        for (string word : words) {
            for (char ch : word) chars.insert(ch - 'a');
        }

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int size = min(s1.size(), s2.size());

            int j = 0;
            while (j < size && s1[j] == s2[j]) j++;

            // corner case: prefix invalid
            if (j == size && s1.size() > s2.size()) return "";

            if (j < size) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            }
        }

        stack<int> st;
        set<int> visited, path;

        for (int ch : chars) {
            if (!visited.count(ch)) {
                if (!dfs(ch, visited, path, st, adj)) return "";
            }
        }

        string res = "";
        while (!st.empty()) {
            res += char(st.top() + 'a');
            st.pop();
        }
        return res;
    }
};
