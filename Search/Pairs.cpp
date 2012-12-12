//https://www.interviewstreet.com/challenges/dashboard/#problem/4e14b83d5fd12
//
#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;

const int maxn = 100005;
vector<LL> num;

bool binsearch(int left, int right, LL value)
{
    int mid; 
    while (left <= right)
    {
        mid = (left + right)/2;
        if (num[mid] == value)
        {
            return true;
        }
        else if (num[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    int n;
    LL k, temp;
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        LL other = num[i] + k;
        if (binsearch(i+1, n-1, other))
        {
            ++ans;
        }
        //cout<<num[i]<<endl;
    }

    cout<<ans<<endl;

    return 0;
}

