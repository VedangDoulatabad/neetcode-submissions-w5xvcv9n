class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Count s1
        for(char c : s1){
            freq1[c - 'a']++;
        }

        int k = s1.size();

        for(int i = 0; i < s2.size(); i++){
            // Add current char
            freq2[s2[i] - 'a']++;

            // Remove char outside window
            if(i >= k){
                freq2[s2[i - k] - 'a']--;
            }

            // Compare
            if(freq1 == freq2){
                return true;
            }
        }

        return false;
    }
};