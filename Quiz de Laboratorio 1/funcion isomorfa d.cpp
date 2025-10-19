#include <iostream>
using namespace std;

int notZ(int p){ return p ? 0 : 1; }
int andZ(int p,int q){ return (p && q) ? 1 : 0; }
int orZ(int p,int q){ return (p || q) ? 1 : 0; }
int norZ(int a,int b){ return notZ(orZ(a,b)); }

int D(int x,int y,int z){ return orZ(norZ(x,y), andZ(y,z)); }

int main(){
    cout << "x y z | NOR | AND | r\n";
    cout << "----------------------\n";
    for(int x=1;x>=0;--x)
      for(int y=1;y>=0;--y)
        for(int z=1;z>=0;--z){
          int n = norZ(x,y), a = andZ(y,z), r = D(x,y,z);
          cout << x<<" "<<y<<" "<<z<<" |  "<<n<<"  |  "<<a<<"  | "<<r<<"\n";
        }
}
