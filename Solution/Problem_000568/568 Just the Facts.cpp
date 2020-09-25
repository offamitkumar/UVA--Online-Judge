#include <bits/stdc++.h>
using namespace std;
#define int int64_t
map<int,int> factors(int n) {
    map<int,int>f;
    int j = 2, temp =n; 
    while(j * j <= temp){
        while(temp%j==0){
            f[j]++;
            temp/=j;
        }
        ++j;
    }
    if(temp!=1){
        f[temp]++;
    }
    return f;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    vector<map<int,int>>ff(10001); 
    map<int,int>f; 
    for(int i=2; i<=10000; ++i) {
        map<int,int> ftemp = factors(i); 
        for(auto&itr:ftemp) {
            f[itr.first]+=itr.second;
        }
        int x = min(f[2], f[5]); 
        f[2]-=x;
        f[5]-=x;
        ff[i] = f;
    }
    int n; 
    while(cin >> n) {
        cout << setw(5) << setfill(' ') << n; 
        cout<< " -> "; 
        if(n == 1 || n == 0)  {
            cout << 1 << '\n'; 
        }else {
            map<int,int> factor = ff[n];
            int ans{1};
            for(auto&itr:factor){
                while(itr.second--){
                    ans = (ans*itr.first)%10;
                }
            }
            cout << ans << '\n'; 
        }
    }
    return 0;
}
