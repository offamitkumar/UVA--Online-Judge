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
    int Z, L, M, I; 
    int caseCounter=1;
    while (cin >> Z >> I >> M >> L, Z+I+M+L) {
        cout << "Case " << caseCounter++ << ": ";
        set<int>s;
        L = (Z * L + I) % M; // cycle might not begin with seed
        while (s.find(L) == s.end()) {
            s.insert(L);
            L = (Z * L + I) % M;
        }
        cout <<  s.size() << '\n'; 
    }
    return 0;
}
