class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        double res = INT_MIN;
        double sum = 0;

        int left = 0;

        for(int right = 0;right<n;right++){

            sum += nums[right];

            if(right - left +1 == k){
                double avg = (sum / k);

                res = max(res,avg);

                sum -= nums[left];

                left++;
            }

        }

        return res;
        
    }
};