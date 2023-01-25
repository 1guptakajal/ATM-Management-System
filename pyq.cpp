/*write a program to print following pattern
                  1
                1 2 1
              1 2 3 2 1
            1 2 3 4 3 2 1
          1 2 3 4 5 4 3 2 1    */

#include<iostream>
using namespace std;
int main(){
int n=5,i,j,k,p=1;
for(i=1;i<=n;i++){
for(j=i;j<=n;j++){
    cout<<" ";
}
for(k=1;k<=i;k++){
    cout<<k;
}
for(k=i;k>1;k--){
cout<<k-1;
}
cout<<endl;
} 
}