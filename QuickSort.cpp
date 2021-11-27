/**
 * @author Sagor
 */

#include<bits/stdc++.h>

using namespace std;
#define gap                        ' '
#define EPS                        1e-9
#define P_INF                      2e9+17
#define N_INF                     -2e9-17
#define MOD                        1000000007
#define PI                         2*acos(0.0)
#define All(x)                     x.begin(),x.end()
#define Mem(Name, type)            memset(Name, type, sizeof(Name))
#define TIMESTAMP(msg)             cout << "[" msg "] Time = " << clock() * 1.0 / CLOCKS_PER_SEC << endl


template<typename T>
T GCD(T a, T b) { return a ? GCD(b % a, a) : b; }

template<typename T>
T LCM(T a, T b) { return (a * b) / GCD(a, b); }


/*-----------------------------------------------------^-----------------------------------------------------*/
void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition(int a[], int low, int high){
    int boss = a[high];
    int curbig_idx = -1;

    for (int i = 0; i < high; i++)
    {
        if(a[i] < boss){
            curbig_idx++;
            swap(&a[curbig_idx], &a[i]);
        }
    }
    swap(&a[curbig_idx + 1], &a[high]);
    return curbig_idx + 1;
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int part = partition(a,low,high);

        quickSort(a, low, part - 1);
        quickSort(a, part + 1, high);
    }
}

void Problem() {
    //Here You Go...
    int a[10] ={10,80,40,90,70,30,20,100,45,75};
    cout<<"Before Quicksort: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    quickSort(a, 0, 9);

    cout<<"After Quicksort: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}


int main() {
    freopen("input.txt", "r", stdin);       //  File input ...
//     freopen("output.txt", "w", stdout);		//  File output ...
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n = 1;
//    cin >> n;            // For Multiple testcases...
    for (int i = 0; i < n; ++i) {
        Problem();
    }
    TIMESTAMP("End:");
    return 0;
}