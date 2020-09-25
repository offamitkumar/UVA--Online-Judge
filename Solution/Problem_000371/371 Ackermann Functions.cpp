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
    int l , b; 
    while(cin >> l >> b,l+b) {
        cerr << l << b << '\n'; 
        int bestAns{},bestSize{};
        if(l>b)swap(l,b);
        bool okay = false;
        if(l == b) {okay=true;}
        for(int i=l; i<b+okay; ++i){
            int start = i;
            multiset<int>s;
            bool firstTime=true;
            while(firstTime || start != 1){
                firstTime = false;
                s.insert(start);
                if(start&1){
                    start = (start * 3 + 1);
                }else{
                    start = (start/2);
                }
            }
            if(bestSize < (int)s.size()){
                bestSize = s.size(); 
                bestAns = i;
            }
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",l,b,bestAns,bestSize);
    }
    return 0;
}
