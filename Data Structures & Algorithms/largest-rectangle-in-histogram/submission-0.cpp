class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> s;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {

            int start = i;

            // Maintain increasing stack
            while(!s.empty() && s.top().second > heights[i]) {

                int index = s.top().first;
                int height = s.top().second;
                s.pop();

                // Width = current index - previous smaller index
                maxArea = max(maxArea, height * (i - index));

                start = index;
            }

            s.push({start, heights[i]});
        }

        // Process remaining elements
        while(!s.empty()) {

            int index = s.top().first;
            int height = s.top().second;
            s.pop();

            maxArea = max(maxArea, height * ((int)heights.size() - index));
        }

        return maxArea;
    }
};