#include <bits/stdc++.h>

using namespace std;

double chances()
{
    return rand()/RAND_MAX;
}

class Server
{
    double success_rate;

    Server(int rate):success_rate(rate)
    {

    }

    Server()
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


    return 0;
}
