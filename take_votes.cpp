#include <bits/stdc++.h>
using namespace std;

#define MAXNODE 317089

map<pair<int,int>,int>mp;
map<pair<int,int>,int>::iterator ii;

int arr[5][MAXNODE];

void decode(char str[],int index){
	ifstream inFile (str);
    string line;


    int cnt=1;
    while(getline(inFile, line)){
        istringstream iss(line);
    	int n;
    	while (iss >> n) {
    		arr[index-1][n]=cnt;
 	    }
		cnt++;
    }

}

int main() {

	char s0[]="dataset/main-graph.txt";
	char s1[]="dataset/input1.txt";
	char s2[]="dataset/input2.txt";
	char s3[]="dataset/input3.txt";
	char s4[]="dataset/input4.txt";
	char s5[]="dataset/input5.txt";

	memset(arr,0,sizeof(arr));

	ifstream inFile (s0);
    string line;

    ofstream outFile("weighted_graph.out");

    while(getline(inFile, line)){
        istringstream iss(line);
    	int n; int u,v,flag=0;
    	while (iss >> n) {
    		if(flag==0){
    			u=n;
    			flag=1;
			}
			else{
				v=n;
			}
 	    }
		mp.insert(make_pair(make_pair(u,v),0));
    }

	decode(s1,1);
	decode(s2,2);
	decode(s3,3);
	decode(s4,4);
	decode(s5,5);

	for(ii=mp.begin();ii!=mp.end();++ii){
		int u=ii->first.first;
		int v=ii->first.second;
		int wt=0;
		for(int i=0;i<5;++i){
			if(arr[i][u]==arr[i][v])
				wt++;
		}
		ii->second=wt;
	}

	for(ii=mp.begin();ii!=mp.end();++ii){
		outFile<<ii->first.first<<","<<ii->first.second<<","<<ii->second<<endl;
	}

	return 0;
}
