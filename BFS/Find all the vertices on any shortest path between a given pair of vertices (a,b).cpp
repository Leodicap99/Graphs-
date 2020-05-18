Find all the vertices on any shortest path between a given pair of vertices (s,d)


#include<bits/stdc++.h> 
using namespace std; 
  
// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<vector<int>> &adj, int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
void bfs(int n,vector<int> &d,vector<vector<int>> adj,int s)
{
    queue<int> q;
    vector<bool> used(n);

    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
        }
    }
}
}
void shortest_path(vector<vector<int>> adj,int n,int s,int d)
{
    vector<int> dists(n),distd(n);
    bfs(n,dists,adj,s);
    bfs(n,distd,adj,d);
    for(int i=0;i<n;i++)
    {
        if(dists[i]+distd[i]==dists[d])
        cout<<i<<" ";
    }
}
// Driver code 
int main() 
{ 
    int V = 5; 
    vector<vector<int>> adj(V); 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    shortest_path(adj,5,0,3); 
    return 0; 
} 