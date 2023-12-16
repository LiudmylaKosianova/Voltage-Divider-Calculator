#include <stdio.h>

#define R2min 10.0      //the mainimum value of R2 for the sweep
#define R2max 100.0     //the maximum value fo R2 for the sweep
#define Npts 10         //the number of points in the arrays

/**Functions*/

int main(void){

    double Vin, R1, R2step;
    double R2[Npts];
    double I[Npts];
    double Vout[Npts];
    double Pout[Npts];
    int PmaxInd, i, j, k;

    printf("Wecome to the Voltage Divider Calculator");
    printf("Enter a value for Vin: \n");
    printf("Enter a value for R1 between 10 and 100 Ohms: \n");

    

    
    return 0;
}

