#include <stdio.h>

int COUNT;

double power(double base, int exponent){
    if (!exponent){return 1.0;}
    else {return power(base, exponent - 1) * base;}
}

double sqrt(double value){
    double guess = value * .5;
    int counter = COUNT;
    while (counter){
        guess = .5 * (guess + value / guess);
    }
    return guess;
}

double greedy_nrt(double value, int degree){
    double guess = value * .5;
    int counter = COUNT;
    while (counter){
        guess = .5 * (guess + value / power(guess, degree - 1));
        counter--;
    }
    return guess;
}

double branching_nrt(double value, int degree){
    int counter = COUNT;
    double guess = value * .5;
    double second;

    while (counter){
        second = .5 * (guess + value / power(guess, degree - 1));
        guess = .5 * (guess + second);
        counter--;
    }
    return guess;
}


int main(){
    int degree;
    double value, output;
    printf("Provide a value: ");
    scanf("%lf", &value);
    printf("Provide a degree of the root: ");
    scanf("%i", &degree);
    printf("Iteration count: ");
    scanf("%i", &COUNT);

    printf("The result of greedy version is: ");
    output = greedy_nrt(value, degree);
    printf("%f, ", output);
    printf("%f\n", power(output, degree));

    printf("The result of better version is: ");
    output = branching_nrt(value, degree);
    printf("%f, ", output);
    printf("%f\n", power(output, degree));
}