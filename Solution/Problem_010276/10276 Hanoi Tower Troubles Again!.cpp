#include <bits/stdc++.h>
using namespace std;
#define int int64_t
set<int>used; 
int ans;
vector<deque<int>>v;
void sol(int n , int counter, int slots){
    if(slots == n){
        return;
    }
    if(v.at(slots).size()==0){
        v.at(slots).push_back(counter); 
        ans++;
        sol(n , counter+1 ,slots );
        return;
    }
    for(int i=0; i<=slots; ++i){
        int x = sqrt(v.at(i).back() + counter); 
        if(x * x == v.at(i).back() + counter){
            v.at(i).push_back(counter); 
            ans++;
            sol(n , counter +1 , slots);
            return; 
        }
    }
    sol(n , counter , slots+1);
    return;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while(t--){
        v.clear();
        int n; cin >> n;
        v.resize(n);
        ans =0; 
        used.insert(0);
        sol(n,1 , 0); 
        cout << ans << '\n'; 
    }
    return 0;
}
