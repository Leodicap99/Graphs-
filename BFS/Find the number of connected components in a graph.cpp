Finding connected components in a graph using BFS

    void bfs(vector<vector<int>> &graph,vector<bool> &vis,int i)
    {
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto &x:graph[t])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int connected_components=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bfs(graph,vis,i);
                connected_components++;
            }
        }
        return connected_components;
    }