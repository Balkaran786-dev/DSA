#define pp pair<int,int>
class Twitter {
public:
    unordered_map<int,unordered_set<int>> followings;
    unordered_map<int,vector<pp>> tweets;
    
    int time_stamp;
    Twitter() {
        time_stamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time_stamp++;
        tweets[userId].push_back({time_stamp,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pp> pq;
        for(auto ele:tweets[userId]){
            pq.push(ele);
        }


        for(auto follow:followings[userId]){
            for(auto ele:tweets[follow]){
                pq.push(ele);
            }
        }
        vector<int> ans;
        int i=1;
        while(!pq.empty() && i!=11){
             ans.push_back(pq.top().second);
             pq.pop();
             i++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

