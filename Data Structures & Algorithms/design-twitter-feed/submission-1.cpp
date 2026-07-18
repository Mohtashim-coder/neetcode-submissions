class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;  // userId → (timestamp, tweetId)
    unordered_map<int, unordered_set<int>> followers;   // followerId → {followeeId}
    int timestamp;
    
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timestamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        vector<pair<int, int>> allTweets;
        
        // Get user's own tweets
        for (auto& tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }
        
        // Get tweets from followed users
        for (int followeeId : followers[userId]) {
            for (auto& tweet : tweets[followeeId]) {
                allTweets.push_back(tweet);
            }
        }
        
        // Sort by timestamp (most recent first)
        sort(allTweets.begin(), allTweets.end(), 
             [](auto& a, auto& b) { return a.first > b.first; });
        
        // Get top 10
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            result.push_back(allTweets[i].second);
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};