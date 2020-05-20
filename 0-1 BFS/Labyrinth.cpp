/*
You are playing some computer game. One of its levels puts you in a maze consisting of n lines, each of which contains m cells. Each cell either is free or is occupied by an obstacle. The starting cell is in the row r and column c. In one step you can move one square up, left, down or right, if the target cell is not occupied by an obstacle. You can't move beyond the boundaries of the labyrinth.

Unfortunately, your keyboard is about to break, so you can move left no more than x times and move right no more than y times. There are no restrictions on the number of moves up and down since the keys used to move up and down are in perfect condition.

Now you would like to determine for each cell whether there exists a sequence of moves that will put you from the starting cell to this particular one. How many cells of the board have this property?
Input

The first line contains two integers n, m (1 ≤ n, m ≤ 2000) — the number of rows and the number columns in the labyrinth respectively.

The second line contains two integers r, c (1 ≤ r ≤ n, 1 ≤ c ≤ m) — index of the row and index of the column that define the starting cell.

The third line contains two integers x, y (0 ≤ x, y ≤ 109) — the maximum allowed number of movements to the left and to the right respectively.

The next n lines describe the labyrinth. Each of them has length of m and consists only of symbols '.' and '*'. The j-th character of the i-th line corresponds to the cell of labyrinth at row i and column j. Symbol '.' denotes the free cell, while symbol '*' denotes the cell with an obstacle.

It is guaranteed, that the starting cell contains no obstacles.
Output

Print exactly one integer — the number of cells in the labyrinth, which are reachable from starting cell, including the starting cell itself.

Input
4 5
3 2
1 2
.....
.***.
...**
*....

Output
10
*/

    #include<bits/stdc++.h>
    using namespace std;
    int n,m,L,R,sx,sy,ans=0;;
    char a[2005][2005],v[2005][2005];
    struct A{int x,y,l,r;};
    deque<A> q;
    void go(int x,int y,int l,int r,char t){
    	if(a[x][y]=='.'&&!v[x][y]&&l<=L&&r<=R){
    		v[x][y]=1;
    		if(t) q.push_front(A{x,y,l,r});
    		else q.push_back(A{x,y,l,r});
    	}
    }
    int main(){
    	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&L,&R);
    	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
    	q.push_front({sx,sy,0,0});v[sx][sy]=1;
        A u;
    	while(q.size())
        {
    		u=q.front();q.pop_front();++ans;
    		go(u.x-1,u.y,u.l,u.r,1);
    		go(u.x+1,u.y,u.l,u.r,1);
    		go(u.x,u.y-1,u.l+1,u.r,0);
    		go(u.x,u.y+1,u.l,u.r+1,0);
    	}
        printf("%d",ans);
        return 0;
    }