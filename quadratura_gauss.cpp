#include <bits/stdc++.h>
using namespace std; 

double quadratura(function<double (double)> f, double a, double b, int n) {
    function<double (double)> F = [&](double t) {
        return ((b - a) / 2) * f(((b - a)/2)*t + ((b + a)/2)); 
    }; 

    const double sqrt3 = sqrt(3); 
    vector<double> A = {1, 1}; 
    vector<double> t = {-1/sqrt3, 1/sqrt3}; 

    assert(n <= (int)A.size()*2 - 1); 

    // n <= k*2 - 1
    // n + 1 <= k * 2
    // n+1 / 2 <= k 
    double ret = 0; 
    int m = n/2 + 1; 
    for (int i = 0; i < m; i++) {
        ret += A[i]*F(t[i]); 
    } 

    return ret; 
} 

int main() {
    function<double (double)> f = [](double x) {
        return x*x; 
    }; 

    cout << setprecision(9) << fixed; 
    cout << quadratura(f, -5, 5, 2) << endl;
}






