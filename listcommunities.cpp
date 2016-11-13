#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

/**
run this like

./listcomm < node_community.out > community_node_list.out

**/

int main()
{
    //ifstream cin("node_community");
    //ofstream cout("community_list");

    vector<vli> community(2000, vli(0));
    //cout<<"hey"<<endl;
    lli node ;
    int comm , max_comm = 0;
    while(cin>>node)
    {
        cin>>comm;
        //cout<<node<<" "<<comm<<endl;
        community[comm].push_back(node);

        if(comm>max_comm)
            max_comm= comm;
    }
    //cerr<<"there are "<<max_comm+1<<" communities"<<endl;
    lli i,j;
    for(i=0;i<=max_comm;i++)
    {
        for(j=0;j<community[i].size();j++)
        {
            cout<<community[i][j]<<" ";
        }
        cout<<"\n";
    }

}
