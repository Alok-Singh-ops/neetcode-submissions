class Solution {
public:

    bool checkRow(int row, vector<vector<char>>& board) {
        unordered_map<char, int> mp;

        for (int i = 0; i < 9; i++) {

            if (board[row][i] == '.') {
                continue;
            }

            if (mp.find(board[row][i]) != mp.end()) {
                return false;
            }

            mp[board[row][i]]++;
        }

        return true;
    }

    bool checkCol(int col, vector<vector<char>>& board) {
        unordered_map<char, int> mp;

        for (int i = 0; i < 9; i++) {

            if (board[i][col] == '.') {
                continue;
            }

            if (mp.find(board[i][col]) != mp.end()) {
                return false;
            }

            mp[board[i][col]]++;
        }

        return true;
    }

    bool checkSubGrid(int sr, int er, int sc, int ec,
                      vector<vector<char>>& board) {

        unordered_map<char, int> mp;

        for (int i = sr; i < er; i++) {
            for (int j = sc; j < ec; j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                if (mp.find(board[i][j]) != mp.end()) {
                    return false;
                }

                mp[board[i][j]]++;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int i = 0; i < 9; i++) {
            if (!checkRow(i, board)) {
                return false;
            }
        }

        // Check columns
        for (int i = 0; i < 9; i++) {
            if (!checkCol(i, board)) {
                return false;
            }
        }

        // Check 3x3 subgrids
        for (int sr = 0; sr < 9; sr += 3) {
            for (int sc = 0; sc < 9; sc += 3) {

                if (!checkSubGrid(sr, sr + 3, sc, sc + 3, board)) {
                    return false;
                }
            }
        }

        return true;
    }
};