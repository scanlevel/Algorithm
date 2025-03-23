#include <iostream>
using namespace std;

int n,num,xor_result=0,xor_bit_arr[16]={},msb_pos = 16;

// 특정 값의 하위 16비트 중 i번 비트가 켜져있다면 배열의 i번 값과 xor 연산함 
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

    // 모든 수를 xor한 뒤 나온 수만 xor하면 등장하지 않은 수만 남음.
    // A ^ A = 0, A ^ 0 = A 를 이용함
    while (cin>>num) {
        xor_calc(num);
        n--;
    }
    
    if (n==1) {
        cout << xor_result;
    } else {
        // xor 결과값에서 값이 1인 최상위 비트를 찾음 ->  두 값이 xor 연산되어있을 때, 서로 차이나는 비트 중 가장 큰 비트 ( 0 ^ 1 = 1, 1 ^ 0 = 1)
        while (!(xor_result & 1<<--msb_pos));
        // 가장 큰 비트가 i번째 비트일 때, 배열의 i번 값엔 하나의 수가 남음, 그 수가 등장하지 않은 두 수중 큰 수, 작은 값은 xor 결과값에 큰 수를 xor 연산하여 구함
        cout << (xor_result ^ xor_bit_arr[msb_pos]) << endl << xor_bit_arr[msb_pos];
    }

    return 0;
}
