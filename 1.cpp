#include <bits/stdc++.h>

using namespace std;

double chances()
{
    return rand()/(double)RAND_MAX;
}

struct server
{
    double success_rate;

    server(double rate)
    {
        success_rate = rate;
    }

    server()
    {
        success_rate = chances();
    }

    int request()
    {
        if(success_rate >= chances())
        {
            return 200;
        }
        else
        {
            return 400;
        }
    }
};


int main()
{
    server a(0.3);


    while(1)
    {
        cout<<a.request()<<endl;
        system("PAUSE");
    }
    return 0;
}
