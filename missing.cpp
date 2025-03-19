#include <iostream>

using namespace std;

int n,num,xor_result=0,xor_bit_arr[16]={},msb_pos = 16;

void xor_calc(int tmp) {
    for (int i=0; i<16; i++) {
        if (tmp & 1<<i) {
            xor_bit_arr[i] ^= tmp;
        }
    }
    xor_result ^= tmp;
}

int main() {

    cin >> n;
    
    for (int i=1; i<=n; i++) {
        xor_calc(i);
    }

    while (cin>>num) {
        xor_calc(num);
        n--;
    }

    if (n==1) {
        cout << xor_result;
    } else {
        while (!(xor_result & 1<<--msb_pos));
        cout << (xor_result ^ xor_bit_arr[msb_pos]) << endl << xor_bit_arr[msb_pos];
    }

    return 0;
}