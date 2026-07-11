class Solution {
public:
    struct compare {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] > b[0];   // Min Heap based on sum
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        // Push first pair of each row
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (!pq.empty() && k--) {

            auto curr = pq.top();
            pq.pop();

            int i = curr[1];
            int j = curr[2];

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};