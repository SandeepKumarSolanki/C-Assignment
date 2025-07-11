#include<iostream>
#include<vector>
using namespace std;

int k_largest(int arr[],int size,int k){

    for(int i=1 ; i<size; i++){
        for(int j=0 ; j<size-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    int t=size;
    return arr[t-k];
    
}


int main(){
    int arr[9]={3,2,3,1,2,4,5,5,6};
    cout<<"give largest "<<k_largest(arr,9,4);
    return 0;
}