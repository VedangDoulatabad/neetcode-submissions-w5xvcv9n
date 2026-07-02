class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        } 

        unordered_map<char, int> freq;

        // Step 1: count characters of s
        for(char c : s){
            freq[c]++;
        }

        // Step 2: subtract using t
        for(char c : t){
            freq[c]--;
        }

        // Step 3: check all values are 0
        for(auto it : freq){
            if(it.second != 0){
                return false;
            }
        }

        return true;
    }
};
