#include <bits/stdc++.h>
using namespace std;

string Entero_a_Romano(int num) {
  map<int,string>Equivalente;
    Equivalente[1]="I";
    Equivalente[4]="IV";
    Equivalente[5]="V";
    Equivalente[9]="IX";
    Equivalente[10]="X";
    Equivalente[40]="XL";
    Equivalente[50]="L";
    Equivalente[90]="XC";
    Equivalente[100]="C";
    Equivalente[400]="CD";
    Equivalente[500]="D";
    Equivalente[900]="CM";
    Equivalente[1000]="M";
  int len=0,z=num;
    while(z!=0){
      z/=10;
      len++;
    }
    z=num;
    string ans="";
    for(int i=len-1;i>=0;i--){
      int div=pow(10,i);
      int req=z/div;
      int val=req*div;
        
      if(Equivalente[val]!="")ans+=Equivalente[val];
        else{
          if(div==1&&req>=5){
            ans+=Equivalente[5];
            req-=5;
          }
            if(div==10&&req>=5){
              ans+=Equivalente[50];
              req-=5;
            }
              if(div==100&&req>=5){
                ans+=Equivalente[500];
                req-=5;
              }
              while(req--)ans+=Equivalente[div];
        }
            z=z-val;
    }
        
  return ans;
}
int main() {
  int decimal;
    cout << "Ingresa un numero entero: "<<endl;
    cin>>decimal;
    string z= Entero_a_Romano(decimal);
    cout<<"El numero a romano "<<z<<endl;
}