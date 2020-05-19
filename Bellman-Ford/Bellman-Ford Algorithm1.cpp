/*
This algorithm is somewhat speeded up: often we already get the answer in a few phases and no useful work is done in remaining phases, just a waste visiting all edges. So, let's keep the flag, to tell whether something changed in the current phase or not, and if any phase, nothing changed, the algorithm can be stopped. (This optimization does not improve the asymptotic behavior, i.e., some graphs will still need all n−1

phases, but significantly accelerates the behavior of the algorithm "on an average", i.e., on random graphs.)

With this optimization, it is generally unnecessary to restrict manually the number of phases of the algorithm to n−1
— the algorithm will stop after the desired number of phases.
*/
void bellman_ford()
{
	vector<int> d(n,INF);
	d[v]=0;
	for(;;)
	{
		bool any=false;
		for(int i=0;i<m;i++)
		{
			if(d[e[j].a]<INF)
			{
				if(d[e[j].b]>d[e[j].a]+e[j].cost)
				{
					d[e[j].b]=d[e[j].a]+e[j].cost;
					any=true;
				}
			}
			i(!any)break;
		}
		i
	}
}