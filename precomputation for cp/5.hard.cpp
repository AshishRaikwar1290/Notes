/*given a string for each query given l and r find if it is possible to form palindrome
between range l to r 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int hsh[N][26];
int main() {
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<N;i++){
            for(int j=0;j<26;j++){
                hsh[i][j]=0;
            }
        }
        int n,q;
        cin>>n;
        cin>>q;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            hsh[i+1][s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                hsh[j][i]+=hsh[j-1][i];
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int odd_count=0;
            for(int i=0;i<26;i++){
                int char_count=hsh[r][i]-hsh[l-1][i];
                if(char_count%2!=0){
                    odd_count++;
                }
            }
            if(odd_count>1){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
        
    }
	return 0;
}