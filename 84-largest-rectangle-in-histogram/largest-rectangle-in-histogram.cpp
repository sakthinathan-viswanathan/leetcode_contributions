class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        heights.push_back(0);
        stack<int> stk;
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();

                int w = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }

        return ans;
    }
};