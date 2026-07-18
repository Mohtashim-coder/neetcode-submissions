class Twitter {

private:
    struct Tweet{
        int tweetId;
        int timestamp;
        Tweet* next;
        Tweet(int id, int time) : tweetId(id), timestamp(time), next(nullptr) {}
    };

    struct User{
        int userId;
        unordered_set<int> following;
        Tweet* tweets;
        User(int id) : userId(id), tweets(nullptr) {}
    };

    unordered_map<int, User*> users;
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // create user if doesn't exist
        if(users.find(userId) == users.end())
        {
            users[userId] = new User(userId);
        }

        // Add tweer to user's tweet list 
        Tweet* newTweet = new Tweet(tweetId, ++timestamp);
        newTweet->next = users[userId]->tweets;
        users[userId]->tweets = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // if user doesn't exist return empty
        if(users.find(userId) == users.end())
        {
            return result;
        }

        // Get all users to fetch tweets from (self + following)
        
        unordered_set<int> feedUsers = {userId};
        for(int followeeId : users[userId]->following)
        {
            feedUsers.insert(followeeId);
        }

        // Max heap: (timestamp, tweetId, user pointers)
        priority_queue<tuple<int, int, Tweet*>> pq;

        // Add most recent tweet from each user
        for(int feedUserId : feedUsers)
        {
            if(users.find(feedUserId) != users.end() && users[feedUserId]->tweets)
            {
                pq.push({users[feedUserId]->tweets->timestamp, users[feedUserId]->tweets->tweetId, users[feedUserId]->tweets});
            }
        }

        // Get top 10 tweets
        while(!pq.empty() && result.size() < 10)
        {
            auto[time, tweetId, tweet] = pq.top();
            pq.pop();
            result.push_back(tweetId);

            // Add next tweet from same user
            if(tweet->next)
            {
                pq.push({tweet->next->timestamp, tweet->next->tweetId, tweet->next});
            }
        }
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        
        // create users if they don't exist
        if(users.find(followerId) == users.end())
        {
            users[followerId] = new User(followerId);
        }

        if(users.find(followeeId) == users.end())
        {
            users[followerId] = new User(followerId);
        }

        users[followerId]->following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users.find(followerId) != users.end())
        {
            users[followerId]->following.erase(followeeId);
        }
    }
};
