class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        deque<int>dq;

        vector<int>res;

        for(int i=0;i<n;i++){

            if(!dq.empty() && i-k >= dq.front()){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if(k-1 <= i){
                res.push_back(nums[dq.front()]);
            }

           
        }

        return res;
        
    }
};