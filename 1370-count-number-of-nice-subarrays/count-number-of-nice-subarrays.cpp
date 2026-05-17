class Solution {
public:

    int findSubarray(vector<int> &nums,int k){

        int n = nums.size();

        int oddCount = 0;
        int count = 0;

        int left = 0;
        for(int right = 0;right<n;right++){

            if(nums[right] % 2 == 1){
                oddCount++;
            }

            while(oddCount > k){

                if(nums[left] % 2 == 1){
                    oddCount--;
                }
                left++;
            }
            count += (right-left+1);
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return findSubarray(nums,k) - findSubarray(nums,k-1);
        
    }
};