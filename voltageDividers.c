#include <stdio.h>

#define R2min 10.0      //the mainimum value of R2 for the sweep
#define R2max 100.0     //the maximum value fo R2 for the sweep
#define Npts 10         //the number of points in the arrays

/**Functions*/
void print_array(double A[], int x);

int main(void){

    double Vin, R1, R2step;
    double R2[Npts];
    double I[Npts];
    double Vout[Npts];
    double Pout[Npts];
    int PmaxInd, i, j, k;

    printf("Wecome to the Voltage Divider Calculator");
    printf("Enter a value for Voltage in: \n");
    scanf(" %lf", &Vin);
    printf("Enter a value for Resistor1 between 10 and 100 Ohms: \n");
    scanf(" %lf", &R1);

    /*Populate R2[] array*/

    R2step = (R2max - R2min) / (Npts - 1); //all elements between ranges R2max and R2min should be equally spaced
    R2[0] = R2min;
    R2[Npts] = R2max;
    for(i=1; i<Npts-1; i++){
        R2[i] = R2[i-1] + R2step;
    }

    print_array(R2, Npts);

    /*Populate I[] array with values of Current*/

    for(i=0; i<Npts; i++){
        I[i] = Vin / (R1 + R2[i]);
    }

    for (i=0;i<Npts; i++){
        Vout[i] = Vin * (R2[i] / (R1 + R2[i]));
    }

    for (i=0;i<Npts; i++){
        Pout[i] = I[i] * Vout[i]; 
    }

    return 0;
}

void print_array(double A[], int x){
    int i;
    printf("Your array = { ");
    for(i=0; i<x; i++){
        printf("%.2lf ", A[i]);
    }
    printf("}\n");
}

