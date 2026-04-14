class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int l = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for(int r = 0; r < s.size(); r++){
            mp[s[r]]++;

            // Track most frequent character in window
            maxFreq = max(maxFreq, mp[s[r]]);

            // If invalid window → shrink
            while((r - l + 1) - maxFreq > k){
                mp[s[l]]--;
                l++;
            }

            // Update answer
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};