#include<bits/stdc++.h>
#define vi vector<long long int>
#define ll long long
#define print(v,a,n) \
    for(int i=a; i<a+n; i++) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

using namespace std; 
int dfstimer = 0;
vector<vector<int>> color;
vector<vector<int>> timein;
vector<vector<int>> timeout;
vector<vector<char>> grid;
int n,m;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(pair<int,int> src, int &sheep, int &wolf, bool &escape) {
    int i = src.first;
    int j = src.second;
    color[i][j] = 1;
    timein[i][j] = dfstimer++;
    if (grid[i][j] == 'k') sheep++;
    if (grid[i][j] == 'v') wolf++;
    if (i == 0 || j == 0 || i == n-1 || j == m-1) escape = true;

    for (auto dir : dirs) {
        int dx = dir.first;
        int dy = dir.second;

        if (i+dx >= n || j+dy >= m || i+dx <0 || j+dy <0) continue;
        if (grid[i+dx][j+dy] == '#') continue;

        if (color[i+dx][j+dy] == 0) 
            dfs({i+dx,j+dy}, sheep, wolf, escape);
    }
    color[i][j] = 2;
    timeout[i][j] = dfstimer++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        cin>>n>>m;

        grid.resize(n, vector<char> (m));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin>>grid[i][j];
            }
        }

        timein.resize(n, vector<int> (m));
        timeout.resize(n, vector<int> (m));
        color.resize(n,vector<int> (m,0));

        int ss = 0, ws = 0; 
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int sheep = 0, wolf = 0;
                bool escape = false;
                if (color[i][j] == 0 && grid[i][j] != '#') {
                    dfs({i,j}, sheep, wolf,escape);
                }

                if (escape == true) {
                    ss += sheep;
                    ws += wolf;
                }
                else {
                    if (sheep > wolf) {
                        ss += sheep;
                    }
                    else {
                        ws += wolf;
                    }
                }
                
            }
        }

        cout<<ss<<" "<<ws;
        




    }

    return 0;
}