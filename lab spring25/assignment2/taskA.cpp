#include <stdio.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int n,s;
    scanf("%d %d",&n,&s);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    int i=0,j=n-1;
    while (i<j)
    {
        int sum = arr[i]+arr[j];
        if(sum==s){
            printf("%d %d\n",i+1,j+1);
            return 0;
        }
        if(sum>s) j--; else i++;
    }
    printf("-1\n");
    return 0;
}