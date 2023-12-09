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
        string a, b;
        cin>>a>>b;

        pair<char,char> start = {char(a[0]),char(a[1])};
        pair<char,char> dest = {char(b[0]),char(b[1])};
        vector<pair<int,int>> dirs = {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

        vector<vector<int>> dist(8, vector<int> (8,-1));
        queue<pair<char,char>> bfs;

        vector<vector<bool>> vis (8, vector<bool> (8, false ));
        
        
        bfs.push(start);
        vis[start.first - 'a'][start.second-'1'] = true;
        dist[start.first - 'a'][start.second - '1'] = 0;

        while (bfs.empty() == false) {
            pair<char,char> knight = bfs.front();
            char x = knight.first;
            char y = knight.second;
            bfs.pop();

            for (auto dir : dirs) {
                int dx = dir.first;
                int dy = dir.second;

                if ((x+dx)<'a' || (x+dx)>'h' || (y+dy)<'1' || (y+dy) > '8') continue;

                if (vis[x+dx-'a'][y+dy-'1'] == true) continue;

                bfs.push({x+dx,y+dy});
                dist[x+dx-'a'][y+dy-'1'] = dist[x-'a'][y-'1'] + 1;
                vis[x+dx-'a'][y+dy-'1'] = true;
            }
        }

        cout<<dist[dest.first-'a'][dest.second-'1']<<endl;
        
    }

    return 0;
}