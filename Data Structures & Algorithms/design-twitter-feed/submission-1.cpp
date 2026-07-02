class Twitter {
    int cnt;
    unordered_map<int,vector<vector<int>>>tweetmap;
    unordered_map<int,set<int>>follower;
public:
    Twitter() {
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        cnt++;
        tweetmap[userId].push_back({cnt,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        auto cmp = [](const vector<int>a, const vector<int>b){
            return a[0]<b[0];
        };
        priority_queue< vector<int>, vector<vector<int>>, decltype(cmp) > pq(cmp);
        follower[userId].insert(userId);
        // insert latest tweet of each followee
        for(auto followeeId: follower[userId]){
            if(tweetmap[followeeId].size()){
                vector<vector<int>>tweets = tweetmap[followeeId];
                int index = tweets.size()-1;
                pq.push({tweets[index][0],tweets[index][1],followeeId,index});
            }
        }

        while(!pq.empty()&&res.size()<10){
            vector<int>curr = pq.top();
            pq.pop();
            int tweet = curr[1];
            int followee = curr[2];
            int index = curr[3];
            res.push_back(tweet);
            if(index>0){
                vector<vector<int>>tweet = tweetmap[followee];
                pq.push({tweet[index-1][0],tweet[index-1][1],followee,index-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
