class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        if(arr.size()==0)
        return arr;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        vector<int> rank(temp.size());
        rank[0] = 1;
        for (int i = 1; i < temp.size(); i++)
        {

            if (temp[i] == temp[i - 1])
                rank[i] = rank[i - 1];
            else
                rank[i] = rank[i - 1] + 1;
        }
        unordered_map<int, int> mpp;
        for (int i = 0; i < temp.size(); i++)
        {
            mpp[temp[i]] = rank[i];
        }

        for (int i = 0; i < arr.size(); i++)
        {
            rank[i]=mpp[arr[i]];
        }
        return rank;
    }
};