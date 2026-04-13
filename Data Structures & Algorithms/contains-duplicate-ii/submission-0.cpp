class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++){
            
            // If element already exists in window
            if(s.count(nums[i])){
                return true;
            }

            // Add current element
            s.insert(nums[i]);

            // Maintain window size of k
            if(s.size() > k){
                s.erase(nums[i - k]);
            }
        }

        return false;
    }
};