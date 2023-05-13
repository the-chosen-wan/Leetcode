
Bob has a string S of length N in which each character represents a colour, either Red (represented by R) or Blue (represented by B).

He also has an array D of length N, where each element is a non-negative integer.

In one move, Bob can select any index i between 1 and N and spill the colour S[i] from index i + 1 to i + D[i] (both inclusive). That is, the characters at indexes i + 1, ..., i + D[i] are set to S[i] if D[i] > 0.

Bob wants to make the entire string Red in colour. That is, all characters in S should be equal to R.

Help him find the minimum number of moves to do so. If this is impossible, print -1.

Input Format
The first line of input contains an integer T, the number of test cases.
The following lines describe the test cases. In each test case:
The first line contains the integer N.
The second line contains the string S, containing N characters.
The third line contains N space separated integers, D[1], D[2], ... D[N]

Output Format
For each testcase, print a new line with the minimum number of moves required to make the entire string Red in colour. If it is impossible, print -1.

Sample
Input
3
3
RRB
2 1 0
3
RRR
1 1 0
3
RRB
1 0 0
Output
1
0
-1