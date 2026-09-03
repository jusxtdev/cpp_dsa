#include <iostream>

using namespace std;

int main() {
    long long a,b,c,d;
    cin >> a >> b >> c >> d;

    long long res;
    long long temp;

    /*POSSIBLE COMBINATIONS ( +, -, *) -- no repetiton
    + -
    + *

    - +
    - *
    
    * +
    * -
    */
   if (
    a + b - c == d ||
    a + b * c == d ||
    a - b + c == d ||
    a - b * c == d ||
    a * b + c == d ||
    a * b - c == d 
   ){
    cout << "YES";
   }else {
    cout << "NO";
   }
}