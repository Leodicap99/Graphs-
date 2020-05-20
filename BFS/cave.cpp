/*
The cave has N rooms and M passages. The rooms are numbered 1 to N, and the passages are numbered 1 to M. Passage i connects Room Ai and Room Bi bidirectionally. One can travel between any two rooms by traversing passages. Room 1

is a special room with an entrance from the outside.

It is dark in the cave, so we have decided to place a signpost in each room except Room 1

. The signpost in each room will point to one of the rooms directly connected to that room with a passage.

Since it is dangerous in the cave, our objective is to satisfy the condition below for each room except Room 1

.

    If you start in that room and repeatedly move to the room indicated by the signpost in the room you are in, you will reach Room 1

    after traversing the minimum number of passages possible.

Determine whether there is a way to place signposts satisfying our objective, and print one such way if it exists.
INPUT
4 4
1 2
2 3
3 4
4 2

OUTPUT
Yes
1
2
2
*/

    #include<bits/stdc++.h>
    using namespace std;
    using ll=long long;  
    const int e = 2e5 + 69;
    vector<ll>adj[e];
    ll par[e];
    bool vs[e];
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        vs[i] = false;
    }
    queue<ll>q;
    q.push(1);
    vs[1] = true;
    while(q.size() != 0){
        ll cur = q.front();
        q.pop();
        for(auto j : adj[cur]){
            if(vs[j] == false){
                par[j] = cur;
                vs[j] = true;
                q.push(j);
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(par[i] == 0){
            cout <<"No";
            return 0;
        }
    }
    cout << "Yes" <<"\n";
    for(int i=2; i<=n; i++){
        cout << par[i] <<"\n";
    }
    }