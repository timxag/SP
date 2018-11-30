//coin.cpp
#include "mlisp.h"

double cc(double amount, double largest__coin);
double count__change(double amount);
double next__coin(double coin);
double GR__AMOUNT();
double dd = 23;
double mm = 06;
double LAGEST__COIN = 3;//старший номинал

double cc(double amount, double largest__coin){
 return
 (  (amount == 0 || largest__coin == 1) ? 1
  : !(amount  > 0 && largest__coin > 0) ? 0
  : (cc(amount, next__coin(largest__coin)) +
     cc(amount - largest__coin, largest__coin)
    )
 );
}

double count__change(double amount){
 return
 cc(amount, LAGEST__COIN);
}

double next__coin(double coin){
  return (  coin == 3
                ? 2
                : coin == 2
                    ? 1
                    : 0
 );
}

double GR__AMOUNT(){
  return 100 * mm + dd;
}

int main(){
 display(" gta variant 20");
 newline();
 display(" 1-2-3");
 newline();
 display("count__change for 100 \t= ");
 display(count__change(100));
 newline();
 display("count__change for ");
 display(GR__AMOUNT());
 display(" \t= ");
 display(count__change(GR__AMOUNT()));
 newline();
 return 0;
}
