Checking a graph for acyclicity and finding a cycle in O(E)
Consider a directed or undirected graph without loops and multiple edges. We have to check whether it is acyclic, and if it is not, then find any cycle.

Algorithm
We will run a series of DFS in the graph. Initially all vertices are colored white (0). From each unvisited (white) vertex, start the DFS, mark it gray (1) while entering and mark it black (2) on exit. 
If DFS moves to a gray vertex, then we have found a cycle (if the graph is undirected, the edge to parent is not considered). 
The cycle itself can be reconstructed using parent array.

vector<vector<int>> graph;
vector<int> color,parent;
int cycle_start,cycle_end;

bool dfs(int v)
{
	color[v]=1;
	for(auto &to:graph[v])
	{
		if(color[v]==0)
		{
			parent[v]=u;
			if(dfs(u))
				return true;
		}
		else if(color==1)
		{
			cycle_start=to;
			cycle_end=v;
		}
	}
}
void find_cycle()
{
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for(int i=0;i<n;i++)
    {
    	if(color[i]==0 && dfs(i))
    		break;
    }	
    if(cycle_start==-1)
    	cout<<"NO CYCLE"<<endl;
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
