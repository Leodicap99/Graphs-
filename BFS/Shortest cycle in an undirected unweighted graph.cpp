Given an undirected unweighted graph. The task is to find the length of the shortest cycle in the given graph. If no cycle exists print -1.

int shortestpath(int n)
{
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		vector<int> p(n,-1);
		vector<int> dist(n,1e6);
		dist[i]=0;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int x=q.top();
			q.pop();
			for(auto &child:graph[x])
			{
				if(dist[child]==1e6)
				{
					dist[child]=dist[x]+1;
					p[child]=x;
					q.push(child);
				}
				else if(p[x]!=child && p[child]!=x)
				{
					ans=min(ans,dist[child]+dist[x]+1);
				}
			}
		} 
	}
	if(ans==INT_MAX)return -1;
	return ans;
}
