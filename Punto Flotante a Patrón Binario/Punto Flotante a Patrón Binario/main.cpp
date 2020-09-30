//
//  main.cpp
//  Punto Flotante a Patrón Binario
//
//  Created by Abel Dia on 9/24/20.
//

#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int to_binary(int numero)
{
    int exp, digito;
    int binario;
    exp = 0;
    binario = 0;
    while(numero / 2 != 0)
    {
        digito = numero % 2;
        binario = binario + digito * pow(10.0,exp);
        exp++;
        numero=numero/2;
    }
    binario = binario + numero * pow(10.0,exp);
    cout << fixed << setprecision(0);
    return binario;
}

int to_decimal(int n)
{
    int decimal, base, temp;
    decimal = 0;
    base = 1;
    temp = n;
    while (temp)
    {
        int lastDigit = temp % 10;
        temp = temp/10;
        decimal += lastDigit*base;
        base *= 2;
    }
    return decimal;
}
int exponencial(int a)
{
    string b;
    b = to_string(a);
    a = b.length() - 1;
    return a;
}
float residuo(float a, int b)
{
    float decimal;
    decimal = a - b;
    if(decimal < 0)
    {   decimal *= -1; }
    return decimal;
}

bool sign(float a)
{   return a >= 0 ? false : true;   }

void float_point()
{
    int exp, tmp, flBinary, expBinary, a;
    float float_n, decimal;
    bool signo;
    string significand;
    cout << "Ingrese un número: ";
    cin >> float_n;
    signo = sign(float_n);
    tmp = float_n;
    decimal = residuo(float_n, tmp);
    flBinary = to_binary(float_n);
    cout << setprecision(2);
    exp = exponencial(flBinary);
    exp += 127;
    expBinary = to_binary(exp);
    cout << setprecision(2);
    
    float b = decimal;
    significand.append(to_string(flBinary));
    for(int i = 0; i < 11; i++)
    {
        b = b*2;
        flBinary = to_binary(b);
        cout << setprecision(2);
        significand.append(to_string(flBinary));
        a = b;
        b = residuo(b, a);
    }
    significand.erase(0, 1);
    cout << "\nSign Exponent    Significand";
    cout << endl << "  " << signo << "  " << expBinary << "  " << significand << endl << endl;
}

void double_point()
{
    //cout << setprecision(2);
    int exp, tmp, flBinary, a;
    float float_n, decimal;
    bool signo;
    string significand;
    cout << "Ingrese un número: ";
    cin >> float_n;
    signo = sign(float_n);
    tmp = float_n;
    decimal = residuo(float_n, tmp);
    flBinary = to_binary(float_n);
    cout << setprecision(2);
    exp = exponencial(flBinary);
    exp += 1023;
    bitset<11>BinExp(exp);
    cout << setprecision(2);
    
    float b = decimal;
    significand.append(to_string(flBinary));
    for(int i = 0; i < 22; i++)
    {
        b = b*2;
        flBinary = to_binary(b);
        cout << setprecision(2);
        significand.append(to_string(flBinary));
        a = b;
        b = residuo(b, a);
    }
    significand.erase(0, 1);
    cout << "\nSign  Exponent          Significand";
    cout << endl << "  " << signo << "  " << BinExp << "  " << significand << endl << endl;
}

void Fto_double()
{
    int exp, tmp, flBinary, expBinary, a;
    float float_n, decimal;
    bool signo;
    string significand;
    cout << "Ingrese un número: ";
    cin >> float_n;
    signo = sign(float_n);
    tmp = float_n;
    decimal = residuo(float_n, tmp);
    flBinary = to_binary(float_n);
    cout << setprecision(2);
    exp = exponencial(flBinary);
    exp += 127;
    expBinary = to_binary(exp);
    cout << setprecision(2);
    
    float b = decimal;
    significand.append(to_string(flBinary));
    for(int i = 0; i < 11; i++)
    {
        b = b*2;
        flBinary = to_binary(b);
        cout << setprecision(2);
        significand.append(to_string(flBinary));
        a = b;
        b = residuo(b, a);
    }
    significand.erase(0, 1);
    cout << "\n|-------------FLOAT-------------|";
    cout << "\n Sign Exponent    Significand";
    cout << endl << "   " << signo << "  " << expBinary << "  " << significand << endl << endl;
    //CONVERCION
    
    int Double;
    Double = to_decimal(expBinary);
    Double += 896;
    bitset<11>FtoD(Double);
    
    for(int i = 0; i < 11; i++)
    {
        b = b*2;
        flBinary = to_binary(b);
        cout << setprecision(2);
        significand.append(to_string(flBinary));
        a = b;
        b = residuo(b, a);
    }
    cout << "\ntransformando...\n";
    cout << "\n|--------------------DOUBLE--------------------|";
    cout << "\n Sign  Exponent          Significand";
    cout << endl << "   " << signo << "  " << FtoD << "  " << significand << endl << endl;
}

int main(int argc, const char * argv[])
{
    float_point();
    double_point();
    Fto_double();
    return 0;
}

