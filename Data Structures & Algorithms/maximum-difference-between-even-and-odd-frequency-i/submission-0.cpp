class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s) {
            freq[ch]++;
        }

        int maxOdd = 0;
        int minEven = INT_MAX;

        // Find maximum odd and minimum even frequency
        for (auto &it : freq) {
            if (it.second % 2 == 1) {
                maxOdd = max(maxOdd, it.second);
            } else {
                minEven = min(minEven, it.second);
            }
        }

        return maxOdd - minEven;
    }
};


