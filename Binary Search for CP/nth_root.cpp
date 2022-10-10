/*program to find nth root a number using bs 
Tc -: O(P*(LOG(N*10^D)
P-Pth root
D-accuracy upto decimal places
n-nth root
*/
#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;
double multiply(double mid,int n){
    double ans = 1;
    for(int i=0;i<n;i++){
        ans*=mid;
    }
    return ans;
}
int main() {
    double x;
    int n;
    cin>>x>>n;
    double l = 1;
    double h = x;
    while(h-l > eps){
        double mid = (h+l)/2;
        if(multiply(mid,n) < x){
            l=mid;
        }
        else{
            h=mid;
        }
    }
    cout<<setprecision(10)<<l<<"\n"<<h<<endl;
	return 0;
}