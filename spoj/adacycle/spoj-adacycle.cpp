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
    int n;
    cin>>n;
    vector<int> adj[n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x;
            cin>>x;
            if (x == 1) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i=0; i<n; i++) {
        queue<int> bfs;
        vector<bool> vis (n,false);
        vector<int> dist (n,0);
        bool flag = false;

        bfs.push(i);
        vis[i] = true;

        while (bfs.empty() == false && flag == false) {
            int node = bfs.front();
            bfs.pop();

            for (auto nb : adj[node]) {
                if (nb == i) {
                    flag = true;
                    dist[i] = dist[node] + 1;
                    break;
                }

                if (vis[nb] == true) continue;

                bfs.push(nb);
                vis[nb] = true;
                dist[nb] = dist[node] + 1;
            }
        }

        if (dist[i] == 0) {
            cout<<"NO WAY";
        }
        else {
            cout<<dist[i];
        }
        cout<<endl;


    }

    return 0;
}