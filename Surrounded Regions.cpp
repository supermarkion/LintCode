/*
	Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
	A region is captured by flipping all 'O''s into 'X''s in that surrounded region.
	Link: http://www.lintcode.com/en/problem/surrounded-regions/
	Example: 
	
	X X X X
	X O O X
	X X O X
	X O X X

	After capture all regions surrounded by 'X', the board should be:

	X X X X
	X X X X
	X X X X
	X O X X

	Solution: apply a queue to perform BFS
	Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/surrounded-regions.cpp
*/

class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); ++i) {
            q.emplace(make_pair(i, 0));
            q.emplace(make_pair(i, board[0].size() - 1));
        }

        for (int j = 0; j < board[0].size(); ++j) {
            q.emplace(make_pair(0, j));
            q.emplace(make_pair(board.size() - 1, j));
        }
        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            if (board[i][j] == 'O' || board[i][j] == 'V') {
                board[i][j] = 'V';
                const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                        {-1, 0}, {1, 0}};
                for (const auto& d : directions) {
                    const int x = i + d.first, y = j + d.second;
                    if (0 <= x  && x < board.size() &&
                        0 <= y && y < board[0].size() &&
                        board[x][y] == 'O') {
                        board[x][y] = 'V';
                        q.emplace(make_pair(x, y));
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != 'V') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};