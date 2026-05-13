class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> mp;

        // Store frequency of words
        for (string word : words)
            mp[word]++;

        // Try every possible starting offset
        for (int i = 0; i < wordLen; i++) {

            int left = i;
            int count = 0;

            unordered_map<string, int> window;

            // Move in chunks of wordLen
            for (int j = i; j + wordLen <= s.size(); j += wordLen) {

                string word = s.substr(j, wordLen);

                // Valid word
                if (mp.find(word) != mp.end()) {

                    window[word]++;
                    count++;

                    // Remove extra occurrences
                    while (window[word] > mp[word]) {

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid substring
                    if (count == wordCount) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                }
                else {

                    // Reset window
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};