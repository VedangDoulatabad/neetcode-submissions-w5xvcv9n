class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                char val = board[i][j];

                // row
                if (rows[i].count(val)) return false;
                rows[i].insert(val);

                // col
                if (cols[j].count(val)) return false;
                cols[j].insert(val);

                // box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(val)) return false;
                boxes[boxIndex].insert(val);
            }
        }

        return true;
    }
};