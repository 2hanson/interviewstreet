#include <string>
#include <iostream>

using namespace std;

int main()
{
    int T;
    string str;
    cin>>T;

    long cur, index, ans;

    while (T--)
    {
        cin>>str;
        ans = str.length();

        for (cur = 1; cur < str.length(); ++cur)
        {
            for (index = 0; (cur+index)<str.length(); ++index)
            {
                if (str[index] != str[cur+index])
                {
                    break;
                }
            }

            ans += (index);
        }

        cout<<ans<<endl;
    }

    return 0;
}

