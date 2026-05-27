class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        vector<int> res;

        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int left = pos - 1;
        int right = pos;

        while(k--) {

            if(left < 0) {
                res.push_back(arr[right++]);
            }
            else if(right >= n) {
                res.push_back(arr[left--]);
            }
            else {
                int diff1 = abs(arr[left] - x);
                int diff2 = abs(arr[right] - x);

                // tie -> smaller element
                if(diff1 <= diff2) {
                    res.push_back(arr[left--]);
                }
                else {
                    res.push_back(arr[right++]);
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};