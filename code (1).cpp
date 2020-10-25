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


int main(){
int n;
cin>>n;
PI arr[n+1];
// first -> steps || second -> type of operation
arr[1].first = 0,arr[1].second = 1;
arr[2].first = 1,arr[2].second = 2;
arr[3].first = 1,arr[3].second = 3;
for(int i = 4 ; i <= n;i++){
if(i%6 == 0){
    if(arr[i/3].first < arr[i/2].first){
        if(arr[i/3].first < arr[i-1].first){
            arr[i].first = arr[i/3].first + 1;
            arr[i].second = 3;
        }else{
        arr[i].first = arr[i-1].first +1;
        arr[i].second = 1;
        }
    }else{
    if(arr[i/2].first < arr[i-1].first){
        arr[i].first = arr[i/2].first+1;
        arr[i].second = 2;
    }else{
    arr[i].first = arr[i-1].first+1;
    arr[i].second = 1;
    }
    }
}else if(i%3 == 0){
if(arr[i-1].first < arr[i/3].first){
    arr[i].first = arr[i-1].first+1;
    arr[i].second = 1;
}else{
    arr[i].first = arr[i/3].first+1;
    arr[i].second = 3;
}
}else if(i%2 == 0){
if(arr[i-1].first < arr[i/2].first){
    arr[i].first = arr[i-1].first +1 ;
    arr[i].second = 1;
}else{
    arr[i].first = arr[i/2].first + 1;
    arr[i].second = 2;
}
}else{
arr[i].first = arr[i-1].first + 1;
arr[i].second = 1;
}
}
cout<<arr[n].first<<endl;
VI vect;
while(n != 1){
    vect.pb(n);
    if(arr[n].second == 1){
        --n;
    }else{
    n /= arr[n].second;
    }
}
vect.pb(1);
reverse(vect.begin(),vect.end());
for(int i = 0 ; i< vect.size();i ++){
    cout<<vect[i]<<" ";
}
return 0;
}

