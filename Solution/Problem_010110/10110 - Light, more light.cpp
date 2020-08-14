/*
 * 
 * This problem just asks to count the number of factors. Either  we can do it by sqrt(N) method 
 * but that will give TLE. 
 *
 * Observation : Number which are not perfect square have odd number of factors. 
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

unordered_map<int,int>f;
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    while(cin >> n,n){
        int x = sqrt(n);
        if(x*x==n){
            cout <<"yes";
        }else{
            cout <<"no";
        }
        cout << '\n';
    }
    return 0;
}
