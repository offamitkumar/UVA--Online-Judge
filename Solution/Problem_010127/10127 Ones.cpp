#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    while(cin >> n){
        int x = 1;
        int counter{1};
        while(x%n!=0){
            counter+=1;
            x*=10;
            x++;
            x%=n;
        }
        cout << counter << '\n'; 
    }
    return 0;
}
