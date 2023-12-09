#include<bits/stdc++.h>
#define vi vector<long long long long>
#define ll long long
#define print(v,a,n) \
    for(long long i=a; i<a+n; i++) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

using namespace std; 

long long n,m;

vector<pair<int,int>> directions = {{1,0}, {0,1},{-1,0},{0,-1}};

void dfs(pair<long long,long long> src, vector<vector<char>> sea, vector<vector<bool>> &vis,long long &sz) {
    int a = src.first;
    int b = src.second;
    vis[a][b] = true;
    sz++;
    
    for (auto dir: directions) {
        int dx = dir.first;
        int dy = dir.second;

        if (a+dx >= n || a+dx <0 || b+dy >=m || b+dy < 0) continue;

        if (vis[a+dx][b+dy] == true) continue;
        if (sea[a+dx][b+dy] != '#') continue;

        dfs({a+dx,b+dy},sea,vis,sz);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        long long answer = 0;
        cin>>n>>m;
        long long size = n*m;
        vector<vector<char>> sea(n,vector<char> (m));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin>>sea[i][j];
            }
        }

        vector<vector<bool>> vis(n, vector<bool> (m));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (sea[i][j] == '#' && vis[i][j] == false) {
                    long long sz=0;
                    dfs({i,j},sea,vis,sz);
                    answer += sz*sz;
                }
            }
        }

        // cout<<answer<<endl;
        
        long long x = __gcd(answer,size);

        answer = answer/x;
        size = size/x;

        if (size == 1) cout<<answer<<endl;
        else cout<<answer<<" / "<<size<<endl;
    }

    return 0;
}