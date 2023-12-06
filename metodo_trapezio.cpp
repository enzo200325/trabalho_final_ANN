#include <bits/stdc++.h>
#include <utility>

using namespace std; 

const double PI = acos(-1);
pair<double, double> trapezoidal(function<double (double)> f,
                                      double a, double b,
                                      double maxSecondDerivative) {
    const int N = 6; 
    double h = (b - a) / N;
    double sum = 0.5 * (f(a) + f(b)); 

    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += f(x); 
    }

    double integral = sum * h; 
    double errorEstimate = (maxSecondDerivative * (b - a) * (b - a) * (b - a)) / (12 * N * N);

    return {integral, errorEstimate}; // Retorna o par {integral, erro estimado}
}

int main() {
    cout << setprecision(9) << fixed;
    function<double (double)> f = [](double x) {
        return x * x;  
    };
    double maxSecondDerivative = 2.0; // Estimativa do valor maximo da segunda derivada de f
    auto result = trapezoidal(f, -5, 5, maxSecondDerivative);
    cout << "Integral: " << result.first << ", Erro Estimado: " << result.second << endl;
}


