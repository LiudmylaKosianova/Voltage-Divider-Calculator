#include <stdio.h>

#define R2min 10.0      //the mainimum value of R2 for the sweep
#define R2max 100.0     //the maximum value fo R2 for the sweep
#define Npts 10         //the number of points in the arrays

/**Functions*/
void print_array(double A[], int x);
int max_index(double P[], int x);

int main(void){

    double Vin, R1, R2step;
    double R2[Npts];
    double I[Npts];
    double Vout[Npts];
    double Pout[Npts];
    int PmaxInd, i;

    printf("Wecome to the Voltage Divider Calculator!\n\n");
    printf("Enter a value for Voltage in: ");
    scanf(" %lf", &Vin);
    printf("Enter a value for Resistor1 between 10 and 100 Ohms: ");
    scanf(" %lf", &R1);

    /*Populate R2[] array*/

    R2step = (R2max - R2min) / (Npts - 1); //all elements between ranges R2max and R2min should be equally spaced
    R2[0] = R2min;
    R2[Npts-1] = R2max;
    for(i=1; i<Npts-1; i++){
        R2[i] = R2[i-1] + R2step;
    }

    //print_array(R2, Npts);

    /*Populate I[] array with values of Current*/

    for(i=0; i<Npts; i++){
        I[i] = Vin / (R1 + R2[i]);
    }

    /*Populate Vout[] array with values of Voltage out*/

    for (i=0;i<Npts; i++){
        Vout[i] = Vin * (R2[i] / (R1 + R2[i]));
    }

    /*Populate Pout[] array with values of Power out*/

    for (i=0;i<Npts; i++){
        Pout[i] = I[i] * Vout[i]; 
    }
    
    PmaxInd = max_index(Pout, Npts);

    printf("\nYour results are:\n\n");
    printf("Ind\tVin\t  R1\t   R2\t\t I\t\tVout\t\tPout\n");
    printf("\t(V)\t (Ohm)\t  (Ohm)\t\t(A)\t\t(V)\t\t(W)\n");
    printf("---\t---\t -----\t  ----\t     --------- \t      ---------       ---------\n");
    for(i=0; i<Npts; i++){
        printf("%d\t%.1lf\t %.1lf\t  %.1lf\t     %.3e\t      %.3e       %.3e\n", i,Vin,R1,R2[i],I[i],Vout[i],Pout[i]);
    }
    printf("\nThe max Power out is %.3e Watt, it occurs at R1 = %.1lf Ohms and R2 = %.1lf Ohms", Pout[PmaxInd], R1, R2[PmaxInd]);
    printf("\n");

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

int max_index(double P[], int x){
    double Pmax = P[0];
    int maxIndex = 0;
    for(int j = 1; j<x; j++){
        if(P[j] > Pmax){
            Pmax = P[j];
            maxIndex = j;
        }
    }

    return maxIndex;
}

