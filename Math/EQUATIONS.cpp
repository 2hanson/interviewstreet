//https://www.interviewstreet.com/challenges/dashboard/#problem/4e14a0058572a

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define LL long long

const LL maxn = 1000005;
const LL mod = 1000007;
LL n;
LL isPrime[maxn]={0};
LL fac[maxn] = {0};
vector<LL> primes;

void primeGen()
{
    LL t;
    for (LL i = 2; i <= n; ++i)
    {
        if (isPrime[i] == 0)
        {
            primes.push_back(i);

            for (LL k = 2; (t = i*k) <= n; ++k)
            {
                isPrime[t] = 1;
            }
        }
    }
}

LL solve()
{
    LL res = 1;
    
    //n*(n-1)*(n-2)*...*3*2*1
   /* for (LL cur = 2; cur <= n; ++cur)
    {
        LL nod = 1;
        LL exponent;
        LL reminder = cur;
        for (LL k = 0; k < primes.size() && reminder>1; ++k)
        {
            exponent = 0;
            while (reminder % primes[k] == 0)
            {
                reminder = reminder / primes[k];
                exponent += 2;
            }
            fac[k] += exponent;
        }
    }*/
    for (LL k = 0; k < primes.size() && primes[k]<=n; ++k)
    {
        fac[k] = 0;
        LL temp = primes[k];

        while (temp <= n)
        {
            fac[k] += n/temp;
            temp *= primes[k];
        }

    }

    for (LL i = 0; i < primes.size(); ++i)
    {
        if (fac[i]!=0)
        {
            res *= (2*fac[i]+1);
            res %= mod;
        }
    }

    return res % mod;
}

int main()
{
    cin>>n;
    if (n == 1)
        cout<<"1"<<endl;
    else
    {
        primeGen();
        cout<<solve()<<endl;
    }
    return 0;
}

