//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 11:57:12 AM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t
int dayInMonths [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}
int countDays(int day, int month, int year) { 
    int counter = 0; 
    for ( int i = 1; i < year; i++ ) {
        counter += (isLeapYear(i) ? 366 : 365);
    } 
    for ( int i = 1; i < month; i++ ) {
        counter += dayInMonths [i - 1];
    } 
    counter += day; 
    if (month > 2 && isLeapYear(year)) counter++; 
    return counter;
}
 
void printOutput(int days) { 
    int year = 1;
    int month = 1; 
    while(days >= 365) {
        days -= (isLeapYear(year) ? 366 : 365); 
        if (days <= 0) {
            days += (isLeapYear(year) ? 366 : 365);
            break;
        } 
        year++;
    } 
    if (days) { 
        if (isLeapYear(year)) dayInMonths [1]++; 
        while (days > dayInMonths [month - 1]) {
            days -= dayInMonths [month - 1];
            month++;
        }
    } 
    cout << days <<' ' << month <<' ' << year << '\n';
}
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
    int futureDays;
    int day;
    int month;
    int year;
    while (cin >> futureDays >> day >> month >> year) {
        if ( futureDays == 0 && day == 0 && month == 0 && year == 0 ) break;
        dayInMonths[1] = 28;
        int totalNumberOfDays = countDays(day, month, year);
        totalNumberOfDays += futureDays;
        printOutput(totalNumberOfDays);
    }
 
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
