class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        int n = nums.size();

        unordered_map<int,int>freq;

        for(int i:nums){
            freq[i]++;
        }

        vector<vector<int>>bucket(n+1);

        for(auto &i:freq){
            bucket[i.second].push_back(i.first);
        }

        vector<int>ans;

        for(int i=bucket.size()-1;i>=0 && ans.size() <= k;i--){
           for(int num:bucket[i]){
            ans.push_back(num);

            if(ans.size() == k){
                return ans;
            }
           }


        }

        return ans;

    }
};