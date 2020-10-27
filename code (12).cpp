#include <bits/stdc++.h>
#define ll long long
#define u unsigned
#define loop_(i,a,b) for(int i = a ; i< b ; i++)
#define loop_reverse(i,a,b) for(int i = b ; i >= a ; i--)
#define loop_simple(i,b) loop_(i,0,b)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define precision_set(x) cout.precision(x);
#define distance(x1,y1,x2,y2) sqrt(pow(x1-x2,2)+pow(y1-y2,2));
#define pb push_back
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<PI> VIP;

void maker(int n , int w , int arr[]){
int dp[n+1][w+1];

for(int i = 0 ;i <= n ; i++){
    for(int j = 0 ; j<= w ; j++){
        if(i == 0 || j == 0)
            dp[i][j] = 0;
        else if(arr[i-1] <= j)
               dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i-1]]+arr[i-1]);
       else
        dp[i][j] =dp[i-1][j];
}
}
cout<<dp[n][w]<<endl;

return;
}
int main(){
int n,w;
cin>>w>>n;
int arr[n];
loop_simple(i,n)
cin>>arr[i];
        maker(n,w,arr);
return 0;
}

