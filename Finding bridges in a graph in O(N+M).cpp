Finding bridges in a graph in O(N+M)
A bridge is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).

Let's say we are in the DFS, looking through the edges starting from vertex v. The current edge (v,to) is a bridge if and only if none of the vertices to and its descendants in the DFS traversal tree has a back-edge
to vertex v or any of its ancestors. Indeed, this condition means that there is no other way from v to to except for edge (v,to).
Low[v] is the minimum of id[v], the entry times id[p] for each node p that is connected to node v via a back-edge (v,p) and the values of low[to] for each vertex to which is a direct descendant of v in the DFS tree:

low[v] = min(low[v],id[p],low[to])

Now, there is a back edge from vertex v or one of its descendants to one of its ancestors if and only if vertex v has a child to for which low[to]≤id[v]. If low[to]=id[v], 
the back edge comes directly to v, otherwise it comes to one of the ancestors of v.
Thus, the current edge (v,to)
in the DFS tree is a bridge if and only if low[to]>id[v].

vector<vector<int>> graph;
vector<bool> vis;
vector<int> id,low;
int time;

void dfs(int v,int p=-1)
{
	vis[v]=true;
	for(auto &to:graph[v])
	{
		if(vis[to])
			low[v]=min(low[v],id[to]);
		else
		{
			low[v]=min(low[v],low[to]);
			if(low[to]>id[v])
				IS_BRIDGE(v, to);
		}
	}
} 

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}