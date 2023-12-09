

You are given N*N matrix A filled with integers, which represents map of country "What" ("What" ain't no country I ever heard of). Our hero is called Brett. Brett has many enemies, namely Jules and Vincent (Jules doesn't like him because he said "what" too many times), but his biggest enemy is Marcellus Wallace, because Brett treated him like a male dog treats female dog. And Marcellus most certainly does not look like a female dog.

But Brett cannot sit at home all day enjoying his Big Kahuna burgers, he has to go from cell (sx, sy) to cell (ex, ey).

From cell (x, y) Brett can go to (x+1, y), (x, y+1), (x-1, y), (x, y-1).

If A[x][y] = S, we say that this cell is property of mafia boss S. When Brett visits cell (x, y), and has not yet apologised to boss A[x][y], then he apologises, after that he can visit any cell controlled by A[x][y] without apologising. Brett does not like to apologise (because there is always chance to hear Ezekiel 25 17), so he asks you to find him path which minimises number of times he has to apologise.
Constraints

N <= 50

0 <= A[i][j] < 10\
Input\

First line contains number t donating number of testcases. First line of each testcase consists of number N. N lines follows containing N numbers donating matrix A. After that two lines follow, containing sx, sy and ex, ey.
\
Output\

For each test output number minimal number of times Brett has to apologise.\
Example\

Input:\
3\
5\
0 1 0 2 3\
0 2 0 3 1\
0 5 0 0 0\
0 5 7 8 0\
0 0 0 0 0\
0 0\
0 4\
5\
0 1 0 2 3\
0 2 0 3 1\
0 5 0 0 0\
0 5 7 8 0\
0 0 0 0 0\
0 0\
0 2\
5\
0 1 0 8 3\
0 2 0 3 1\
0 5 0 0 0\
0 5 7 8 9\
0 0 0 0 0\
0 0\
0 3\

Output:\
3\
1\
2\

Explanation

For the second test case, Brett can reach cell (0, 2) following path on which each cell is controlled by boss 0.

NOTE: If you wish to understand references in problem statement, watch the movie Pulp Fiction, or this clip www.youtube.com/watch?v=aBs3Mu-qous
