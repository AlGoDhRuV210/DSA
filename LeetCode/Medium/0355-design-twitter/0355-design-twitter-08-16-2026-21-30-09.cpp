class Node {
public:
    int id;
    unordered_set<int> following;
    vector<pair<int, int>> tweet;
    Node(int data) { id = data; }
};
class Twitter {
public:
    int time = 0;
    map<int, Node*> mpp;

    Twitter() { mpp.clear(); }

    void postTweet(int userId, int tweetId) {
        Node* node;
        if (mpp.find(userId) == mpp.end()) {
            node = new Node(userId);
            mpp[userId] = node;
        }
        node = mpp[userId];
        node->tweet.push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        if (mpp.find(userId) == mpp.end())
            return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto i : mpp[userId]->following) {
            if (mpp.find(i) == mpp.end())
                continue;
            auto v = mpp[i]->tweet;
            for (int j = (int)v.size() - 1; j >= 0 && j >= (int)v.size() - 10;
                 j--) {
                /* code */
                pq.push(v[j]);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        auto v = mpp[userId]->tweet;
        for (int j = (int)v.size() - 1; j >= 0 && j >= (int)v.size() - 10;
             j--) {
            /* code */
            pq.push(v[j]);
            if (pq.size() > 10)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        Node* node;
        if (mpp.find(followerId) == mpp.end()) {
            node = new Node(followerId);
            mpp[followerId] = node;
        }
        node = mpp[followerId];
        node->following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        Node* node;
        if (mpp.find(followerId) == mpp.end()) {
            node = new Node(followerId);
            mpp[followerId] = node;
        }
        node = mpp[followerId];
        node->following.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */