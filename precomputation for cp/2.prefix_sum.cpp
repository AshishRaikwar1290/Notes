/*find sum of elements between range l to r*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
long long pre[N];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    pre[i]=pre[i-1]+a[i];
	}
	int q;
	cin>>q;
	while(q--){
	    int l,r;
	    cin>>l>>r;
	    cout<<(pre[r]-pre[l-1])<<endl;
	}
	return 0;
}
/*
I/P:
6
3 6 2 8 9 2
4 
2 3
4 6
1 5
3 6

O/P:
8
19
28
21

TC: o(n)+o(q)
*/

/*
Given 2D array of N*N intergers. given q queries and in each query given a,b,c and d print 
sum of square represented by (a,b) as top left point and (c,d) as top bottom right point
constraints
1<=N<=10^3
1<=a[i][j]<=10^9
1<=q<=10^5
1<=a,b,c,d<=N
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int arr[N][N];
long long prefix[N][N];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        cin>>arr[i][j];
	        prefix[i][j]=arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
	    }
	}
	int q;
	cin>>q;
	while(q--){
	    int a,b,c,d;
	    cin>>a>>b>>c>>d;
	    cout<<prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1]<<endl;
	}
}
/*I/P
3
3 6 2
8 9 2
3 4 1
2
1 1 2 2
1 2 3 3

O/P
26
24

*/