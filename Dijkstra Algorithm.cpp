/*
Dijkstra Algorithm
You are given a directed or undirected weighted graph with n vertices and m edges. 
The weights of all edges are non-negative. You are also given a starting vertex s.

Algorithm

Let's create an array d[] where for each vertex v we store the current length of the shortest path from s to v in d[v]. Initially d[s]=0
, and for all other vertices this length equals infinity. In the implementation a sufficiently large number (which is guaranteed to be greater 
than any possible path length) is chosen as infinity.

d[v]=∞, v≠s

In addition, we maintain a Boolean array u[] which stores for each vertex v

whether it's marked. Initially all vertices are unmarked:

u[v]=false

The Dijkstra's algorithm runs for n iterations. At each iteration a vertex v is chosen as unmarked vertex which has the least value d[v]
Evidently, in the first iteration the starting vertex will be selected.

The selected vertex v is marked. Next, from vertex v relaxations are performed: all edges of the form (v,to) are considered, and for each vertex to the algorithm tries to improve the value d[to]. 
If the length of the current edge equals len

, the code for relaxation is:

d[to]=min(d[to],d[v]+len)

After all such edges are considered, the current iteration ends. Finally, after n
iterations, all vertices will be marked, and the algorithm terminates. We claim that the found values d[v] are the lengths of shortest paths from s to all vertices v.

Note that if some vertices are unreachable from the starting vertex s, the values d[v] for them will remain infinite. Obviously, the last few iterations of the algorithm will choose those vertices, 
but no useful work will be done for them. Therefore, the algorithm can be stopped as soon as the selected vertex has infinite distance to it.

Time Complexity:O(V^2+E)

*/

vector<vector<pair<int,int>>> graph;
const int INF=1e9;
vector<int> p,d;

void dijkstra()
{
	int n=graph.size();
	d.assign(n,INF);
	p.assign(n,-1);
	vector<bool> vis(n,false);
	for(int i=0;i<n;i++)
	{
		int v=-1;
		for(int j=0;j<n;j++)
		{
			if(!vis[j] && (vis==-1 || d[j]<d[v]))
				v=j;
		}
		if(d[v]==INF)
			break;
		vis[v]=true;
		for(auto edge:v)
		{
			int to=edge.first;
			int weight=edge.second;
			if(d[to]>d[v]+weight)
			{
				d[to]=d[v]+weight;
				p[to]=v;
			}
		}
	}
}