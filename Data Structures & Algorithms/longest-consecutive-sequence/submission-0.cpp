class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for (int num : s) {
            // check if it's start of sequence
            if (s.count(num - 1) == 0) {
                int current = num;
                int length = 1;

                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};