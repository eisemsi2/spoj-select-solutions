#include<bits/stdc++.h>
#define vi vector<long long int>
#define loop(a,n) for (int i=a; i<a+n; i++)
#define ll long long
#define print(v,a,n) \
    loop(a,n) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

using namespace std; 

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n,r,m;
        cin>>n>>r>>m;

        vector<int> adj[n+1];

        for (int i=0 ; i< r; i++) {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<pair<bool,int>> vis (n+1, {false,-1});
        bool flag = false;

        for (int i=0; i<m && flag == false; i++) {
            int src, st;
            cin>>src>>st;

            if (vis[src].first == true) {
                flag = true;
                break;
            }

            queue<int> bfs;
            bfs.push(src);
            bfs.push(INT_MAX);
            vis[src] = {true,i};
            while (bfs.empty() == false && st > 0 ) {
                int city = bfs.front();
                bfs.pop();
                if (city == INT_MAX) {
                    if (bfs.empty() == false) bfs.push(INT_MAX);
                    st--;
                    continue;
                }

                for (auto nbcity : adj[city] ) {
                    if ( vis[nbcity].first == true && vis[nbcity].second == i ) continue;
                    else if (vis[nbcity].first == true) {
                        flag = true;
                        break;
                    }

                    bfs.push(nbcity);
                    vis[nbcity] = {true,i};
                }
                // st--;
            }
            
            
        }
        if (flag == false) {
            int i;
            for (i = 1; i<=n; i++) {
                if (vis[i].first == false) break;
            }
            if (i != n+1) {
                flag = true;
            }
        }

        if (flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;

    }

    return 0;
}