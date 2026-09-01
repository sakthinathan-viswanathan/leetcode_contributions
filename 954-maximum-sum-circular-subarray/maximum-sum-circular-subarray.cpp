class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int curMax = 0;
        int curMin = 0;

        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int totalSum = 0;

        for(int num : nums){

            curMax = max(num,curMax + num);
            maxSum = max(maxSum,curMax);

            curMin = min(num,curMin + num);
            minSum = min(curMin,minSum);

            totalSum += num;
        }

        if(maxSum < 0){
            return maxSum;
        }

        return max(maxSum,totalSum - minSum);
        
    }
};