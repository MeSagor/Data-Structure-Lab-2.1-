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
int tree[100];

void insertElement(int value){
    int curIdx = 0;
    while(true){
        if(tree[curIdx] == -1){
            tree[curIdx] = value;
            break;
        } else if(tree[curIdx] <= value){
            if(tree[curIdx] == value){
                cout<<"Multiple value"<<endl;
                cout<<"Location: "<<curIdx<<endl;
                break;
            } else{
                curIdx = (curIdx * 2) + 2;
            }
        } else if(tree[curIdx] >= value){
            if(tree[curIdx] == value){
                cout<<"Multiple value"<<endl;
                cout<<"Location: "<<curIdx<<endl;
                break;
            } else{
                curIdx = (curIdx * 2) + 1;
            }
        }
    }
}


void Problem() {
     Mem(tree, -1);
     insertElement(8);
     insertElement(3);
     insertElement(10);
     insertElement(1);
     insertElement(6);
     insertElement(4);
     insertElement(7);
     insertElement(14);
     insertElement(13);
     insertElement(11);
     insertElement(6);

     for (int i = 0; i < 40; i++)
     {
         if(tree[i]!=-1){
            cout<<"at "<<i<<": "<<tree[i]<<endl;
         }
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