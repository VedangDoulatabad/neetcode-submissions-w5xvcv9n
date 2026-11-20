class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxArea = 0;

        while (i < j) {
            int h = min(heights[i], heights[j]);
            int w = j - i;
            maxArea = max(maxArea, h * w);

            // move smaller height
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxArea;
    }
};