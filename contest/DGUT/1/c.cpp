#include<bits/stdc++.h>

using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    double x1, x2;
    x1=min(((-b+sqrt(delta))/(2*a)),((-b-sqrt(delta))/(2*a)));
    x2=max(((-b+sqrt(delta))/(2*a)),((-b-sqrt(delta))/(2*a)));
    if(x1==x2){
        printf("x1=x2=%.5lf\n", x1);
    }else if(delta<0){
        printf("No answer!\n");
    }else{
        printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
    }
    return 0;
}