/**
 * @author Sagor
 */

#include<bits/stdc++.h>

using namespace std;
#define gap                        ' '
#define EPS                        1e-9
#define P_INF                      1e9+17
#define N_INF                     -1e9-17
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

void shortPath(int graph[][N]){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++){
                    if(graph[j][i] + graph[i][k] < graph[j][k]){
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
       }
}

void Problem() {
     int graph[N][N] = {{7, 5, 0, 0},
					    {7, 0, 0, 2},
					    {0, 3, 0, 0},
					    {4, 0, 1, 0}};
     
      for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(graph[i][j] == 0) graph[i][j] = 999999;
        }
        
    }
    
     shortPath(graph);
     
     cout<<"Shortest path matrix:"<<endl;
     for (int i = 0; i < 4; i++){
         for (int j = 0; j < 4; j++){
             cout<<graph[i][j]<<" ";
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