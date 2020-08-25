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
    int n; 
    while(cin >> n){
        vector<string>v(n); 
        int max_len = 0;
        for(int i=0; i<n;++i){
            cin >> v.at(i);
            max_len = max(max_len , (int)v.at(i).size());
        }
        sort(v.begin(), v.end()); 
        cout<< string(60, '-') << '\n'; 
        int wid=max_len;
        int counter = 1;
        while(wid+max_len+2<=60){
            ++counter;
            wid+=(max_len+2);
        }
        int row = ceil((double)n/(double)counter);
        for(int i=0; i<row; ++i){
            for(int j=i;j<n; j+=row){
                int t = v.at(j).size(); 
                cout << v.at(j); 
                for(int l = t;l<max_len+2; ++l){
                    cout<<" ";
                }
            }
            cout << '\n'; 
        }
    }
    return 0;
}
