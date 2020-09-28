#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool check(int n , int m) {
    set <int> s; 
    while(n){ 
        int x= n%10; 
        if (s.find(x) != s.end()){
            return false;
        }
        s.insert(x);
        n/=10;
    }

    while(m){ 
        int x= m%10; 
        if (s.find(x) != s.end()){
            return false;
        }
        s.insert(x);
        m/=10;
    }
    if(s.find(0) == s.end()) {
        return ((int)s.size()==9);
    } else {
        return ((int)s.size()==10);
    }
}
string fit(int n) {
    string res = to_string(n); 
    if(res.size() < 5) {
        res = ("0"+res);
    }
    return res;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    bool more = false;
    while (cin >> n , n) {
        if(more)
            puts("");
        more =true;
        bool ok=false;
        for(int i=1234; i<=98765; ++i) {
            if (check(i, n*i)){
                string a = fit(i); 
                string b = fit(n*i);
                if(a.size()>5 || b.size()>5 || a.size()<4 || b.size()<4) {
                    continue;
                }
                ok =true;
                printf("%s / %s = %ld\n", max(a,b).c_str() ,min(a,b).c_str() , n);
            }
        }
        if (!ok) {
            printf("There are no solutions for %ld.\n",n);
        }
    }
    return 0;
}
