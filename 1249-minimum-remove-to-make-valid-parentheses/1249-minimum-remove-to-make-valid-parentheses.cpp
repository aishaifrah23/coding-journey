class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vector<bool> to_remove(n, false);
        vector<int> open_indices;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open_indices.push_back(i);
            } else if (s[i] == ')') {
                if (open_indices.empty()) {
                    to_remove[i] = true; 
                } else {
                    open_indices.pop_back(); 
                }
            }
        }
        for (int idx : open_indices) {
            to_remove[idx] = true;
        }
        string result = "";
        for (int i = 0; i < n; i++) {
            if (!to_remove[i]) {
                result += s[i];
            }
        }
        return result;
    }
};