//扩展KMP算法

#include <string>
#include <iostream>

using namespace std;
const int maxn = 100005;

char str[maxn];
long ans;
int exNext[maxn],extend[maxn]; //extend[i]表示原 串以第i开始与模式串的前缀的最长匹配
void EKMP(char s[],char t[])//s[]为主串，t[]为模版串
{
    int i,j,p,l;
    int len=strlen(t);
    int len1=strlen(s);
    memset(exNext,0,sizeof(exNext));
    memset(extend,0,sizeof(extend));
    exNext[0]=len;
    j=0;
    while(1+j<len&&t[j]==t[1+j])j++;
    exNext[1]=j;
    int a=1;
    for(i=2; i<len; i++)
    {
        p=exNext[a]+a-1;
        l=exNext[i-a];
        if(i+l<p+1)exNext[i]=l;
        else
        {
            j=max(0,p-i+1);
            while(i+j<len&&t[i+j]==t[0+j])j++;
            exNext[i]=j;
            a=i;
        }
    }
    j=0;
    while(j<len1&&j<len&&s[j]==t[j])j++;
    extend[0]=j;
    a=0;
    for(i=1; i<len1; i++)
    {
        p=extend[a]+a-1;
        l=exNext[i-a];
        if(l+i<p+1)extend[i]=exNext[i-a];
        else
        {
            j=max(0,p-i+1);
            while(i+j<len1&&j<len&&s[i+j]==t[j])j++;
            extend[i]=j;
            a=i;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    long cur, index;

    while (T--)
    {
        ans = 0;
        cin>>str;
        EKMP(str, str);
        
        int len=strlen(str);
        for (int i = 0; i < len; ++i)
        {
            ans += extend[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
