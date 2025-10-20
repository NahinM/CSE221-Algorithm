#include <stdio.h>

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    
    int i=0,j=0,sum=0,len=0;
    while (j<n)
    {
        if(arr[j]+sum<=k) {
            sum+=arr[j];
            int ll = j-i+1;
            if(len<ll) len = ll;
            j++;
        }else if(sum!=0) {
            sum-=arr[i++];
        }else {
            i++;j++;
        }
    }
    printf("%d\n",len);
}