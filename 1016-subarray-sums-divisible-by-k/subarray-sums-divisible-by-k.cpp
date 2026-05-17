class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;

        mp[0] = 1;
        int sum = 0;
        int count = 0;

       
        for(int right = 0;right<n;right++){

            sum += nums[right];

            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            
            count += mp[rem];

            mp[rem]++;
           
        }

        return count;
        
    }
};