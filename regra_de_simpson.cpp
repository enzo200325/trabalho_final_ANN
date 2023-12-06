#include <bits/stdc++.h>

const double PI = acos(-1); 
double simpson(std::function<double (double)> f, double a, double b) {
    const int N = 6;  
    double h = (b - a) / N; 
    double res = f(a) + f(b); 
    for (int i = 1; i <= N-1; i++) {
        double x = a + h*i; 
        res += f(x) * ((i & 1) ? 4 : 2); 
    } 
    res *= h/3; 
    return res; 
} 

int main() {
    std::cout << std::setprecision(9) << std::fixed; 
    std::function<double (double)> f = [](double x) {
        return x*x; 
    };  
    std::cout << simpson(f, -5, 5) << std::endl;
}


