/*
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

Example


Queries are interpreted as follows:

    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of  between the indices  and  inclusive:

index->	 1 2 3  4  5 6 7 8 9 10
	[0,0,0, 0, 0,0,0,0,0, 0]
	[3,3,3, 3, 3,0,0,0,0, 0]
	[3,3,3,10,10,7,7,7,0, 0]
	[3,3,3,10,10,8,8,8,1, 0]
The largest value is  after all operations are performed.

https://www.hackerrank.com/challenges/crush/problem


*/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e7+10;
long long int arr[N];
long arrayManipulation(int n, vector<vector<int>> queries) {
    int q = queries.size();
    for(int i=0;i<q;i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int c = queries[i][2];
        arr[a]+=c;
        arr[b+1]-=c;
    }
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    long int max=-1;
    for(int i=1;i<=n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
/*TC: o(n+m)=10^7 */