//Function prototypes 
void additionCalculator(int t1, int n1, int t2, int n2);
void subtractionCalculator(int t1, int n1, int t2, int n2);
void multiplicationCalculator(int t1, int n1, int t2, int n2);
void divisionCalculator(int t1, int n1, int t2, int n2);
int greatestCommonFactor(int numerator, int denominator);

//Header files 
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;

int main() {

        //Variables 
        int t1, t2, n1, n2;
        char arithmeticOperator;
        char divisor;
        char answer;

        cout << "Fraction Calculator" << endl;
        cout << "============================" << endl << endl;

        do {

                //Take user input in the form a/b
                cout << "Enter value of first fraction: in the form of a/b: ";
                cin >> t1 >> divisor >> n1;

                //Take user input in the form c/d
                cout << "Enter value of second fraction: in the form of c/d ";
                cin >> t2 >> divisor >> n2;

                cout << endl;

                //Menu 
                cout << "Choose artithmetic operator" << endl << endl;
                cout << "Addition(+)" << setw(24) << "Subtraction(-)" << endl;
                cout << "Multiplication(*)" << setw(15) << "Division(/)" << endl;
                cout << "Operator: "; //Operator is entered in the form of +, -, /, *
                cin >> arithmeticOperator;

                cout << endl;

                //Choose function accordingly depending on which operator is chosen 
                if (arithmeticOperator == '+') {
                        additionCalculator(t1, n1, t2, n2);
                }
                else if (arithmeticOperator == '-') {
                        subtractionCalculator(t1, n1, t2, n2);
                }
                else if (arithmeticOperator == '*') {
                        multiplicationCalculator(t1, n1, t2, n2);
                }
                else if (arithmeticOperator == '/') {
                        divisionCalculator(t1, n1, t2, n2);
                }

                cout << "Calculate again? (Y/N) ";
                cin >> answer;
                cout << endl;

        } while (toupper(answer) == 'Y');

        return 0;
}

//Addition function 
void additionCalculator(int t1, int n1, int t2, int n2) {

        //Calculate numerator and denominator of fraction using user input 
        double numerator = t1 * n2 + t2 * n1;
        double denominator = n1 * n2;

        double factor = greatestCommonFactor(numerator, denominator); //Get highest common factor 

        //Reduce terms by dividing nuemrator and denominator by factor 
        numerator = numerator / factor;
        denominator = denominator / factor;

        //Print results 
        cout << t1 << "/" << n1 << " + " << t2 << "/" << n2 << " = " << numerator << "/" << denominator << endl << endl;
}

//Subtraction fucntion 
void subtractionCalculator(int t1, int n1, int t2, int n2) {

        //Calculate numerator and denominator of fraction using user input 
        int numerator = (t1 * n2) - (t2 * n1);
        int denominator = n1 * n2;

        double factor = greatestCommonFactor(numerator, denominator); //Get highest common factor 

        //Reduce terms by dividing nuemrator and denominator by factor 
        numerator = numerator / factor;
        denominator = denominator / factor;

        //Print results 
        cout << t1 << "/" << n1 << " - " << t2 << "/" << n2 << " = " << numerator << "/" << denominator << endl << endl;
}

//Multiplication function 
void multiplicationCalculator(int t1, int n1, int t2, int n2) {

        //Calculate numerator and denominator of fraction using user input 
        int numerator = t1 * t2;
        int denominator = n1 * n2;

        double factor = greatestCommonFactor(numerator, denominator); //Get highest common factor 

        //Reduce terms by dividing nuemrator and denominator by factor 
        numerator = numerator / factor;
        denominator = denominator / factor;

        //Print results 
        cout << t1 << "/" << n1 << " * " << t2 << "/" << n2 << " = " << numerator << "/" << denominator << endl << endl;
}

//Division function 
void divisionCalculator(int t1, int n1, int t2, int n2) {

        //Calculate numerator and denominator of fraction using user input 
        int numerator = t1 * n2;
        int denominator = n1 * t2;

        double factor = greatestCommonFactor(numerator, denominator); //Get highest common factor 

        //Reduce terms by dividing nuemrator and denominator by factor 
        numerator = numerator / factor;
        denominator = denominator / factor;

        //Print results 
        cout << "(" << t1 << "/" << n1 << ")" << " / " << "(" << t2 << "/" << n2 << ")" << " = " << numerator << "/" << denominator << endl << endl;
}

//Gets and returns the greatest common factor in order to reduce fraction 
int greatestCommonFactor(int numerator, int denominator) {

        int loopCounter = abs(min(numerator, denominator)); //Find the lowest value between numerator and denominator to use as loop counter 
        int maxFactor = 0;

        //Loops through to get the biggest common factor of numerator and denominator
        for (int i = 1; i <= loopCounter; i++) {
                if (numerator % i == 0 && denominator % i == 0) {
                        maxFactor = i;
                }
        }
        return maxFactor;
}
