#include <iostream>
using namespace std;
int main(){
    // number of testcases
    int t;
    cin>>t;
    while(t--){
        // size of array
        int n;
        cin>>n;
        int arr[n];
        // elements of array
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // maxsum currentmaxsum
        // totalsum
        // minsum
        int total=arr[0];
        int minsum=arr[0];
        int currentminsum=arr[0];
        int maxsum=arr[0];
        int currentmaxsum=arr[0];
        for(int i=1;i<n;i++){
            total=total+arr[i];
            // maxsum nikalne ke liye
            currentmaxsum=max(arr[i],arr[i]+currentmaxsum);
            maxsum=max(maxsum,currentmaxsum);
            // minimum nikalne ke liye
            currentminsum=min(arr[i],arr[i]+currentminsum);
            minsum=min(minsum,currentminsum);
        }
        int circularmaxsum=total-minsum;
        // agar saare elements negative hai 
        if(maxsum<0){
            cout<<maxsum<<endl;
        }
		else{
        	cout<<max(maxsum,circularmaxsum)<<endl;
		}
    }
	return 0;
}