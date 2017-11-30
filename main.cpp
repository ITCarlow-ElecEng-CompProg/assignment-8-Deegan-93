/** Luke Deegan,
 *  Exercise 8,
 *  Op Amp Circuits,
 *  7/3/17
 */



#include <iostream>
#include <cmath>
#include <cstdio>
#include <windows.h>
using namespace std;

/** Declare all functions to be used within the program */
int main(void);
char displayMenu(void);
void invert_amp(void);
void non_invert_amp(void);
void invert(double Rin, double Rf, double Av, double Vin, double *avPtr, double *voutPtr);
void noninvert(double R1, double R2, double Av, double Vin, double *avPtr, double *voutPtr);


/** Main Function */
int main(void)

{

    char choice;

    do
{

    choice = displayMenu();
    switch (choice)


    {

    case 'a': invert_amp();
    break;

    case 'b': non_invert_amp();
    break;

    case 'q': system("cls");
    cout << "Goodbye\n";
    break;

    default: cout << "\nInvalid input, press any key to continue...";
    fflush(stdin);
    getchar();
    break;
    }

}

    while (choice != 'q');


    return 0;

}



/** Display menu function, gives user instructions as to which
    keys should be pressed for which function */
    char displayMenu(void)
{

/** Declare local variables fo this function */
    char choice;

    system("cls");

    cout << "Coordinate Conversion";

    cout << "\n\nPress 'a' for an Inverting Amplifier ...";

    cout << "\nPress 'b' for a Non-Inverting Amplifier ...";

    cout << "\nPress 'q' to quit ...\n\nChoice: ";

    fflush(stdin);

    choice = getchar();

    return choice;
}

/** Initial Inverting amp function */
void invert_amp(void)
{

/** Declare all local variables to be used in the function */
    double Vcc = 0, Vee = 0, Vin, Rin = 0, Rf = 0, Av, Vout;
    double *avPtr = &Av, *voutPtr = &Vout;
    system("cls");

    cout << "Inverting Amplifier\n\n";

/** Series of while loops to check that the correct values are entered for each variable */
    while (Vcc <= 0)
    {
    cout << "Enter Vcc:\t";
    cin >> Vcc;
    }

    while (Vee >= 0)
    {
    cout << "Enter Vee:\t";
    cin >> Vee;
    }

    cout << "Enter Vin:\t";
    cin >> Vin;

    while (Rin <= 0)
    {
    cout << "Enter Rin:\t";
    cin >> Rin;
    }

    while (Rf <= 0)
    {
    cout << "Enter Rf:\t";
    cin >> Rf;
    }

/** Call the calculation subfunction */
    invert(Rin, Rf, Av, Vin, avPtr, voutPtr);

/** Display the results to the user using the pointers returned from
    the sub fucntion. Included is an if statement to check if the
    answer in is not higher than a preset value. If it is, it reverts
    to the max value */
    cout << "\nAv:\t" << Av;

    cout << "\nVout:\t" << Vout;

    if (Vout <= Vee || Vout >= Vcc)
    {
            if (Vin <= 0)
            {
                cout << "\n\nAmplifier is in saturation \n\nVout: \t" << Vcc;
            }
            else
            {
                cout << "\n\nAmplifier is in saturation \n\nVout: \t" << Vee;
            }

    }


    cout << "\n\nPress any key to return to the main menu...";

    fflush(stdin); getchar();

    return;
}

/** Sub function used for the inverting amp calculations,
    returning values through pointers */
void invert(double Rin, double Rf, double Av, double Vin, double *avPtr, double *voutPtr)
{
    *avPtr = -Rf / Rin;

    *voutPtr = *avPtr * Vin;

    return;
}

/** Initial non inverting amp function */
void non_invert_amp(void)

{

/** Declare all local variables to be used within the function */
    double Vcc = 0, Vee = 0, Vin, R1=0, R2=0, Av, Vout;

/** Declare and initialise pointers to be used in the function */
    double *avPtr = &Av, *voutPtr = &Vout;
    system("cls");

    cout << "Non-Inverting Amplifier\n\n";

/** Series of while loops to check if the values entered are correct per the variable */
    while (Vcc <= 0)
    {
    cout << "Enter Vcc:\t";
    cin >> Vcc;
    }

    while (Vee >= 0)
    {
    cout << "Enter Vee:\t";
    cin >> Vee;
    }

    cout << "Enter Vin:\t";
    cin >> Vin;

    while (R1 <= 0)
    {
    cout << "Enter R1:\t";
    cin >> R1;
    }

    while (R2 <= 0)
    {
    cout << "Enter R2:\t";
    cin >> R2;
    }

/** Call the calculation sub function */
    noninvert(R1, R2, Av, Vin, avPtr, voutPtr);

/** Display the results to the user using the pointers returned from
    the sub fucntion. Included is an if statement to check if the
    answer in is not higher than a preset value. If it is, it reverts
    to the max value */
    cout << "\nAv:\t\t" << Av;

    cout << "\nVout:\t\t" << Vout;

    if (Vout <= Vee || Vout >= Vcc)
    {
            if (Vin >= 0)
            {
                cout << "\n\nAmplifier is in saturation \n\nVout: \t " << Vcc;
            }
            else
            {
                cout << "\n\nAmplifier is in saturation \n\nVout: \t " << Vee;
            }

    }

    cout << "\n\nPress any key to return to the main menu...";

    fflush(stdin);
    getchar();

    return;
}

/** Sub function used for the inverting amp calculations,
    returning values through pointers */
void noninvert(double R1, double R2, double Av, double Vin, double *avPtr, double *voutPtr)
{
    *avPtr = 1 + (R2/R1);

    *voutPtr = *avPtr * Vin;

    return;
}

