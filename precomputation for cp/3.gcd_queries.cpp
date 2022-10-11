/*
You are given an array A of integers of size N. You will be given Q queries where each query is represented by two integers L, R. You have to find the gcd(Greatest Common Divisor) of the array after excluding the part from range L to R inclusive (1 Based indexing). You are guaranteed that after excluding the part of the array remaining array is non empty.
Input
First line of input contains an integer T denoting number of test cases.
For each test case, first line will contain two space separated integers N, Q.
Next line contains N space separated integers denoting array A.
For next Q lines, each line will contain a query denoted by two space separated integers L, R.
Output
For each query, print a single integer representing the answer of that query.
https://www.codechef.com/problems/GCDQ
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    int a[n+10];
	    int forward[n+10];
	    int backward[n+10];
	    forward[0]=backward[n+1]=0;
	    for(int i=1;i<=n;i++){
	        cin>>a[i];
	    }
	    for(int i=1;i<=n;i++){
	        forward[i]=__gcd(forward[i-1],a[i]);
	    }
	    for(int i=n;i>=1;i--){
	        backward[i]=__gcd(backward[i+1],a[i]);
	    }
	    while(q--){
	        int l,r;
	        cin>>l>>r;
	        cout<<__gcd(forward[l-1],backward[r+1])<<endl;
	    }
	    
	}
	return 0;
}
