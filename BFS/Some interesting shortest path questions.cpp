Note: Time Complixity of BFS = O(V+E)
Question 1: Given a directed weighted graph. You are also given the shortest path from a source vertex ‘s’ to a destination vertex ‘t’.  If weight of every edge is increased by 10 units, does the shortest path remain same in the modified graph?

Ans) The shortest path may change. The reason is, there may be different number of edges in different paths from s to t.
For example, let shortest path be of weight 15 and has 5 edges. Let there be another path with 2 edges and total weight 25.
The weight of the shortest path is increased by 5*10 and becomes 15 + 50. Weight of the other path is increased by 2*10 and becomes 25 + 20. 
So the shortest path changes to the other path with weight as 45.

Question 2: This is similar to above question. Does the shortest path change when weights of all edges are multiplied by 10?
Ans)If we multiply all edge weights by 10, the shortest path doesn’t change. 
The reason is simple, weights of all paths from s to t get multiplied by same amount. 
The number of edges on a path doesn’t matter. It is like changing unit of weights.

