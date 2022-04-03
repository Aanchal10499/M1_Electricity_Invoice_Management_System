#include<stdlib.h>
#include<stdio.h>

void tariff(){
    printf(" Consumption      Fixed     Wheeling   Energy\n");
    printf("  Slab(kWh)       Charge     Charge    Charge\n");
    printf("                            (Rs/kWh)   (Rs/kWh)\n\n");
    printf("  0-100 units       75        1.46      3.05\n");
    printf(" 101-300 units      115       1.46      5.00\n");
    printf(" 301-500 units      115       1.46      6.65\n");
    printf("Above 501 units     140       1.46      7.80\n\n\n");

}