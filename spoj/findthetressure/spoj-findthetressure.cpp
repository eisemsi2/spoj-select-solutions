#include<iostream>
#include<vector>
#include<queue>
// #include<set>
#include<algorithm>
// #define vi vector<long long int>
// #define loop(a,n) for (int i=a; i<a+n; i++)
// #define ll long long
// #define print(v,a,n) \
//     loop(a,n) {   \
//         std::cout<<v[i]<<" "; \
//     }   \
//     cout << endl;   \

using namespace std; 

int main() {
    int t;
    cin>>t;
    while (t--) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin>>n;
        vector<int> adj[n+1];

        for (int i=1; i<n; i++) {
            int x;
            cin>>x;
            for (int j=0; j<x; j++) {
                int y;
                cin>>y;
                adj[i].push_back(y);
            }
        }
        for (int i=1; i<n; i++) {
            sort(adj[i].begin(),adj[i].end());
        }

        queue<int> bfs;
        vector<bool> vis (n+1,false);
        // vector<int> dist(n+1,0);
        vector<int> parent (n+1,-1);
        bool flag = false;

        bfs.push(1);
        vis[1] = true;

        while (bfs.empty() == false && flag == false) {
            int node = bfs.front();
            bfs.pop();

            for (auto nb : adj[node]) {
                if (vis[nb] == true) continue;
                
                bfs.push(nb);
                // dist[nb] = dist[node] + 1;
                vis[nb] = true;
                parent[nb] = node;
                if (nb == n) {
                    flag = true;
                    break;
                }
            }
        }
        if (vis[n] == false) {
            cout<<-1<<endl;
        }
        else{
            vector<int> path;
            int dist = 0;
            // path.push_back(n);
            while (n != 1) {
                n = parent[n];
                path.push_back(n);
                dist++;
            }
            reverse(path.begin(),path.end());
            cout<<dist<<endl;
            for (int i=0; i<path.size(); i++) {
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}