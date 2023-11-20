#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    for (int i=2; i<=sqrt(n); ++i){
        if (n % i == 0)
        {
            return false;
        }    
    } 
    return true;
}

int main() {
    int L, sum, count;
    cin >> L;
    sum = count = 0;
    for (int i=2; sum + i <= L; ++i)
        if (isPrime(i)) {
            sum += i;
            ++count;
            cout << i << '\n';
        }
    cout << count << endl;
    return 0;
}