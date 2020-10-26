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
int dp [101][101][101];

void maker(int a , int arr[] , int b , int brr[], int c , int crr[]){
for(int i = 1; i <= a ; i++){
    for(int j = 1 ; j<= b ; j ++){
        for(int k = 1; k <= c ; k++){
             if(arr[i-1] == brr[j-1] && arr[i-1] == crr[k-1]){
            dp[i][j][k] = dp[i-1][j-1][k-1]+1;
        }else{
        dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
        }
        }

    }
}
}

// lcs
int main(){
int a,b,c;
cin>>a;
int arr[a];
loop_input(i,a)
cin>>arr[i];
cin>>b;
int brr[b];
loop_input(i,b)
cin>>brr[i];
cin>>c;
int crr[c];
loop_input(i,c)
cin>>crr[i];

loop_input(i,a+1)
dp[i][0][0] = 0;
loop_input(i,b+1)
dp[0][i][0] = 0;
loop_input(i,c+1)
dp[0][0][1] = 0;

maker(a,arr,b,brr,c,crr);
cout<<dp[a][b][c]<<endl;
return 0;
}

