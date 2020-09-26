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
    map<int,pair<int,int>>ans; 
    int male = 0 , female = 1; 
    for (int i=0; i<=45; ++i) {
        ans[i] = make_pair(male , female+male); 
        int prevYearMale = male , prevYearFemale = female; 
        male = (prevYearMale + prevYearFemale); 
        female = (prevYearMale+1); 
    }
    int n; 
    while(cin >> n && n != -1) {
        cout << ans[n].first << " " << ans[n].second << '\n'; 
    }
    return 0;
}
