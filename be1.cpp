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
        ll x,y,n;
        cin>>x>>y>>n;
        ll res = 1;
        while (y > 0) {
            if (y&1 == 1) {
                res = ((res%n)*(x%n))%n;
            }
            x = ((x%n)*(x%n))%n;
            y = y>>1;
        }
        cout<<res<<endl;
    }

    return 0;
}