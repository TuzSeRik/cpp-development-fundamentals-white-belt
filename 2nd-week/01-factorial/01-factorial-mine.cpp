// Simple recursive realisation of factorial
int Factorial(int x) {
    int result = 1;

    for (int i = 1; i <= x; ++i) {
        result *= i;
    }

    return result;
}
