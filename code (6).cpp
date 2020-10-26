#include <bits/stdc++.h>
#define ll long long
#define u unsigned
#define loop_(i,a,b) for(int i = a ; i< b ; i++)
#define loop_reverse(i,a,b) for(int i = b ; i >= a ; i--)
#define loop_input(i,b) loop_(i,0,b)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define precision_set(x) cout.precision(x);
#define distance(x1,y1,x2,y2) sqrt(pow(x1-x2,2)+pow(y1-y2,2));
#define pb push_back
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<PI> VIP;
int dp [101][101];

void maker(int a , int arr[] , int b , int brr[]){
for(int i = 1; i <= a ; i++){
    for(int j = 1 ; j<= b ; j ++){
        if(arr[i-1] == brr[j-1]){
            dp[i][j] = dp[i-1][j-1]+1;
        }else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
}

// lcs
int main(){
int a,b;
cin>>a;
int arr[a];
loop_input(i,a)
cin>>arr[i];
cin>>b;
int brr[b];
loop_input(i,b)
cin>>brr[i];

loop_input(i,a+1)
dp[i][0] = 0;
loop_input(i,b+1)
dp[0][i] = 0;

maker(a,arr,b,brr);
cout<<dp[a][b]<<endl;
return 0;
}

