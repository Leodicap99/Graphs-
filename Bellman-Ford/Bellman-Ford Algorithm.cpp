/*
Suppose that we are given a weighted directed graph G with n vertices and m edges, and some specified vertex v. 
You want to find the length of shortest paths from vertex v to every other vertex.

THIS ANSWER DOESNOT DEAL WITH NEGATIVE CYCLE!
This is the simplest implementation of bellman ford whch doesnt tackle the negative cycles condition.
Time Complexity - O(VE)
*/

struct edge
{
	int a,b,cost;
};
int n,m,v;
vector<edge> e;
const int INF=1e9;

void bellman_ford()
{
	vector<int> d(n,INF);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(d[e[j].a]<INF)
				d[e[j].b]=min(d[e[j].b],d[e[j].a]+e[j].cost);
		}
	}
}
