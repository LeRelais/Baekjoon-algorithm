#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, b, c;
    for(int i = 0; ; i++){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            break;
        printf("Triangle #%d\n", i+1);
        if(c == -1){
            printf("c = %.3f\n", sqrt(pow(a,2) + pow(b,2)));
        }
        else{
            if(a != -1){
                if(a >= c){
                    cout << "Impossible.\n";
                }
                else{
                    printf("b = %.3f\n", sqrt(pow(c,2) - pow(a,2)));
                }
            }

            if(b != -1){
                if(b >= c){
                    cout << "Impossible.\n";
                }
                else{
                    printf("a = %.3f\n", sqrt(pow(c,2) - pow(b,2)));
                }
            }
        }
        cout << '\n';
    }
    return 0;
}