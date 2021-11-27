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
int path[N][N];

void findPathmatrix(int a[][N]){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++){
                    a[j][k] = a[j][k] | (a[j][i] & a[i][k]);
                }
            }
        }
     
     // coping the result...
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                path[i][j] = a[i][j];
            }
        }
}

void Problem() {
     Mem(graph, 0);
     Mem(path, 0);
     int edge = 7;
     int vertex = 5;

     for (int i = 0; i < edge; i++){
         int a,b;
         cin>>a>>b;
         graph[a][b] = 1;
         graph[b][a] = 1;
     }
    
    findPathmatrix(graph);    

    bool connected = true;
    cout<<"Path Matrix:"<<endl;
    for (int i = 1; i < vertex+1; i++){
        for (int j = 1; j < vertex+1; j++){
            if(path[i][j]==0) connected = false;
            cout<<path[i][j]<<" ";
        }
       cout<<endl; 
    }

    if(connected) cout<<"The graph is strongly connected"<<endl;
    else cout<<"The graph isn't strongly connected"<<endl;
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