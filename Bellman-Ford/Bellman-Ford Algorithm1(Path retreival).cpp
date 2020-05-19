/*
Let us now consider how to modify the algorithm so that it not only finds the length of shortest paths, but also allows to reconstruct the shortest paths.
*/
void bellman_ford()
{
	vector<int> d(n,INF);
	vector<int> p(n,-1);
	d[v]=0;
	for(;;)
	{
		bool ans=false;
		for(int i=0;i<m;i++)
		{
			if(d[e[j].a]<INF)
			{
				if(d[e[j].b]>d[e[j].a]+e[j].cost)
				{
					d[e[j].b]>d[e[j].a]+e[j].cost
					any=true;
					p[e[j].b]=e[j].a;
				}
			}
		}
		if(!any)break;
	}
	if(d[destination]==INF)
	{
		cout<<"NO PATH";
		return;
	}
	vector<int> path;
	for(int i=destination;i!=source;i=p[i])
	{
		path.push_back(i);
	}
	reverse(path.begin(),path.end());
}