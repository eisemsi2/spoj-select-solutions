#include<bits/stdc++.h>
#define vi vector<long long int>
#define ll long long
#define print(v,a,n) \
    for(int i=a; i<a+n; i++) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

#define mp(x,y) make_pair(x,y)
#define p pair<int,int>
using namespace std; 
int m, n;
pair<int,int> s ;
pair<int,int> e ;
vector<vector<char>> grid;
vector<vector<int>> color; 
vector<p> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(p src) {
    color[src.first][src.second] = 1;
    int x = src.first;
    int y = src.second;

    for (auto dir : dirs) {
        int dx = dir.first;
        int dy = dir.second;

        if (x+dx >=m || x+dx <0 || y+dy >=n || y+dy<0) continue;
        if (color[x+dx][y+dy] != 0) continue;
        if (grid[x+dx][y+dy] == '#') continue;

        dfs(mp(x+dx,y+dy));
    }

    color[x][y] = 2;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        cin>>m>>n;
        s = mp(-1,-1);
        e = mp(-1,-1);
        grid.clear();
        grid.resize(m, vector<char> (n));
        bool valid = true;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin>>grid[i][j];
                if ((i == 0 || j == 0 || i == m-1 || j == n-1) && s == mp(-1,-1) && grid[i][j] == '.') s = {i,j};
                else if ((i == 0 || j == 0 || i == m-1 || j == n-1) && e == mp(-1,-1) && grid[i][j] == '.') e = {i,j};
                else if ((i == 0 || j == 0 || i == m-1 || j == n-1) && grid[i][j] == '.' ) valid = false;
            }
        }
        if ( s == mp(-1,-1) || e == mp(-1,-1)) valid = false;
        if (valid == false) {
            cout<<"invalid"<<endl;
            continue;
        }
        color.clear();
        color.resize(m, vector<int> (n, 0));
        dfs(s);
        if (color[e.first][e.second] == 0) {
            cout<<"invalid"<<endl;
        }
        else cout<<"valid"<<endl;

    }

    return 0;
}