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

void maker(int y1 , string s1 ,int y2 ,string s2){

loop_input(i,y1+1)
dp[i][0] = i;
loop_input(i,y2+1)
dp[0][i] = i;

loop_(i,1,y1+1){
loop_(j,1,y2+1){
if(s1[i-1] == s2[j-1]){
    dp[i][j] = dp[i-1][j-1];
}else{
dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
}
}
}
return;
}

// change a word to another
int main(){
string s1,s2;
cin>>s1>>s2;
int y1 = s1.length() , y2 = s2.length();


maker(y1,s1,y2,s2);

cout<<dp[y1][y2]<<endl;
/*
cout<<"######################"<<endl;
loop_input(i,y1+1){
loop_input(j,y2+1){
cout<<"["<<dp[i][j]<<"] ";
}
cout<<endl;
}
*/
return 0;
}

