// Union find does not work for directed graph - it works only when there is one out going edge for
// every node in graph else it does not work because for cases like cross edge we find both nodes
// belongs to same component so it is incorrect example 1 -> 2 -> 3 -> 5 |              ^ | |
// ----------------
// 1 -> 5 and 3 -> 5 , 5 is cross vertex union find says the 5 belongs to same component so there is
// cycle actually there is no cycle.