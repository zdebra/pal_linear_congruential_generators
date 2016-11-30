#include <iostream>
#include <math.h>

struct PrimeDivisor{
    unsigned int value;
    unsigned int count;
    PrimeDivisor *next;
    PrimeDivisor *prev;
};

PrimeDivisor* prime_divisors(unsigned int m);
PrimeDivisor* get_tail(PrimeDivisor *head);
bool is_coprime(unsigned int a, unsigned int b);
unsigned int divisors_count(PrimeDivisor* head, unsigned int m);

int main() {
/*
    unsigned int a_min, a_max, c_min, c_max, m_min, m_max, d;

    std::cin >> a_min;
    std::cin >> a_max;
    std::cin >> c_min;
    std::cin >> c_max;
    std::cin >> m_min;
    std::cin >> m_max;
    std::cin >> d;


    for(unsigned int m=m_min; m<m_max+1; m++) {

        PrimeDivisor *cur = prime_divisors(m);
        int divisors = divisors_count(cur, m);

    }*/


    unsigned int m = 24;
    PrimeDivisor *head = prime_divisors(m);
    PrimeDivisor *cur = head;
    while(cur != NULL && cur->value!=0) {
        std::cout << cur->value << std::endl;
        cur = cur->next;
    }

    std::cout << "--" << std::endl << divisors_count(head, m)  << std::endl;





}

// enhanced eratosthenes sieve
PrimeDivisor* prime_divisors(unsigned int n) {
    PrimeDivisor *cur = new PrimeDivisor();
    PrimeDivisor *first = cur;
    unsigned int size = ceil(n/2);
    bool* a = new bool[size];
    for(unsigned int i=0; i<size; i++) {
        a[i] = true;
    }
    unsigned int sq = ceil(sqrt(n));
    for(unsigned int i=2; i<=sq; i++) {
        if(a[i-2]) {
            for(unsigned int j=i*i; j<=(size+2);j+=i) {
                a[j-2] = false;
            }

            //push it man
            if((n%i) == 0) {
                cur->value = i;
                cur->next = new PrimeDivisor();
                PrimeDivisor *tmp = cur;
                cur = cur->next;
                cur->prev = tmp;
            }
        }
    }
    for(unsigned int i=sq+1;i<=size;i++) {
        if(a[i-2] && n%i==0) {
            cur->value = i;
            cur->next = new PrimeDivisor();
            cur = cur->next;
        }
    }

    delete[] a;

    return first;
}

unsigned int divisors_count(PrimeDivisor* head, unsigned int m) {

    if(m==1) {
        return 1;
    }

    unsigned int count = 1;

    PrimeDivisor *cur = head;
    while(cur != NULL && cur->value != 0) {

        unsigned int sub = m;
        while(sub%cur->value == 0) {
            sub /= cur->value;
            cur->count++;
        }

        count *= (cur->count + 1);
        cur = cur->next;

    }

    if(count==1) {
        count++;
    }

    return count;



}

PrimeDivisor* get_tail(PrimeDivisor *head) {
    PrimeDivisor *cur = head;
    while(cur->next != NULL && cur->next->value != 0) {
        cur = cur->next;
    }
    return cur;
}

bool is_coprime(unsigned int a, unsigned int b) {
    return a%b==0 || b%a==0;
}