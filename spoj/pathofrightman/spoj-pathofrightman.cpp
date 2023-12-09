#include<bits/stdc++.h>
#define vi vector<long long int>
#define ll long long
#define print(v,a,n) \
    for(int i=a; i<a+n; i++) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

using namespace std; 
int n;
int dfstimer = 0;
pair<int,int> s;
pair<int,int> e;
// vector<vector<int>> color;
vector<vector<int>> grid;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        grid.resize(n, vector<int> (n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++ ){
                cin>>grid[i][j];
            }
        }

        cin>>s.first;
        cin>>s.second;
        cin>>e.first;
        cin>>e.second;
        // color.clear();
        // color.resize(n, vector<int> (n, 0));

        // vector<vector<int>> dp (n, vector<int> (n,-1));
        // vector<vector<vector<int>>> dp (n, vector<vector<int>> (n, vector<int> (1<<10, -1)));

        ll min = 1E18;

        for (int i=0; i<1025; i++) {
            int bm = i;
            vector<vector<int>> color (n, vector<int> (n, 0));

            if ((bm & (1<<grid[s.first][s.second])) == 0) continue;
            queue<pair<int,int>> bfs;
            bfs.push(s);
            color[s.first][s.second] = 1;

            bool pathfound = false; 
            while (bfs.empty() == false && pathfound == false) {
                pair<int,int> node = bfs.front();
                bfs.pop();

                if (node == e) {
                    pathfound = true;
                    break;
                }

                int x = node.first;
                int y = node.second;

                for (auto dir : dirs) {
                    int dx = dir.first;
                    int dy = dir.second;

                    if (x+dx >=n || x+dx < 0 || y+dy>=n || y+dy<0) continue;
                    
                    if (color[x+dx][y+dy] == 1) continue;

                    if ((bm & (1<<grid[x+dx][y+dy])) == 0) continue;

                    color[x+dx][y+dy] = 1;
                    bfs.push({x+dx,y+dy});
                }
            }

            if (pathfound == true) {
                int cnt = __builtin_popcount(bm);
                if (cnt < min) min = cnt;
            }

        }

        cout<<min<<endl;
         
    }

    return 0;
}