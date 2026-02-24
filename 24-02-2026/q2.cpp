/*DETAILED PROBLEM STATEMENT:

You are given the head of a singly linked list of even length.

The linked list follows these rules:
• Nodes are indexed starting from 0.
• The total number of nodes is even.
• Nodes at even indices contain even integers.
• Nodes at odd indices contain odd integers.
We divide the list into pairs:
(0,1), (2,3), (4,5), ...
For each pair:
• If value at even index > value at odd index → "Even" team gets 1 point.
• If value at odd index > value at even index → "Odd" team gets 1 point.
After evaluating all pairs:
• Return "Even" if Even team has more points.
• Return "Odd" if Odd team has more points.
• Return "Tie" if both teams have equal points.


CONSTRAINTS:
• 2 ≤ Number of nodes ≤ 100
• Number of nodes is even
• 1 ≤ Node.val ≤ 100
• Value at even index is even
• Value at odd index is odd

Sample input1:
2
2 1
Sample output1:
Even


Explanation:
Only one pair (2,1)
2 > 1 → Even gets 1 point.

Sample input2:
4
4 5 2 1
Sample output2:
Tie


Sample input3:
6
2 5 4 7 20 5
Sample output3:
Odd


*/
