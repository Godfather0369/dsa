#include<iostream>

using namespace std;

int findKey();

int main(){


    int ans = findKey();
   
    if(ans ==-1){
        cout<<"Element Not Found ";
    }else{
        cout<<"Element  Found  at "<<ans+1;

    }

}


int findKey(){

    int i; 
    int arr[5] = {33,45,12,8,20};
    int k = 12;
    for(i=0;i<5;i++){
            if(arr[i]==k){
                return i;
            } 
    }
    return -1;
}