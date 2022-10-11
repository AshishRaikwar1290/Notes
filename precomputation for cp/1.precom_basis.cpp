#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long fact[N];
int main() {
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++){
	    fact[i]=fact[i-1]*i;
	}
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	cout<<fact[n]<<endl;
	}
	return 0;
}

/*
TC with precomp o(n)+o(t)
TC without precomp o(n*t)
*/
/*only 10^7 iterations in 1 sec*/

/*
count occurences of element in an array
1<=N<=10^5
1<=a[i]<=10^7
1<=q<=10^5
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int hsh[N];
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    hsh[a[i]]++;
	}
	int q;
	cin>>q;
	while(q--){
	    int x;
	    cin>>x;
	    cout<<hsh[x]<<endl;
	}
	
}
/*
TC: O(N)+O(Q)==2*10^5
can pass in 1 sec
*/