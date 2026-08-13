class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for (auto i : prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < n; i++)
        {
            for (auto j : adj[i])
                indegree[j]++;
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            cnt++;
            for (auto i : adj[top])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return cnt == n;
    }
};