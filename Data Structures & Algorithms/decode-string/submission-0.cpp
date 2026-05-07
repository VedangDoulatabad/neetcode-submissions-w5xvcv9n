class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        
        string currentString = "";
        int k = 0;

        for (char ch : s) {

            // If digit, build the number
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }

            // Start of bracket
            else if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);

                // Reset for new substring
                k = 0;
                currentString = "";
            }

            // End of bracket
            else if (ch == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();

                string decoded = currentString;

                currentString = stringStack.top();
                stringStack.pop();

                while (repeatTimes--) {
                    currentString += decoded;
                }
            }

            // Normal character
            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};