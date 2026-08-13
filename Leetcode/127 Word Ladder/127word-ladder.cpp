class Solution
{
public:
    int ans = INT_MAX;
    map<string, int> s;

    void bfs(string beginWord, string endWord, int cur, queue<string> q)
    {
        if (beginWord == endWord)
        {
            ans = min(ans, cur);
            return;
        }
        int n = beginWord.length();
        while (!q.empty())
        {
            int siz = q.size();
            cur++;
            while (siz--)
            {
                string w = q.front();
                q.pop();

                for (int i = 0; i < n; i++)
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == w[i])
                            continue;

                        // replace beginWord[i] with c
                        string word = w.substr(0, i) + c +
                                      w.substr(i + 1, n - i - 1);
                        if (word == endWord)
                        {
                            ans = cur + 1;
                            return;
                        }
                        if (s.find(word) != s.end() && s[word] == 0)
                        {
                            q.push(word);
                            s[word] = 1;
                        }
                    }
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        for (auto i : wordList)
            s[i] = 0;
        if (beginWord == endWord)
            return 0;

        if (s.find(endWord) == s.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int n = beginWord.length();
        s[beginWord] = 1;
        bfs(beginWord, endWord, 0, q);

        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};