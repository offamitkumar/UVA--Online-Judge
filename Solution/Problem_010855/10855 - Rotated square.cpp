//  Author : Amit Kumar 
//  Date   : Friday 24 July 2020 03:16:59 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
char big[2000][2000]; 
char small[2000][2000];
char temp[2000][2000];
signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int n , m; 
    while(cin >> n >> m , n+m){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin >> big[i][j];
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                cin >> small[i][j];
            }
        }
        int rotation = 0;
        while(rotation<4){
            int counter{};
            for(int i=0;i<n-m+1;++i){
                for(int j=0;j<n-m+1;++j){
                    bool  matched=true;
                    for(int k=0;k<m && matched;++k){
                        for(int l = 0; l<m && matched;++l){
                            if(small[k][l] != big[i+k][j+l]){
                                matched=false;
                            }
                        }
                    }
                    counter+=matched;
                }
            }
            rotation++;
            cout<<  counter;
            if(rotation!=4){
                cout <<" ";
            }
            for(int i=0; i<m;++i){
                for(int j=0;j<m;++j){
                    temp[j][m-i-1] =small[i][j];
                }
            }
            for(int i=0; i<m;++i){
                for(int j=0;j<m;++j){
                    small[i][j]=temp[i][j];
                }
            }
        }
        cout << '\n'; 
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
