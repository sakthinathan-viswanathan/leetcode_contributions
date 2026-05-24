class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        double ans = INT_MIN;
        int left = 0;

        double sum = 0;

        for(int right = 0;right<n;right++){

            sum += nums[right];

            if((right - left +1) == k){
                double avg = sum / k;

                ans = max(ans,avg);

                sum -= nums[left];
                left++;
            }
        }

        return ans;
        
    }
};