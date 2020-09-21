#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    vector<int>v{ 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361 }; 
    int n;
    while(cin >> n && n) {
        if(find(v.begin() , v.end() , n) != v.end()){
            printf("The number %ld is a Carmichael number.",n);
        } else {
            printf("%ld is normal.", n);
        }
        puts("");
    }
    return 0;
}
