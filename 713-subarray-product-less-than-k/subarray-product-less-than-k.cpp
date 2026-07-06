class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size();

        int left = 0;
        long long pro = 1;
        long long res = 0;

        for(int right = 0;right<n;right++){

            

            pro *= nums[right];
            

            while(pro >= k){
                pro /= nums[left];
                left++;
            }

            res += (right-left+1);
        }

        return res;
        
    }
};