#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n , m; 
    int case_counter{1};
    while(cin >> n >> m && (n+m)>=0){
        set<int>s;
        printf("Case %ld: A = %ld, limit = %ld, number of terms = ",case_counter++ , n , m );
        //int term_counter{};
        s.insert(n);
        while(n != 1ll && n <= m){
            if(n&1){
                n = 3ll * n + 1ll;
            }else{
                n/=2ll;
            }
            if(n<=m){
                s.insert(n);
            }
        }
        cout << s.size()<< '\n'; 
    }
    return 0;
}
