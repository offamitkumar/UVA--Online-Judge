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
    int x; 
    int case_counter{1};
    vector<int>v(12); 
    while(cin >> x, x>=0){
        cout<<"Case "<<case_counter++<<":\n";
        for(auto&itr:v){
            cin >> itr;
        }
        int pc{x};
        for(int i=0,y; i<12; ++i){
            cin >> y; 
            if(pc>=y){
                cout<<"No problem! :D"<<'\n';
                pc-=y;
            }else{
                cout<<"No problem. :("<<'\n';
            }
            pc+=v.at(i);
        }
    }
    return 0;
}
