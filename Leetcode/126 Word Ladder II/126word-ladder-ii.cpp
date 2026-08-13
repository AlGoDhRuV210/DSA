class Solution
{
public:
    string b;
    vector<vector<string>> ans;
    unordered_map<string, int> mpp;

    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (mpp.find(word) != mpp.end())
                {
                    if (mpp[word] == steps - 1)
                    {
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord); 
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;
        int n = beginWord.size();
        while (!q.empty())
        {
            string w = q.front();
            q.pop();
            int steps = mpp[w];
            if(w==endWord)
            break;
            for (int i = 0; i < n; i++)
            {
                char original = w[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    w[i] = c;
                    if (s.find(w) != s.end())
                    {
                        q.push(w);
                        mpp[w] = steps + 1;
                        s.erase(w);
                    }
                }
                w[i] = original;
            }
        }
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);

            dfs(endWord, seq);
        }

        return ans;
    }
};