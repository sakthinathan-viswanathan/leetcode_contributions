class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> &a,pair<int,int>& b){
            return a.first > b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;

        for(int i:nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;

        for(auto i:mp){
            pq.push({i.second,i.first});

            if (pq.size() > k)
            pq.pop();
        }

        vector<int>res;

        while(!pq.empty()){
           res.push_back(pq.top().second);
           pq.pop();
        }


        return res;
        
    }
};