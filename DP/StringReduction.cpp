//https://www.interviewstreet.com/challenges/dashboard/#problem/4eac48496bee2
//
#include <iostream>
#include <string>
using namespace std;

const int maxn = 105;
int dpa[maxn][maxn];
int dpb[maxn][maxn];
int dpc[maxn][maxn];

void init(int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            dpa[i][j] = 0;
            dpb[i][j] = 0;
            dpc[i][j] = 0;
        }
    }
}

int main()
{
    int len;
    int T;
    cin>>T;
    string str;
    while (T--)
    {
        cin>>str;
        len = str.length();
        
        int d;
        int cur;

        init(len);

        bool isa = false;
        bool isb = false;
        bool isc = false;
        //d == 1
        for (cur = 0; cur < len; ++cur)
        {
            if (str[cur] == 'a')
            {
                isa = true;
                dpa[cur][cur] = 1; 
            }
            else if (str[cur] == 'b')
            {
                isb = true;
                dpb[cur][cur] = 1;
            }
            else if (str[cur] == 'c')
            {
                isc = true;
                dpc[cur][cur] = 1;
            }
        }

        bool flag = ((isa&&isb) || (isa&&isc) || (isb&&isc));

        if (flag == false)
        {
            cout<<len<<endl;
        }
        else
        {
        for (d = 2; d <= len; ++d)
        {
            flag = false;
            //cur - cur+d-1
            for (cur = 0; (cur+d-1) < len; ++cur)
            {
                int limit = cur+d-1;
                for (int k = cur; k < limit; ++k)
                {
                    // a
                    if ((dpb[cur][k]==1 && dpc[k+1][limit]==1)||(dpb[k+1][limit]==1 && dpc[cur][k]==1))
                    {
                        flag = true;
                        dpa[cur][limit] = 1;
                    }
                    //b
                    if ((dpa[cur][k]==1 && dpc[k+1][limit]==1)||(dpa[k+1][limit]==1 && dpc[cur][k]==1))
                    {
                        flag = true;
                        dpb[cur][limit] = 1;
                    }
                    //c
                    if ((dpa[cur][k]==1 && dpb[k+1][limit]==1)||(dpa[k+1][limit]==1 && dpb[cur][k]==1))
                    {
                        flag = true;
                        dpc[cur][limit] = 1;
                    }
                }
            }
        }

        flag = true;

        for (d = len; d >= 2&&flag; --d)
        {
            
            for (cur = 0; (cur+d-1) < len; ++cur)
            {
                int limit = cur+d-1;
                if (dpa[cur][limit] == 1)
                {
                    flag = false;
                    break;
                }
                else if (dpb[cur][limit] == 1)
                {
                    flag = false;
                    break;
                }
                else if (dpc[cur][limit] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == false)
                break;
        }

        cout<<(len-d+1)<<endl;
        }
    }
    return 0;
}

