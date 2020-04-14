#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

void l()
{
    cout << endl;
}
                                                                                                           
double f(double z)
{
    return sin(z*z);                                                                                   
}
                                                                                                           
                                                                                                            //формула Симпсона
double S(int n, double a, double b) 
{
    double sum = 0, h;
    
    h = (b - a) / n;
    
    for (double i = 1; i < n; i += 2)
        sum += f(a + (i - 1) * h) + 4 * f(a + i * h) + f(a + (i + 1) * h);
    
    return h / 3 * sum;

}

double R(int n, double a, double b) 
{
    double s = 0, h = (b - a) / n;
    
    for (int i = 1; i < n; i++)
    {
        s += f(a + i * h);
    }
    
    return h * (f(a) / 2 + s + f(b) / 2);

}

int main() {

    cout << "Khodin Ivan, 9 variant" << endl << endl;

    const double PI = 3.141592653589793;
    
    ofstream f1;
    f1.open("ans1.dat");
    
    ofstream f2;
    f2.open("ans2.dat");
    
    double a = 0, b = PI/4, e = 0.0001;
    
    int n = 20;
    
    while (abs((S(n, a, b) - S(n / 2, a, b)) / S(n, a, b)) >= e) {
        n *= 2;
    }
    
    cout << n << " " << S(n, a, b) << " " << abs((S(n, a, b) - S(n / 2, a, b)) / S(n, a, b)) << endl;
    
    f1 << S(n, a, b) << " " << abs((S(n, a, b) - S(n / 2, a, b)) / S(n, a, b)) << endl;



    n = 20;
    
    while (abs((R(n, a, b) - R(n / 2, a, b)) / R(n, a, b)) >= e) {
        n *= 2;
    }
    
    cout << n << " " << R(n, a, b) << " " << abs((R(n, a, b) - R(n / 2, a, b)) / R(n, a, b)) << endl;
    
    f2 << R(n, a, b) << " " << abs((R(n, a, b) - R(n / 2, a, b)) / R(n, a, b)) << endl;

    l();

    f1.close();

    f2.close();

    return 0;

}
