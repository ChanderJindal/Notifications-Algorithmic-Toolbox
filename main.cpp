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

int optimal_weight(int W, int w[] , int w_size) {
  int** weights = new int* [w_size + 1];

  for (int i = 0; i <= w_size; i++) {
    weights[i] = new int[W + 1];
  }

  for (int i = 0; i <= w_size; i++) {
    for (int j = 0; j <= W; j++) {
        if (i==0 || j==0) {
          weights[i][j] = 0;
        }
        else if (w[i - 1] <= j)
          weights[i][j] = max(w[i - 1] + weights[i - 1][j - w[i - 1]],  weights[i - 1][j]);
        else
          weights[i][j] = weights[i - 1][j];
    }
  }
  return weights[w_size][W];
}

int main(){
int n,w;
cin>>w>>n;
int arr[n];
loop_simple(i,n)
cin>>arr[i];
cout<< optimal_weight(w,arr,n)<<endl;
return 0;
}

