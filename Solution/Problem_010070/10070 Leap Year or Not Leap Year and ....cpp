#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int div400(string &n) {
    int num{};
    for (int i=0; i<(int)n.size(); ++i) {
        num*=10; 
        num+= (n[i]-'0');
        num%=400;
    }
    return !(num);
}
int div4(string &n) {
    int num{};
    for (int i=0; i<(int)n.size(); ++i) {
        num*=10; 
        num+= (n[i]-'0');
        num%=4;
    }
    return !(num);
}
int div100(string &n) {
    int num{};
    for (int i=0; i<(int)n.size(); ++i) {
        num*=10; 
        num+= (n[i]-'0');
        num%=100;
    }
    return !(num);
}
bool leap_year(string &n) {
    if  (div400(n)) {
        return true;
    } else if(div4(n) && (!div100(n))) {
        return true;
    }
    return false;
}
bool hulu(string &n) {
    int num{};
    for (int i=0; i<(int)n.size(); ++i) {
        num*=10; 
        num+= (n[i]-'0');
        num%=15;
    }
    return !(num);
}
bool bulu(string &n) {
    int num{};
    for (int i=0; i<(int)n.size(); ++i) {
        num*=10; 
        num+= (n[i]-'0');
        num%=55;
    }
    return !(num);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string n; 
    bool more=false;
    while (cin >> n) {
        if(more) {
            puts("");
        }
        more = true;
        bool ok1{false}, ok2{false}, ok3{false};
        if (leap_year(n)) {
            ok1 = true;
            puts("This is leap year.");
        }
        if (hulu(n)) {
            ok2 =true;
            puts("This is huluculu festival year.");
        }
        if (ok1 && bulu(n)) {
            ok3 = true;
            puts("This is bulukulu festival year.");
        }
        if ((!ok1) && (!ok2) && (!ok3)) {
           puts("This is an ordinary year.");
        }
    }
    return 0;
}
