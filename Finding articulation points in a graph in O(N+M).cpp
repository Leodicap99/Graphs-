An articulation point (or cut vertex) is defined as a vertex which, when removed along with associated edges,makes the graph 
disconnected (or more precisely, increases the number of connected components in the graph). 

Time Complexity:- O(V+E)

1. Let's say we are in the DFS, looking through the edges starting from vertex v≠root. If the current edge (v,to) is such that none of the vertices to or its descendants 
in the DFS traversal tree has a back-edge to any of ancestors of v, then v is an articulation point. Otherwise, v is not an articulation point.

2. Let's consider the remaining case of v=root. This vertex will be the point of articulation if and only if this vertex has more than one child in the DFS tree.

vector<vector<int>> graph;
vector<int> id,low;
vector<bool> vis;
int time=0;
void dfs(int v,int p=-1)
{
	vis[v]=true;
	id[v]=low[v]=time++;
	int children=0;
	for(auto &to:graph[v])
	{
		if(vis[to])
			low[v]=min(low[v],id[to]);
		else
		{
			vis[to]=true;
			low[v]=min(low[v],low[id]);
			if(low[to]>=id[v] && p!=-1)
				IS_CUTPOINT(v);
			children++;
		}
	}
	if(p==-1 && children>1)
		IS_CUTPOINT(v);
}
void cut_vertices()
{
	vis.assign(n,false);
	id.assign(n,0);
	low.assign(n,0);
	for(int i=0;i<n;i++)
		dfs(i);
}