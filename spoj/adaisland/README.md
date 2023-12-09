

Ada the Ladybug just read a book from famous author Dobsonfly Daffoedil. It is about Robinson's Cicada, who was flying over sea. Suddenly she had an accident and fell to island below her. Luckily the island was big enough, so she could recover and fly home till Friday night... or something like that.

As Ada was reading through the book, she fell asleep and started dreaming. She was thinking about how lucky the Cicada was, that she fell into such big island. She could have fallen into a smaller one or even to sea.

It keeps bugging her, so she has asked you to tell her the expected size of island, the Cicada will fall to (considering equal probability for all coordinates). Since Ada is not friend of floating point numbers, she wants the answer in some "nice" form.

Island is considered to be union of any '#' characters, which share side.
Input

The first line contains an integer T, the number of test-cases.

Each test-case begins with two integers N, M, 1 ≤ N, M ≤ 1000

Afterward N lines follow, with M characters. Each of the characters is either '#' (island) or '~' (sea).
Output

For each test-case print the expected size of island. Output it as p / q, where p and q has no common divisor. If p / q can be printed as an integer (not as fraction), do so!\
Example Input

5\
3 4\
~~~~\
~~~~\
~~~~\
3 3\
#~~\
##~\
~~~\
4 5\
#~##~\
#~~~#\
~~~~#\
####~\
1 1\
#\
4 4\
~~~~\
##~~\
~##~\
##~~\

Example Output

0\
1\
7 / 5\
1\
9 / 4\

