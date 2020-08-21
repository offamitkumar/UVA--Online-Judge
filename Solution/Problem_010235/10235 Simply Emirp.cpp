#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int N = 999999;
int lp[N+1];
vector<int> pr;
set<int>Pr;
void linear_sieve(void){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
            Pr.insert(i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
/*}}}*/
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; 
    linear_sieve();
    while(cin >> s){
        string temp = s;
        cout << s <<" is ";
        if(Pr.find(stoi(s))!=Pr.end()){
            reverse(s.begin() , s.end()); 
            if(s != temp && Pr.find(stoi(s))!=Pr.end()){
                cout << "emirp.";
            }else{
                cout <<"prime.";
            }
        }else{
            cout <<"not prime.";
        }
        cout << '\n'; 
    }
    return 0;
}
