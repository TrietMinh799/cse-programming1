// Lab 1 — C Fundamentals
// Compile and run:  gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
// Task: implement the functions marked TODO until all tests PASS.
#include <stdio.h>

// ---------------------------------------------------------------------------
// Simple test harness (no need to modify)
static int passed = 0, total = 0;
#define CHECK(expr)                                 \
    do {                                            \
        total++;                                    \
        if (expr) {                                 \
            passed++;                               \
            printf("  PASS  %s\n", #expr);          \
        } else {                                    \
            printf("  FAIL  %s\n", #expr);          \
        }                                           \
    } while (0)
// ---------------------------------------------------------------------------

// 1.1 Sum of two numbers
int add(int a, int b) {
    // TODO
    return a + b;
}

// 1.2 Sum of the digits of n (n may be negative: sum_digits(-12) = 3)
int sum_digits(int n) {
    // TODO: use n % 10 to get the last digit, n / 10 to drop the last digit
    if(n < 0) n *= -1;
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum; // TODO: fix the return value
}

// 1.3 n! using a loop (0! = 1)
long factorial(int n) {
    // TODO
    long long result = 1;
    for(int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result; // TODO: fix the return value
}

// 1.4a Recursive Fibonacci: fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2)
long fib_recursive(int n) {
    // TODO
    if(n == 1) return 1;
    if(n == 0) return 0;
    return fib_recursive(n - 1) + fib_recursive(n - 2); // TODO: fix the return value
}

// 1.4b Iterative Fibonacci
long fib_loop(int n) {
    // TODO
    long long dp[n];
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n]; // TODO: fix the return value
}

// 1.5 Return 1 if n is prime, otherwise 0 (numbers < 2 are not prime)
int is_prime(int n) {
    // TODO: only need to try divisors i with i * i <= n
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return 0;
    }
    return 1; // TODO: fix the return value
}

// 1.6 Greatest common divisor (Euclid's algorithm): gcd(a, b) = gcd(b, a % b), gcd(a, 0) = a
int gcd(int a, int b) {
    // TODO
    if(b == 0) return a;
    return gcd(b, a % b); // TODO: fix the return value
}

// 1.7 Leap year
int is_leap_year(int y) {
    // TODO
    if(y % 100 == 0)
        return y % 400 == 0; 
    return y % 4 == 0; // TODO: fix the return value
}

// 1.8 Number of days in a month. You MUST use switch, grouping cases with the same result.
// Return 0 if month is not in 1..12
int days_in_month(int month, int year) {
    // TODO
    if(month < 1 || month > 12) return 0;

    int answer = 0;
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            answer = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            answer = 30;
            break;
        case 2:
            answer = 28 + is_leap_year(year);
            break;
        default:
            answer = 0;
            break;
    }
    return answer; // TODO: fix the return value
}

int main() {
    printf("1.1 add\n");
    CHECK(add(2, 3) == 5);
    CHECK(add(-4, 4) == 0);

    printf("1.2 sum_digits\n");
    CHECK(sum_digits(1234) == 10);
    CHECK(sum_digits(0) == 0);
    CHECK(sum_digits(-12) == 3);

    printf("1.3 factorial\n");
    CHECK(factorial(0) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(15) == 1307674368000L);

    printf("1.4 fibonacci\n");
    CHECK(fib_recursive(0) == 0);
    CHECK(fib_recursive(1) == 1);
    CHECK(fib_recursive(20) == 6765);
    CHECK(fib_loop(0) == 0);
    CHECK(fib_loop(20) == 6765);
    CHECK(fib_loop(80) == 23416728348467685L);

    printf("1.5 is_prime\n");
    CHECK(is_prime(2) == 1);
    CHECK(is_prime(97) == 1);
    CHECK(is_prime(1) == 0);
    CHECK(is_prime(91) == 0);
    CHECK(is_prime(-7) == 0);

    printf("1.6 gcd\n");
    CHECK(gcd(12, 18) == 6);
    CHECK(gcd(17, 5) == 1);
    CHECK(gcd(7, 0) == 7);

    printf("1.7 is_leap_year\n");
    CHECK(is_leap_year(2024) == 1);
    CHECK(is_leap_year(2023) == 0);
    CHECK(is_leap_year(1900) == 0);
    CHECK(is_leap_year(2000) == 1);

    printf("1.8 days_in_month\n");
    CHECK(days_in_month(1, 2023) == 31);
    CHECK(days_in_month(4, 2023) == 30);
    CHECK(days_in_month(2, 2023) == 28);
    CHECK(days_in_month(2, 2024) == 29);
    CHECK(days_in_month(13, 2024) == 0);

    printf("\nResult: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
