class Solution {
public:
    vector<string> ans;

    bool isValid(string part) {
        // Leading zero is not allowed unless the segment is exactly "0"
        if (part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    void backtrack(string &s, int idx, int parts, string curr) {
        // If 4 parts are formed
        if (parts == 4) {
            if (idx == s.size()) {
                curr.pop_back();      // Remove the last '.'
                ans.push_back(curr);
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            if (isValid(part)) {
                backtrack(s, idx + len, parts + 1, curr + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        backtrack(s, 0, 0, "");
        return ans;
    }
};