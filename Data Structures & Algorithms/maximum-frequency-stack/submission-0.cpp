class FreqStack {
public:
    
    // Stores frequency of each value
    unordered_map<int, int> freq;

    // Stores stack of elements for each frequency
    unordered_map<int, stack<int>> group;

    // Tracks maximum frequency
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        
        // Increase frequency
        freq[val]++;

        int f = freq[val];

        // Update maximum frequency
        maxFreq = max(maxFreq, f);

        // Push into corresponding frequency stack
        group[f].push(val);
    }
    
    int pop() {
        
        // Get most frequent element
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        // Reduce frequency
        freq[val]--;

        // If no elements left with max frequency
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};