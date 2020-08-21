#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int N = 1000000;
int lp[N+1];
vector<int> pr;
set<int>Pr;
void linear_sieve(void){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
            Pr.insert(i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    linear_sieve(); 
    int n; 
    while(cin >> n,n){
        cout << n <<" = ";
        for(auto&itr:pr){
            if(Pr.find(n - itr)!=Pr.end()){
                cout << itr <<" + " << n - itr << '\n'; 
                break;
            }
        }
    }
    return 0;
}
