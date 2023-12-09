 Ada the Ladybug is on a trip in Bugindia. There are many cities and some uni-directional roads connecting them. Ada is wondering about the shortest path, which begins in a city and ends in the same city. Since Ada likes short trips, she asked you to find the length of such path for each city in Bugindia.

# Input

The first line will contain 0 < N ≤ 2000, the number of cities.

Then N lines follow, each containing N integers 0 ≤ Hij ≤ 1. One means, that there is a road between i and j (zero means there isn't a road).
Output

Print N lines, the length of shortest path which begins in city i and ends in city i. If the path doesn't exist, print "NO WAY" instead.

Example Input

5
0 1 1 1 1 \n
1 0 0 0 1
0 0 1 1 0
0 0 1 0 0
0 0 0 1 0

Example Output

2
2
1
2
NO WAY

Example Input

5
0 1 0 0 1
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
1 0 0 0 0

Example Output

2
5
5
5
2

