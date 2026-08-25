class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0] = -1;

        int res = 0;
        int sum = 0;


        int left = 0;
        for(int r=0;r<n;r++){

            if(nums[r] == 0){
                sum--;
            }
            else
            {
                sum++;
            }

            if(mp.find(sum) != mp.end()){

                int len = r - mp[sum];
                res = max(res,len);
            }
            else
            {
                mp[sum] = r;
            }
        }

        return res;
        
    }
};