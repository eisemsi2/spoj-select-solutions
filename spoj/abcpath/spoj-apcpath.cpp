#include<bits/stdc++.h>
#define vi vector<long long int>
#define ll long long
#define print(v,a,n) \
    for(int i=a; i<a+n; i++) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

using namespace std; 
vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m;

int dfs(pair<int,int> src, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
    int x = src.first;
    int y = src.second;
    vis[x][y] = true;
    int maxlen = 1;

    for (auto d: dir ) {
        int dx = d.first;
        int dy = d.second;

        if (x+dx <0 || x+dx >=n || y+dy<0 || y+dy >=m) continue;
        if (vis[x+dx][y+dy] == true) continue;

        if (grid[x+dx][y+dy] == grid[x][y]+1) {
            vis[x+dx][y+dy] = true;
            int len = 1 + dfs({x+dx,y+dy},vis,grid);
            if (len > maxlen) maxlen = len;
        }
    }

    return maxlen;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    int i = 1;
    while (n!=0 && m!= 0) {
        set<pair<int,int>> As;
        vector<vector<char>> grid (n,vector<char> (m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin>>grid[i][j];
                if (grid[i][j] == 'A') As.insert({i,j});
            }
        }
        
        int maxlen = 0;
        if (As.size() >= 1) {
            for (auto A : As) {
                vector<vector<bool>> vis(n, vector<bool> (m,false));
                int len = dfs(A,vis,grid);
                if (len > maxlen) maxlen = len;
            }
        }

        cout<<"Case "<<i<<": "<<maxlen<<endl;
        i++;
        cin>>n>>m;
    }

    return 0;
}