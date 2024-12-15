#include <stdio.h>
#include <math.h>
#include <string>

double f(double x) {
    return sqrt(1 - x * x);
}

double integral(double a, double b, int n) {
    double S = 0;
    for(int k = 1; k < n; k++) {
        S += ((f(a + (b - a) * k / n) + f(a + (b - a) * (k - 1) / n) ) * (b - a) / n) / 2;
        if (k % 100000 == 0) {
            printf("[%d/%d] %.15f\n", k, n, S);
        }
    }
    return S;
}

int main(int argc, char* argv[]) {
    int n = std::atoi(argv[1]);
    printf("%.15f\n", integral(0, 1, n) * 4);

}
