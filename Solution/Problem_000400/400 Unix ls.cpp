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
        int x = 0;
        for(int i=0; i<n;++i){
            cin >> v.at(i);
            x = max(x , (int)v.at(i).size());
        }
        sort(v.begin(), v.end()); 
        cout<< string(60, '-') << '\n'; 
        int wid=x;
        int counter = 1;
        while(wid+x+2<=60){
            ++counter;
            wid+=(x+2);
        }
        int k = ceil((double)n/(double)counter);
        for(int i=0; i<k; ++i){
            int ttt = counter;
            for(int j=i;j<n; j+=k){
                if(ttt==0){
                    int t = v.at(j).size(); 
                    cout << v.at(j); 
                    for(int l = t;l<x; ++l){
                        cout<<" ";
                    }
                }else{
                    int t = v.at(j).size(); 
                    cout << v.at(j); 
                    for(int l = t;l<x+2; ++l){
                        cout<<" ";
                    }

                }
            }
            cout << '\n'; 
        }
    }
    return 0;
}
