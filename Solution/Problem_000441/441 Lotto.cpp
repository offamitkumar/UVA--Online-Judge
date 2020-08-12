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
    int k; 
    bool more = false;
    while(cin>>k,k){
        if(more){
            cout << '\n'; 
        }
        more = true;
        vector<int>s(k); 
        for(auto&itr:s)cin >> itr; 
//        sort(s.begin(),s.end()); weak test cases
        for(int a = 0; a<k; ++a)
            for(int b =a+1; b<k;++b)
                for(int c =b+1; c<k; ++c)
                    for(int d = c+1; d<k;++d)
                        for(int e=d+1; e<k;++e)
                            for(int f=e+1;f<k;++f){
                                cout << s[a] <<' ' << s[b] << ' ' << s[c] << ' ' << s[d] <<' ' << s[e] <<' ' << s[f]<<'\n'; 
                            }

    }
    return 0;
}
