Given a connected graph with N vertices and M edges. The task is to print the lexicographically smallest DFS traversal of the graph starting from 1. 
Note that the vertices are numbered from 1 to N.

Input: N = 5, M = 8, edges[] = {{1, 4}, {3, 4}, {5, 4}, {3, 2}, {1, 5}, {1, 2}, {1, 3}, {3, 5}}
Output: 1 2 3 4 5 

void dfs(vector<int> *adj,vector<bool> &vis,int i)
{
    vis[i]=true;
    cout<<i<<" ";
    for(int &x:adj[i])
    {
        if(!vis[x])
        dfs(adj,vis,x);
    }
}
void printLexoSmall(vector<int> *adj,int n)
{
    for(int i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(adj,vis,i);
    }
}