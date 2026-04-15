class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for(char c : t){
            need[c]++;
        }

        unordered_map<char, int> window;

        int have = 0;
        int needCount = need.size();

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;

            if(need.count(c) && window[c] == need[c]){
                have++;
            }

            // Try shrinking
            while(have == needCount){
                
                // Update answer
                if((r - l + 1) < minLen){
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove from left
                window[s[l]]--;

                if(need.count(s[l]) && window[s[l]] < need[s[l]]){
                    have--;
                }

                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};