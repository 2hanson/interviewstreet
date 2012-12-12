//https://www.interviewstreet.com/challenges/dashboard/#problem/4fd05444acc45
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> flowers;

int cmp(int a, int b)
{
    return (a > b);
}

int main()
{
    int n, k, value;
    cin>>k>>n;
    for (int index = 0; index < k; ++index)
    {
        cin>>value;
        flowers.push_back(value);
    }

    sort(flowers.begin(), flowers.end(), cmp);
    
    int res = 0;
    
    for (int index = 0; index < flowers.size(); ++index)
    {
        res += (index/n + 1)*flowers[index];
    }

    cout<<res<<endl;

    return 0;
}

