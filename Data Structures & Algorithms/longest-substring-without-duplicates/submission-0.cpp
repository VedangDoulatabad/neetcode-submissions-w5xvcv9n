class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, k = 0;

        for(int i = 0; i < s.size(); i++){
            
            // Fix: shrink window properly
            while(st.count(s[i])){
                st.erase(s[l]);
                l++;
            }

            st.insert(s[i]);
            k = max(k, i - l + 1);
        }

        return k;
    }
};