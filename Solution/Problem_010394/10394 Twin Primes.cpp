#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int N = 20000000;
int lp[N+1];
set<int>ss;
vector<int> pr;
vector<pair<int,int>>ans;
void linear_sieve(void){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
            ss.insert(i);
            if(ss.find(i-2) != ss.end()) {
                ans.push_back(make_pair(i-2 , i));
            }
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
    ans.push_back(make_pair(-1,-1)); 
    linear_sieve();
    int t; 
    while (cin >> t) {
        printf("(%ld, %ld)\n", ans.at(t).first , ans.at(t).second);
    }
    return 0;
}
