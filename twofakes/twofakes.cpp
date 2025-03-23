#include <cstdlib>
#include "twofakes.h"
#define make_coin_arr(arr,start,end) for(int i=0; i<11; i++) arr[i] = (start<=i && i<=end);

int check(int start,int end){
    int length = (end-start+1)/2;
    make_coin_arr(left,start,start+length-1);
    make_coin_arr(right,start+length,end);
    return balance(left,right);
}

int main(){
    int fake1 = -1,fake2 = -1;
    load_coins();
    int result[5] = {check(1,6), 0,0, check(7,8), 0};
    result[4] = check(8+(result[3]!=0),9+(result[3]!=0));
    bool four_coin_is_normal = (result[3]==0 && result[4]==0);

    if (result[0]){
        int num = (result[0]==-1) ? 2 : 5;
        result[1] = check(num-1,num); 
        result[2] = check(9,10);
        if (four_coin_is_normal && result[2]==0){
            fake1 = num-1 + (result[1]==1);
            fake2 = num + (result[1]+2)%2;
        } else {
            fake1 = num+1 - (3+result[1])%3;
            fake2 = 8 - (result[3]==-1) + ((result[3]==0) << !(result[4]));
        }
    } else{
        result[1] = check(1,2);
        result[2] = check(4,5);
        if (four_coin_is_normal){
            fake1 = 3 - (3+result[1])%3;
            fake2 = 6 - (3+result[2])%3;
        } else {
            if (result[3]==0){
                fake1 = 7 + (1+result[4])%3;
                fake2 = 8 + (1+result[4])%3;
            } else{
                fake1 = 7 + (result[3]==1);
                fake2 = 9 + (result[4]==1);
            }
        }
    }
    two_fakes(fake1,fake2);
}