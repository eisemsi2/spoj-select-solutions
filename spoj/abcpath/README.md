
You will be given a 2-dimensional grid of letters. Find the length of the longest path of consecutive letters, starting at 'A'. Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).

For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':

Input

Each test case will start with a line contains two integers H, W the height and width of the grid respectively 1 <= H, W <= 50. Then H lines follow each of W uppercase letters only. Input terminates with H = 0 and W = 0.
Output

For each test case print “Case C: X” without quotes where C is the case number starting with 1 and X is the solution.\
Example\


Sample Input:\
4 3\
ABE\
CFG\
BDH\
ABC\
0 0

Sample Output:\
Case 1: 4\