All of us are familiar with the reign of the great mughal ruler, Akbar. He was always concerned with the prosperity and safety of the people. Therefore to safeguard his kingdom (which consisted of N cities) he wanted to place secret soldiers all over his kingdom so as to protect the people. But since his kingdom is very large therefore he wanted to place them in such a way that every city is protected by one and only one soldier.According to Akbar, this is the optimum placement.

As for these soldiers they can protect multiple cities according to their strengths.

The strength of a particular soldier is defined as the maximum distance upto which a guard can protect a city from its base city(base city is the city assigned to the guard). If there are 3 cities C1, C2 and C3 such that C1 C2 and C2 C3 are connected respectively, if a soldier with strength 1 is placed at C2 then all the cities C1, C2 and C3 are protected by that soldier.

Also the kingdom is connected with a network of secret two way roads for faster access only accessible to these soldiers. The length of any road on this network between any two cities is 1 kms. There are R such roads in the kingdom. 

He had given this task to birbal to place the soldiers. Birbal didn't wanted to be a fool in front of the king, therefore took the job and placed M soldiers all over the kingdom but he was not very good at mathematics. But since he is very intelligent he somehow places the guards all over the kingdom and now turns to you (who is a genius mathematician ;) ) to check whether his placements are good or not.

Your task is to check if the placements of the soldiers are optimum or not.
INPUT

The input consists of T test cases. Each test case then consists of 3 parts.The first line consists of N, R and M.

the next R lines consists of two numbers A and B denoting the two cities between which a road exists.

the next M lines consists of 2 numbers, city number K and strength S of that particular soldier.

=> strength 0 means it will only guard the city on which it is present.

=> assume every city is accesible from every other city.
CONSTRAINTS

T <= 10;

1 <= N <= 10^6;

N - 1 <= R <= min(10^7, (N * (N - 1) ) / 2));

1 <= K <= N;

0 <= S <= 10^6\
OUTPUT

print "Yes" if the soldiers are placed optimumly else print "No", (quotes are for clarity.)
SAMPLE

INPUT\
2\
3 2 2\
1 2\
2 3\
1 2\
2 0\
4 5 2\
1 4\
1 2\
1 3\
4 2\
3 4\
2 1\
3 0\

OUTPUT\
No\
Yes\
