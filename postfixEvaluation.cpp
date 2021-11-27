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
float Stack[20];
int top = -1;

void Push(float data){
   // cout<<top<<" ";
    top++;
    if(top > 20){
        cout<<"Overflow Error"<<endl;
        return;
    }
    Stack[top] = data;

}

float Pop(void){
    if(top!=-1){
        return Stack[top--];
    } else{
        cout<<"Inflow Error"<<endl;
        return -999999;
    }
}

float Calculate(float a, float b, char oparator){
    if(oparator == '+') return a + b;
    else if(oparator == '-') return a - b;
    else if(oparator == '*') return a * b;
    else if(oparator == '/') return a / b;
    else return -1;
}

void Problem() {
    //Here You Go...

    char postfix[16];
    cin.getline(postfix,16);
    cout<<"Expression :"<<postfix<<endl;
    
    for (int i = 0; i < 16; i++)
    {
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            char num[5];
            int idx=0;
            while(postfix[i] >= '0' && postfix[i] <= '9'){
                num[idx++] = postfix[i];
                i++;
            }
            num[idx] = '\0';
            float actualNum = (float) atof(num);
            cout<<actualNum<<endl;
            Push(actualNum);
        } else if(postfix[i]=='+' ||postfix[i]=='-' ||postfix[i]=='*' ||postfix[i]=='/'){
            float op1 = Pop();
            float op2 = Pop();
            cout<<op2<<postfix[i]<<op1;
            float result = Calculate(op2, op1, postfix[i]);
            Push(result);
            cout<<"="<<result<<endl;
            i++;
        }
    }
    
    cout<<"Answer: "<<Pop()<<endl;
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