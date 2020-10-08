#include <iostream>

using namespace std;

unsigned long long int upSta(int n){
    unsigned long long int res[n + 1]; 
    res[0] = 1; 
    res[1] = 1; 
    res[2] = 2; 
    for (int i = 3; i <= n; i++) {
        cout<<res[i - 1]<<" "<<res[i - 2]<<endl;
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n]; 
}

int main() {
    int t;
    cin >> t ;
    if(t<=5){
        int arr[t];
        for(int i=0;i<t;i++){
            cin>>arr[i];
            if(arr[i]<=22000)
            cout<<upSta(arr[i])<<endl;
        }
    }
    return 0;
}