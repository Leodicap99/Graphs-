/*
It is well-known, that you can find the shortest paths between a single source and all other vertices in O(|E|) using Breadth First Search in an unweighted graph, 
i.e. the distance is the minimal number of edges that you need to traverse from the source to another vertex. We can interpret such a graph also as a weighted 
raph, where every edge has the weight 1. If not all edges in graph have the same weight, that we need a more general algorithm, like Dijkstra which runs in 
O(|V|2+|E|) or O(|E|log|V|) time.

However if the weights are more constrained, we can often do better. In this article we demonstrate how we can use BFS to solve the 
SSSP (single-source shortest path) problem in O(|E|), if the weights of each edge is either 0 or 1.

*/
void solve()
{
	vector<int> d(n,INF);
	d[s]=0;
	deque<int> dq;
	dq.push_front(s);
	while(!dq.empty())
	{
		int v=dq.front();
		dq.pop_front();
		for(auto edge:graph[v])
		{
			int to=edge.first;
			int cost=edge.second;
			if(d[v]+cost<d[to])
			{
				d[to]=d[v]+cost;
				if(cost==1)
					dq.push_back(to)
				else
					dq.push_front(to);
			}
		}
	}
}
