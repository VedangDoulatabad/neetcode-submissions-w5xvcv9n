class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int l = 0;
        int r = people.size() - 1;
        while(l <= r){
            int remain  = limit - people[r];
            r--;
            ans++;
            if(l <= r && remain >= people[l]){
                l++;
            }
        }
        return ans;
    }
};