#include<bits/stdc++.h>
#define vi vector<long long int>
#define ll long long
#define print(v,a,n) \
    for(int i=a; i<a+n; i++) {   \
        std::cout<<v[i]<<" "; \
    }   \
    cout << endl;   \

using namespace std; 

int dfs(ll src, vector<bool> &vis, vector< pair<int,int> > adj[], vector<ll> &data) {
    vis[src] = true;
    int notvisted = 0;
    for (auto nb : adj[src] ) {
        if (vis[nb.first] == false) {
            notvisted ++;
        }
    }
    if (notvisted == 0) {
        data[src] = 0;
        return data[src];
    }

    int maxdog = 0;

    for (auto nb : adj[src]) {
        if (vis[nb.first] == true)  continue;

        if (data[nb.first] == -1) dfs(nb.first,vis,adj,data);
        if (data[nb.first] + nb.second > maxdog) maxdog = data[nb.first] + nb.second;
    }

    return data[src] = maxdog ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;

        vector<pair<int,int>> adj[n+1];

        ll sum = 0;

        for (int i=0; i<n-1; i++) {
            int x,y,z;
            cin>>x>>y>>z;

            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
            sum += z;
        }
        vector<bool> vis(n+1, false);

        vector<ll> data (n+1,-1);
        dfs(1,vis,adj,data);
        // vector<int> ans (n+1,0);
        // for (int i=1; i<=n; i++) {
        //     int maxdog = data[i];
        //     for (auto nb : adj[i]) {
        //         if (nb.second + data[nb.first] > maxdog) maxdog = nb.second+ data[nb.first];
        //     }
        //     ans[i] = maxdog;
        // }
        print(data,1,n);
        // print(ans,1,n);        
        // for (int i=1; i<n+1; i++) {
        //     if (sum - data[i] > data[i]) {
        //         ans[i] = sum-data[i];
        //     }
        //     else ans[i] = data[i];
        // }
        // print(ans,1,n);
    }

    return 0;
}