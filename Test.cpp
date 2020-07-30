#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 50, count = 0;
    bool prime[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        prime[i] = true;
    }

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            count++;
        }
    }
    cout << count;
}
/*
 int count=0,numbers=0;
    for(int i=2;i<=N;i++){
        count=0;
        for(int j=2;j<i;j++){
            if(i%j==0)
                count++;
            if(count==2) 
                break;
        }
        if(count==1)
            numbers++;
    }
    return numbers;*/