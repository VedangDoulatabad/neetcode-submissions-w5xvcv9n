class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums){
            if(seen.find(num) != seen.end()){
                return true;
            }else{
                seen.insert(num);
            }
        }
        return false;
    }
};