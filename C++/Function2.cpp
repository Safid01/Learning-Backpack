#include <iostream>
using namespace std;
bool search_fromArr(int nums[],int se){
        for(int i =0; i<5; i++){
            if(nums[i]==se){
                return true;
            }
        }
    return false;
}
int main() {
    int arr[5]={4,7,8,8,9};
    int s = search_fromArr(arr,10);
    if(s==1){
        cout<<"found"<<endl;
    }else{
        cout<<"not found"<<endl;
    }
    return 0;
}