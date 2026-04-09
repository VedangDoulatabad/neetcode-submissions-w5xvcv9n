class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> solution;
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }

        for(auto it : freq){
            if(it.second > n/3){
                solution.push_back(it.first);
            }
        }

        return solution;
    }
};