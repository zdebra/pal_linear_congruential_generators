#include <iostream>
#include <math.h>

struct PrimeDivisor{
    unsigned int value;
    PrimeDivisor *next;
};

PrimeDivisor* prime_divisors(unsigned int m);
unsigned int divisor_count(unsigned int m);
bool is_coprime(unsigned int a, unsigned int b);


int main() {

    unsigned int a_min, a_max, c_min, c_max, m_min, m_max, d;

    std::cin >> a_min;
    std::cin >> a_max;
    std::cin >> c_min;
    std::cin >> c_max;
    std::cin >> m_min;
    std::cin >> m_max;
    std::cin >> d;

    unsigned int total = 0;
    for(unsigned int m = m_min; m<=m_max; m++) {

        if(divisor_count(m) >= d) {
            PrimeDivisor *head = prime_divisors(m);
            for(unsigned int c = c_min; c<=c_max; c++) {

                if(is_coprime(m,c)) {

                    for(unsigned int a = a_min; a <= a_max; a++) {
                        PrimeDivisor *cur = head;
                        bool stop = false;
                        if(cur->value != 0) {
                            do {

                                if ((a - 1) % cur->value != 0) stop = true;

                            } while ((cur->next != NULL) && cur->value != 0 && !stop);
                        }

                        if(!stop) {
                            if(m%4==0) {
                                if((a-1)%4==0) total++;
                            } else {
                                total++;
                            }
                        }

                    }

                }

            }

            //todo delete prime divisors from memory here.

        }

    }

    std::cout << total;


}

// enhanced eratosthenes sieve
// todo: maybe there is not neccesary to use whole sized array (just a half should be enough)
PrimeDivisor* prime_divisors(unsigned int n) {
    PrimeDivisor *cur = new PrimeDivisor();
    PrimeDivisor *first = cur;
    unsigned int size = n-1;
    bool* a = new bool[size];
    for(unsigned int i=0; i<size; i++) {
        a[i] = true;
    }
    unsigned int sq = ceil(sqrt(n));
    for(unsigned int i=2; i<=sq; i++) {
        if(a[i-2]) {
            for(unsigned int j=i*i; j<=n;j+=i) {
                a[j-2] = false;
            }

            //push it man
            if((n%i) == 0) {
                cur->value = i;
                cur->next = new PrimeDivisor();
                cur = cur->next;
            }
        }
    }
    for(unsigned int i=sq+1;i<=ceil(n/2);i++) {
        if(a[i-2] && n%i==0) {
            cur->value = i;
            cur->next = new PrimeDivisor();
            cur = cur->next;
        }
    }

    delete[] a;

    return first;
}

// using http://stackoverflow.com/questions/110344/algorithm-to-calculate-the-number-of-divisors-of-a-given-number
unsigned int divisor_count(unsigned int x) {
    unsigned int limit = x;
    unsigned int numberOfDivisors = 0;

    if (x == 1) return 1;

    for (unsigned int i = 1; i < limit; ++i) {
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

bool is_coprime(unsigned int a, unsigned int b) {
    return a%b==0 || b%a==0;
}