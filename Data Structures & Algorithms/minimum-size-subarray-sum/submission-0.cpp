class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = 0;
        int l = 0;
        int minLen = INT_MAX;

        for(int r = 0; r < nums.size(); r++){
            total += nums[r];

            // Shrink while valid
            while(total >= target){
                minLen = min(minLen, r - l + 1);
                total -= nums[l];
                l++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};