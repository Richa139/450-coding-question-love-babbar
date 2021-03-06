// For sorted arrays when duplicacy occurs
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }   
  for(int j=0;j<m;j++){
    cin>>b[j];
  }
   int cnt=0;
   int i=0,j=0;
   while(i<n && j<m){
    if(a[i]<b[j]){
        cnt++;
        i++;
    }
    else if(a[i]>b[j]){
        cnt++;
        j++;
    }
    else{
        cnt++;
        i++;
        j++;
    }
   }
   if(i!=n-1){
       while(i<n){
        cnt++;
        i++;
       }
   }
   if(j!=m-1){
    while(j<m){
        cnt++;
        j++;
    }
   }
   cout<<cnt<<endl;
}

// 2nd method
// for sorted arrays by remove duplicacy 
vector<int> findUnion(int a[], int b[], int n, int m)
{
  vector<int>v,v1;
   int cnt=0;
   int i=0,j=0;
   while(i<n && j<m){
    if(a[i]<b[j]){
        v.push_back(a[i]);
        cnt++;
        i++;
    }
    else if(a[i]>b[j]){
        v.push_back(b[j]);
        cnt++;
        j++;
    }
    else{
        v.push_back(a[i]);
        cnt++;
        i++;
        j++;

    }
   }
  if(i!=n){
       while(i<n){
        cnt++;
        v.push_back(a[i]);
        i++;
       }
   }
   if(j!=m){
    while(j<m){
        v.push_back(b[j]);
        cnt++;
        j++;
    }
   }
//   cout<<cnt<<endl;
v1.push_back(v[0]);
for(int i=1;i<v.size();i++){
    if(v[i]==v[i-1]){
        
    }
    else{
        v1.push_back(v[i]);
    }
}

return v1;
    }


// For unsorted array
int doUnion(int a[], int n, int b[], int m)  {
        //code here
        int k=0;
        int arr[n+m];
        for(int i=0;i<n;i++){
            arr[k]=a[i];
            k++;
        }
        for(int j=0;j<m;j++){
            arr[k]=b[j];
            k++;
        }
        sort(arr,arr+n+m);
        int count=0;
        for(int i=0;i<k;i++){
            if(i<k-1 && arr[i]==arr[i+1]){
                count++;
            }
        }
        return k-count;
    }
// -sets
int doUnion(int a[], int n, int b[], int m)  {
        //code here
          set<int>s;
          for(int i=0;i<n;i++){
              s.insert(a[i]);
          }
           for(int i=0;i<m;i++){
              s.insert(b[i]);
          }
          return s.size();
    }
// time complexity=O(n+m(log(m+n))
                  
// -maps
int doUnion(int a[], int n, int b[], int m)  {
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp.insert({a[i],i});
        }
        for(int i=0;i<m;i++){
            mp.insert({b[i],i});
        }
        return mp.size();
    }
// time complexity=O(n+m)
