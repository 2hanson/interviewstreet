#include <iostream>
#include <vector>

using namespace std;

const int maxn = 105;
int yuRank[maxn];//equal to children num
int pIndex[maxn];//parent index
int n, m;
vector<int> leafList;
int ans;

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        pIndex[i] = -1;
        yuRank[i] = 0;
    }
}

void updateyuRank(int cur, int inc)
{
    while (cur != -1)
    {
        yuRank[cur] += inc;
        cur = pIndex[cur];
    }
}

void out()
{
    for (int i = 1; i <= n; ++i)
    {
        cout<<yuRank[i]<<" "<<pIndex[i]<<endl;
    }
}

void findLeaf()
{
    for (int i = 1; i <= n; ++i)
    {
        if (0 == yuRank[i])
        {
            leafList.push_back(i);
        }
    }
}

int findRoot(int cur)
{
    while(pIndex[cur] != -1)
    {
        cur = pIndex[cur];
    }

    return cur;
}

void solve()
{
    while (leafList.empty() == false)
    {
        int cur = leafList[ leafList.size() - 1]; 
        leafList.pop_back();
        //cout<<"leaf: "<<leaf<<endl;

        int root = findRoot(cur);
        //
        //not root
        while (pIndex[cur] != -1)
        {
            if ((yuRank[cur]+1)%2 == 0 &&  (yuRank[root]-yuRank[cur])%2 == 0)
            {
                ++ans;
                updateyuRank( pIndex[cur], -(yuRank[cur] + 1));

                //
                if (yuRank[ pIndex[cur] ] == 0)
                {
                    leafList.push_back(pIndex[cur]);
                }

                pIndex[cur] = -1;
                break;
            }

            cur = pIndex[cur];
        }
    }
}

int main()
{
    cin>>n>>m;
    init();
    int u, v;

    while (m--)
    {
        cin>>u>>v;
        if (yuRank[u] > yuRank[v])
        {
            pIndex[v] = u;
            updateyuRank(u, yuRank[v]+1);
        }
        else
        {
            pIndex[u] = v;
            updateyuRank(v, yuRank[u]+1);
        }
    }

    findLeaf();

    ans = 0;   
    solve();

    cout<<ans<<endl;
    return 0;
}

