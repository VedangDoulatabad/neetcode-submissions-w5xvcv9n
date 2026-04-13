class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> preMax(n), postMax(n);

        // Prefix max
        preMax[0] = height[0];
        for(int i = 1; i < n; i++){
            preMax[i] = max(height[i], preMax[i - 1]);
        }

        // Suffix max
        postMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            postMax[i] = max(height[i], postMax[i + 1]);
        }

        // Calculate water
        int water = 0;
        for(int i = 0; i < n; i++){
            water += min(preMax[i], postMax[i]) - height[i];
        }

        return water;
    }
};