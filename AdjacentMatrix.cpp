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
#define N 10
int graph[N][N];
int res[N][N];

void printConnections(int vertex){
    for (int i = 1; i < 6; i++){
        if(graph[vertex][i] == 1){
            cout<<i<<" ";
        } 
    }
}

void multiply(int a[][N], int b[][N], int degree){
    for (int d = 1; d < degree; d++){
        int temp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < N; k++)
                    temp[i][j] += a[i][k] * b[k][j];
            }
        }
     
        // Storing
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res[i][j] = temp[i][j];
    }
}

void Problem() {
     Mem(graph, 0);
     
     for (int i = 0; i < 7; i++){
         int a,b;
         cin>>a>>b;
         graph[a][b] = 1;
         res[a][b] = 1;
         graph[b][a] = 1;
         res[b][a] = 1;
     }

            // Answer of a...
    for (int i = 1; i < 6; i++){
        cout<<"Adjacent nodes of "<<i<<": ";
        printConnections(i);
        cout<<endl;
    }
    cout<<endl;
            // Answer of b to d...
    multiply(res, graph, 2);

     for (int i = 1; i < 6; i++){
         for (int j = 1; j < 6; j++){
             //cout<<"paths of len 3 from "<<i<<" to "<<j<<": "<<res[i][j]<<endl;
             cout<<res[i][j]<<" ";
         }
         cout<<endl;
     }    
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