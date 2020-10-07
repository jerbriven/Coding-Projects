In order to understand the time and space complexity of the merged max heaps, you
must first consider the complexities for building a heap. For average, worst,
and best cases, the time and space complexity is O(n). The space complexity is
O(n) because n spots in memory are needed for the number of nodes. The big O
time complexity for one call to max is O(nlogn). Looking at the tighter bound,
the time compleixty actually becomes O(n). This function merges two arrays of
size n and m that represent heaps. Therefore, this function has the same space
and time complexities but with m+n. Therefore, both the space and time complexities
should be O(n + m). Since n and m are both linear values, this simplifies to O(n).
Therefore, merging the two max heaps has the same time and space complexity of
building a normal heap, O(n), where n = n + m.