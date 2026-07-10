class Solution {
public:

    struct compare{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
                return a.first < b.first;
        }
    };
    
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        int res = 0;

       while (--k) {
            pq.pop();
        }

        return pq.top().first;
    }
};