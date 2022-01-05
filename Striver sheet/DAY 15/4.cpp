#include<iostream>
using namespace std;

int stringtoInt(string a){
    int i = 0;
    while (i < a.length() && a[i] == ' ')
    {
        i++;
    }
    if (i >= a.length())
    {
        return 0;
    }
    int sign = 1;
    if (a[i] == '+' || a[i] == '-')
    {
        sign = (a[i] == '+') ? 1 : -1;
        i++;
    }
    if (i >= a.length())
    {
        return 0;
    }
    int num = 0;
    for (i ; i < a.length() && a[i] >= '0' && a[i] <= '9'; i++)
    {
        if (num > INT32_MAX/10 || (num == INT32_MAX/10 && a[i] - '0' > INT32_MAX%10))
        {
            return (sign == 1) ? INT32_MAX : INT32_MIN;
        }
        num = num*10 + (a[i]-'0');
    }
    return num*sign;
}

int main(){
    cout<<stringtoInt("    -45")<<endl;
}