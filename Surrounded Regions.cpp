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