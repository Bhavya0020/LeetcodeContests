#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int

class Solution {
public:
    int p = 0;  // Variable to keep a count of number of primes from 1 to n

    void sieves(int n){     // Sieve Of eratosthenes to calculate number of primes in O(n)
        vector<bool> v(n+1, true);
        v[0] = false;
        v[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(v[i]){
                for(int j = i * i; j <= n; j+= i){
                    v[j] = false;
                }
            }
        }
        for(int i = 0; i <= n; i++){
            if(v[i]){
                p++;
            }
        }
    }
    const int mod = 1e9+7;  // Modulo
    long long fact(int n){  // Factorial function with modulo 
        long long a = 1;
        for(int i = 1; i <= n; i++){
            a = ((a % mod) * (i % mod)) %mod;
        }
        return a;
    }
    int numPrimeArrangements(int n) {
        sieves(n);
        // The number of Prime arrangements are factorial of p into factorial of n - p 
        return (int)(((fact(p) % mod) * (fact(n - p) % mod)) % mod);    
    }
};

void testcase(){
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
