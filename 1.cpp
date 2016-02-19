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

struct client
{
    vector<server> servers;
    int *priorities;
    int requests_to_success;

    client(int num_servers)
    {
        priorities = new int[num_servers];

        for(int i = 0 ; i < num_servers ; i++)
        {
            servers.push_back(server(chances()));
        }

    }

    client()
    {
        servers.resize(3);

        servers[0].success_rate = 0.9;
        servers[1].success_rate = 0.8;
        servers[2].success_rate = 0.7;
    }

    int request_key(int server_id)
    {
       int server_response = servers[server_id].request();
       return server_response;
    }


    int acknowledge(int server_id)
    {

    }

    int request(int server_id)
    {
        int status = request_key(server_id);

        if(status == 200)
        {
            acknowledge(server_id);
        }
        else
        {

        }

        return status;
    }


    int initiate_req()
    {
        int requests_to_success = 1;
        bool success = false;


        for(int i = 0 ;i < servers.size();i++)
        {
             int response = request(i);

            //cout<<"Requesting server :"<<i<<" "<<"status code :"<<response<<endl;

            if(response == 200)
            {
                success = true;
                break;
            }
            else
            {
               // cout<<"Request FAILED";
                requests_to_success ++;
            }

          //  system("pause");
        }

        if(!success) //
        {
            cout<<"\n\n NO SUCCESS ENCOUNTERED";
        }
        else
        {
            cout<<"Success after "<<requests_to_success<<" requests";
        }

        return requests_to_success;
    }


    void batch_request(int num)
    {
        int total_requests = 0;

        while(num--)
        {
           int reqs = initiate_req();
           total_requests += reqs;
        }

        cout<<"Had to make "<<total_requests<<" requests";
    }

};
int main()
{
    srand(time(NULL));

    client c;


    c.initiate_req();

    c.batch_request(10000);

    return 0;
}
