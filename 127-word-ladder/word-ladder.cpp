class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        // If endWord is not present, transformation is impossible
        if (words.find(endWord) == words.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                // Try changing every character
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;

                        word[i] = c;

                        // Found the end word
                        if (word == endWord)
                            return level + 1;

                        // If this is a valid unused word
                        if (words.find(word) != words.end()) {
                            q.push(word);
                            words.erase(word); // Mark as visited
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};