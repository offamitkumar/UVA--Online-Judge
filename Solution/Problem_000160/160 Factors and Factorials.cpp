#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int>pr = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    while(cin >> n,n){
        map<int,int>f;
        for(int i=2; i<= n; ++i){
            int x = i; 
            for(int j=2; j*j<=x; ++j){
                while(x%j==0){
                    f[j]++;
                    x/=j;
                }
            }
            if(x){
                f[x]++;
            }
        }
        cout << setw(3) << setfill(' ') << n <<"! =";
        int x= 1;
        for(int i=0; pr.at(i) <= n; ++i){
            cout << setw(3) << setfill(' ') << f[pr.at(i)];
            if(x == 15 && pr.at(i+1) <=n){
                x = 0;
                cout << '\n' << "      ";
            }
            ++x;
        }
        cout << '\n'; 
    }
    return 0;
}
