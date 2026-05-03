class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // stack
        
        for (int a : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && a < 0 && st.back() > 0) {
                if (abs(a) > st.back()) {
                    st.pop_back(); // stack asteroid destroyed
                } 
                else if (abs(a) == st.back()) {
                    st.pop_back(); // both destroyed
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true; // current destroyed
                    break;
                }
            }
            
            if (!destroyed) {
                st.push_back(a);
            }
        }
        
        return st;
    }
};