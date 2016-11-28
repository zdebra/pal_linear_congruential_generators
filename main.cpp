#include <iostream>
#include <math.h>

bool* prime_divisors(int m);
int divisor_count(int m);

struct PrimeDivisor{
    int value;
    PrimeDivisor *next;
};

int main() {

    int a_min, a_max, c_min, c_max, m_min, m_max, d;

  /*  std::cin >> a_min;
    std::cin >> a_max;
    std::cin >> c_min;
    std::cin >> c_max;
    std::cin >> m_min;
    std::cin >> m_max;
    std::cin >> d;*/


    int m = 24;
    bool *b = prime_divisors(m);
    for(int i=0; i < m-1; i++) {
        std::cout << i+2 << ": " << b[i] << std::endl;
    }

    return 0;
}

// enhanced eratosthenes sieve
bool* prime_divisors(int n) {
    int size = n-1;
    bool* a = new bool[size];
    for(int i=0; i<size; i++) {
        a[i] = true;
    }
    int sq = ceil(sqrt(n));
    for(int i=2; i<=sq; i++) {
        if(a[i-2]==true) {
            for(int j=i*i; j<=n;j+=i) {
                a[j-2] = false;
            }
            a[i-2] = (n%i) == 0;
        }
    }

    for(int i=sq+1; i<n; i++) {
        a[i-2] = false;
    }

    return a;
}

// using http://stackoverflow.com/questions/110344/algorithm-to-calculate-the-number-of-divisors-of-a-given-number
int divisor_count(int x) {
    int limit = x;
    int numberOfDivisors = 0;

    if (x == 1) return 1;

    for (int i = 1; i < limit; ++i) {
        if (x % i == 0) {
            limit = x / i;
            if (limit != i) {
                numberOfDivisors++;
            }
            numberOfDivisors++;
        }
    }

    return numberOfDivisors;
}