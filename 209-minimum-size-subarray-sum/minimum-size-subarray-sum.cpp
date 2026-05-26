class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int currentsum=0;
        int minWindowsize=INT_MAX;
       

        int l=0;
        int r=0;

        while(r < nums.size()){

            currentsum += nums[r];
            r++;

            while(currentsum >= target){

                int curWindowSize = r-l;

                minWindowsize=min(minWindowsize,curWindowSize);

                currentsum -= nums[l];
                l++;

            }
        }

        return minWindowsize == INT_MAX?0:minWindowsize;
        
    }
};