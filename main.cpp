#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int *a, int n, int *b, int m){

    int j = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
        if(a[i] >= mid)
            count++;
        else
            while(j < m){
                if(a[i] + b[j] >= mid){
                    count++;
                    j++;
                    break;
                }
                j++;
            }


    if(count == n)
        return true;

    return false;
}

int main(){

    int n; cin >> n;

    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int m; cin >> m;

    int *b = new int[m];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    int left = 1;
    int right = *(max_element(a, a + n)) + *(max_element(b, b + m));

    int mid;

    while(left < right){
        mid = left + (right - left + 1) / 2;
        if(check(mid, a, n, b, m) == true)
            left = mid;
        else
            right = mid - 1;
    }

    int count = 0;
    for(int i = 0; i < n; i++)
        if(a[i] < left)
            count++;


    cout << right << " " << count << endl;

    int i = 0, j = 0;
    for(;i < n; i++)
        if(a[i] >= left)
            continue;
        else {
            while(j < m){
                if(a[i] + b[j] >= left){
                    cout << i + 1 << " " << j + 1 << endl;
                    break;
                }
                j++;
            }
            j++;
        }
    return 0;
}
