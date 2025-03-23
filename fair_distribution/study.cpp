#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int n, k, pages_sum = 0;
int pages[MAX_N] = {};

void read() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> pages[i];
        pages_sum += pages[i];       
    }
}

bool check(int max_pages) {
    bool flag = false;
    int student_index = 0, assigned_pages = 0;
    for (int i=0; i<n; i++) {
        while (student_index < k) {
            if (assigned_pages + pages[i] < max_pages) {
                assigned_pages += pages[i];
                break;
            } else {
                if (pages[i] > max_pages) {
                    flag = true;
                    break;
                }
                student_index++;
                assigned_pages = 0;
            }
        }
        if (student_index == k || flag) {
            flag = true;
            break;
        }
    }
    return flag;
}

int binary_search() {
    int left = 0, right = pages_sum;
    int mid = (left+right)/2;
    while(left < right) {
        if (check(mid)) left = mid+1;
        else right = mid;
        mid = (left + right)/2;
    }
    return mid-1;
}

int main() {
    read();
    cout << binary_search();
    return 0;
}