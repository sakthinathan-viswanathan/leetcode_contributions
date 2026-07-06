class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        deque<int>mq;
        vector<int>res;

        int left = 0;
        for(int right=0;right<n;right++){

            while(!mq.empty() && nums[mq.back()] <= nums[right]){
                mq.pop_back();
            }

            mq.push_back(right);

            if((right-left+1) == k){
                res.push_back(nums[mq.front()]);
                left++;
            }

            while(!mq.empty() && mq.front() < left){
                mq.pop_front();
            }


        }

        return res;
    }
};