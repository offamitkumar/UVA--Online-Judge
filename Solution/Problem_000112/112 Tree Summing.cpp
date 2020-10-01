#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool ok = false; 
int sol(int current_sum , int target , char ch) {
    while (ch==' ' || ch == '\n') {
        cin >> ch;
    }
    if (ch == '(') {
        int num{};
        int negNum = 1;
        bool numFound=false;
        while (cin >> ch) {
            if (ch >='0' && ch<='9') {
                num*=10; 
                num+=(ch-'0');
                numFound = true;
            } else if (ch == '-') {
                negNum = -1;
            } else {
                break;
            }
        }
        num*=negNum;
        while (ch == ' ' || ch == '\n') {
            cin >> ch;
        }
        if (!numFound) {
            return 0;
        }
        int leftSum = sol(current_sum + num , target , ch); 
        while (cin >> ch) {
            if (ch == '(') {
                break;
            }
        }
        int rightSum = sol(current_sum+ num , target, ch); 
        while (cin >> ch) {
            if (ch == ')') {
                break;
            }
        }
        if (leftSum == 0 && rightSum == 0) {
            if (current_sum+ num == target) {
                ok = true;
            }
        }
        return 1;
    }
    return 0;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int I; 
    while (cin >> I) {
        ok = false;
        char ch;
        cin >> ch; 
        sol(0 , I, ch);
        if (ok) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
