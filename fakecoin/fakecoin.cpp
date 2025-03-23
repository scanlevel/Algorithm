#include <cstdlib>
#include "fakecoin.h"

struct info{
    int start, end;
};

void init_arr(int* arr) {
    for (int i=0; i<22; i++) {
        arr[i] = 0;
    }
}

void make_coin_arr(int* arr,int start, int end) {
    for (int i=start; i<=end; i++) {
        arr[i] = 1;
    }
}

info check(int start, int end, int length) {
    int mid1 = start + length;
    int mid2 = start + length*2;
    
    init_arr(left);
    init_arr(right);
    make_coin_arr(left,start,mid1-1);
    make_coin_arr(right,mid1,mid2-1);

    int result = balance(left,right);
    if (result == 1) {
        return {mid1,mid2-1};
    } else if (result == 0) {
        return {mid2,end};
    } else if (result == -1) {
        return {start, mid1-1};
    }
    return {-1,-1};
}

int main() {
    load_coins();

    int fake_coin = 0;
    info check0 = {1,21};
    info check1 = check(check0.start,check0.end,7);
    info check2 = check(check1.start,check1.end,3);
    if (check2.end == check2.start) {
        fake_coin = check2.start;
    } else {
        info check3 = check(check2.start,check2.end,1);
        fake_coin = check3.start;
    }

    report_coin(fake_coin);
}