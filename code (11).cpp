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


bool maker_2_helper(int n , int arr[] , int a , int b , int c){
if(a+b+c == 0){
return true;
}
if(n < 0){
    return false;
}
bool x=false,y=false,z=false;
if(a - arr[n-1] >= 0)
 x =   maker_2_helper(n-1,arr,a-arr[n-1],b,c);
 if(x){
    return true;
 }else{
 if(b - arr[n-1] >= 0)
  y =  maker_2_helper(n-1,arr,a,b-arr[n-1],c);
  if(y){
    return true;
  }else{
 if(c - arr[n-1] >= 0)
  z =  maker_2_helper(n-1,arr,a,b,c-arr[n-1]);
  if(z)
    return true;
  else
    return false;
  }
 }
}

void maker_2(){
int n,total =0;
cin>>n;
int arr[n];
for(int i = 0 ; i<n;i++){
    cin>>arr[i];
    total += arr[i];
}
if(n < 3 || total%3 != 0){
    cout<<0<<endl;
    return;
}
if(maker_2_helper(n,arr,total/3,total/3,total/3))
    cout<<1<<endl;
else
    cout<<0<<endl;
return;
}

int main(){
maker_2();
return 0;
}

