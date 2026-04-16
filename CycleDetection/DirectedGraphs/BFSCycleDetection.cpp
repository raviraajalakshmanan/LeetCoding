// The real issue is:

// in DFS, VISITING means “currently on recursion path”
// in BFS, “visited/discovered” only means “seen before”
// so BFS does not preserve the current path information needed to detect directed cycles that way

// Naive BFS cannot detect cycles in a directed graph using visited/parent logic.
// Example:
// 1 -> 2 -> 3
//  \        \
//   --------> 4
//
// From node 1, BFS may enqueue both 2 and 4.
// Later, when processing 3, it sees an edge 3 -> 4.
// But 4 being already discovered does NOT mean there is a cycle.
// BFS cannot distinguish this from a true back edge to an ancestor in the current path.
//
// So for directed graphs:
// - use DFS + recursion stack, or
// - use Kahn's algorithm (BFS with indegree).
