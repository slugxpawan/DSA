
class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    vector<string> path;

    void backtrack(string word, string beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        } else {
            for (const string& p : parent[word]) {
                backtrack(p, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord)) return {};

        parent.clear();
        ans.clear();
        path.clear();

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;

            while (sz--) {
                string word = q.front();
                q.pop();

                for (int i = 0; i < word.size(); i++) {
                    string next = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == word[i]) continue;

                        next[i] = ch;

                        if (dict.count(next)) {
                            parent[next].push_back(word);

                            if (!levelVisited.count(next)) {
                                levelVisited.insert(next);
                                q.push(next);
                            }

                            if (next == endWord) {
                                found = true;
                            }
                        }
                    }
                }
            }

            // Remove words only after the entire level is processed.
            for (const string& w : levelVisited) {
                dict.erase(w);
            }
        }

        if (found) {
            backtrack(endWord, beginWord);
        }

        return ans;
    }
};
