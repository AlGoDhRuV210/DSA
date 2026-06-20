class Solution
{
public:
  vector<pair<int, int>> merge(vector<pair<int, int>> v)
  {
    if (v.empty())
      return v;
    vector<pair<int, int>> p;
    for (int i = 0; i < v.size(); i++)
    {
      if (p.size() == 0)
      {
        p.push_back(v[i]);
      }
      else if (v[i].first > p.back().second)
        p.push_back(v[i]);
       else
       p.back().second = max(p.back().second, v[i].second);
    }
    return p;
  }

  int minLights(vector<int> &lights)
  {
    int n = lights.size();
    int ans = 0; // bulbs required
    vector<pair<int, int>> v;
    for (int i = 0; i < lights.size(); i++)
    {
      if (lights[i] == 0)
        continue;
      v.push_back({max(0, i - lights[i]), min(n - 1, i + lights[i])});
    }
    sort(v.begin(),v.end());
    v = merge(v);
    if (v.empty())
    {
      return (n+2)/3;
    }
    pair<int, int> p = v[0];

    ans += (p.first + 2) / 3;

    int last = p.second;
    for (int i = 1; i < v.size(); i++)
    {
      int cur = v[i].first;

      ans += (cur - last - 1 + 2) / 3;
      last = v[i].second;
    }
    int rem = n - last - 1;

    ans += (rem + 2) / 3;
    return ans;
  }
};