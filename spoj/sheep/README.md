

Mirko has a herd of sheep, surrounded by fences backyard. While he was asleep, wolves have sneaked into the fenced area and attacked the sheep.

Backyard is of a rectangular shape, and consists of fields arranged in rows and columns.

    Character '.' (full stop) represents a blank field.
    Character '#' represents a fence.
    Character 'k' represents a sheep.
    Character 'v' represents a wolf.

Two fields belong to the same sector if we can move from the field A to the field B without going over the fence, by making only horizontal and vertical steps (we cannot move diagonally).

If we can escape from field A from the backyard, that field does not belong to any sector.

Luckily, Mirko taught his sheep Kung-Fu skills, and they can defend themselves against wolves only if they outnumber the wolves in that sector. When there are more sheep in the sector than wolves, all wolves die without sheep casualties. Otherwise all sheep perish and wolves are unharmed. If a field doesn't belong in any sector, sheep will flee and wolfs will be left without a prey, so every animal survives.

Write a program that will determine how many sheep and wolves will survive this bloody night.
Input

Integers N and M, number of rows and columns which represent Mirko's backyard.

In every of the N lines, there are M characters representing the appearance of Mirko's backyard - positions of the fences, wolves and sheep.
Constraints

3 <= N, M <= 250\
Output\

In the first and the only line, print the number of sheep and wolves that will survive.
Example

Input:\
8 8  \
.######.\  
#..k...# \ 
#.####.#  \
#.#v.#.#  \
#.#.k#k#  \
#k.##..#  \
#.v..v.#  \
.######.\

Output:\
3 1\

