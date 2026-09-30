class Solution {
public:
    vector<vector<int>> dir = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    bool solve(vector<vector<char>>& board, int sr, int sc,
               int i, string& word) {

        // Out of bounds
        if (sr < 0 || sc < 0 ||
            sr >= board.size() || sc >= board[0].size())
            return false;

        // Current cell doesn't match
        if (board[sr][sc] != word[i])
            return false;

        // Last character matched
        if (i == word.size() - 1)
            return true;

        // Mark current cell as visited
        char temp = board[sr][sc];
        board[sr][sc] = '#';

        // Try all 4 directions
        for (int j = 0; j < 4; j++) {

            int new_sr = sr + dir[j][0];
            int new_sc = sc + dir[j][1];

            if (solve(board, new_sr, new_sc, i + 1, word)) {
                return true;
            }
        }

        // Backtrack
        board[sr][sc] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                if (solve(board, r, c, 0, word))
                    return true;
            }
        }

        return false;
    }
};