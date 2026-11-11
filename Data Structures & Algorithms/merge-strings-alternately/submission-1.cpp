class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string res;
        while(i < word1.length() && j < word2.length()){
            res += word1[i++];
            res += word2[j++];
        }

        res += word1.substr(i);
        res += word2.substr(j);
        return res;
    }
};