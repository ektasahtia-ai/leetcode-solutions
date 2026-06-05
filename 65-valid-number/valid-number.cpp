class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digitSeen = true;
                digitAfterE = true;
            }
            else if (c == '+' || c == '-') {
                // Sign allowed only at start or immediately after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // Dot cannot appear after e/E and only once
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }
            else if (c == 'e' || c == 'E') {
                // e/E only once and must follow a digit
                if (eSeen || !digitSeen)
                    return false;

                eSeen = true;
                digitAfterE = false;
            }
            else {
                return false;
            }
        }

        return digitSeen && digitAfterE;
    }
};