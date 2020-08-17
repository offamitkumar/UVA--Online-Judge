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
    int s ;string a; 
    map<char,vector<string>>f; 
    f['0'] = {
        " - ", // begin
        "| |", // begin -> mid
        "   ", // mid 
        "| |", // mid -> end
        " - "  // end 
    };
    f['1'] = {
        "   ", // begin
        "  |",
        "   ", // mid 
        "  |",
        "   "  // end 
    };
    f['2'] = {
        " - ", // begin
        "  |",
        " - ", // mid 
        "|  ",
        " - "  // end 
    };
    f['3'] = {
        " - ", // begin
        "  |",
        " - ", // mid 
        "  |",
        " - "  // end 
    };
    f['4'] = {
        "   ", // begin
        "| |",
        " - ", // mid 
        "  |",
        "   "  // end 
    };
    f['5'] = {
        " - ", // begin
        "|  ",
        " - ", // mid 
        "  |",
        " - "  // end 
    };
    f['6'] = {
        " - ", // begin
        "|  ",
        " - ", // mid 
        "| |",
        " - "  // end 
    };
    f['7'] = {
        " - ", // begin
        "  |",
        "   ", // mid 
        "  |",
        "   "  // end 
    };
    f['8'] = {
        " - ", // begin
        "| |",
        " - ", // mid 
        "| |",
        " - "  // end 
    };
    f['9'] = {
        " - ", // begin
        "| |",
        " - ", // mid 
        "  |",
        " - "  // end 
    };
    while(cin >> s >> a){
        if(s+stoi(a)==0){
            break;
        }
        string aa = a;
        int k = 2 * s + 3;
        for(int j=1;j <= k ; ++j){
            for(int l=0;l<(int)aa.size();++l){
                char itr = aa[l];
                for(int i = 0; i < s+2; ++i){
                    if(j==1){ // begin
                        if(i==0){
                            cout << f[itr][0][0] ;
                        }else if(i+1 == s+2){
                            cout << f[itr][0][2] ; 
                        }else{
                            cout << f[itr][0][1] ; 
                        }
                    }else if(k/2>=j){ // begin ->  mid
                        if(i==0){
                            cout << f[itr][1][0] ;
                        }else if(i+1 == s+2){
                            cout << f[itr][1][2] ; 
                        }else{
                            cout << f[itr][1][1] ; 
                        }
                    }else if(k/2+1 == j){ // mid 
                        if(i==0){
                            cout << f[itr][2][0] ;
                        }else if(i+1 == s+2){
                            cout << f[itr][2][2] ; 
                        }else{
                            cout << f[itr][2][1] ; 
                        }
                    }else if(j == k){ // end
                        if(i==0){
                            cout << f[itr][4][0] ;
                        }else if(i+1 == s+2){
                            cout << f[itr][4][2] ; 
                        }else{
                            cout << f[itr][4][1] ; 
                        }
                    }else { // mid -> end 
                        if(i==0){
                            cout << f[itr][3][0] ;
                        }else if(i+1 == s+2){
                            cout << f[itr][3][2] ; 
                        }else{
                            cout << f[itr][3][1] ; 
                        }
                    }
                }
                if(l+1 != (int)aa.size()){
                    cout<<" ";
                }
            }
            cout << '\n'; 
        }
        cout << '\n'; 
    }
    return 0;
}
