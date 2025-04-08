#include <stdio.h>
#include "tp_1_recursividad.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Ejercicio 1
bool palindromoREC(char palabra[], int i)
{
    int longitud = strlen(palabra);
    if (i >= longitud / 2)
    {
        return true;
    }
    if (palabra[0 + i] == palabra[longitud - 1 - i] && palindromoREC(palabra, i + 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool palindromo(char *cadena)
{
    return palindromoREC(cadena, 0);
}

// Ejercicio 2
int producto(int m, int n)
{
    if ((n == 0 || m == 0))
    {
        return 0;
    }
    if (n > 0)
    {
        n -= 1;
        return m + producto(m, n);
    }
    else
    {
        n += 1;
        return -m + producto(m, n);
    }
}

// Ejercicio 3
int terminoSeridFibonacciREC(int k, int i, int a, int b)
{
    if (k <= 0)
    {
        return 0;
    }

    if (k == 1)
    {
        return 1;
    }
    if (k == i)
    {
        return a;
    }
    int c = b;
    b = a;
    a += c;
    i++;
    return terminoSeridFibonacciREC(k, i, a, b);
}
int terminoSeridFibonacci(int k)
{
    return terminoSeridFibonacciREC(k, 2, 2, 1);
}

// Ejercicio 4
float divisionREC(int m, int n, int i, int dec)
{
    if (n == 0)
    {
        return 0;
    }

    if (m < n)
    {
        if (m == 0)
        {
            return i;
        }
        else
        {
            dec++;
            if (dec > 5)
            {
                return i;
            }
            float resultado = i + divisionREC(m * 10, n, 0, dec) * 0.1f;
            return resultado;
        }
    }
    else
    {
        m -= n;
        i++;
        return divisionREC(m, n, i, dec);
    }
}
float division(int m, int n)
{
    return divisionREC(m, n, 0, 0);
}

// Ejercicio 5
char *agregarSeparadorMiles(char numero[])
{
    int len = strlen(numero);
    if (len <= 3)
    {
        char *result = malloc(len + 1);
        strcpy(result, numero);
        return result;
    }
    char *prefix = malloc(len - 2);
    strncpy(prefix, numero, len - 3);
    prefix[len - 3] = '\0';
    char *proccesedPref = agregarSeparadorMiles(prefix);
    free(prefix);
    char *suffix = numero + len - 3;
    char *result = malloc(strlen(proccesedPref) + 1 + 3 + 1);
    sprintf(result, "%s.%s", proccesedPref, suffix);
    free(proccesedPref);
    return result;
}

// Ejercicio 6
char *reunionMafia(int nivel)
{
    if (nivel < 1)
    {
        return strdup("0");
    }
    if (nivel == 1)
    {
        return strdup("(-.-)");
    }
    char *centro = reunionMafia(nivel - 1);
    char *completo = malloc(strlen(centro) + 7);
    sprintf(completo, "(-.%s.-)", centro);
    free(centro);
    return completo;
}

// Ejercicio 7
char *ondaDigital(char seniales[])
{
    int len = strlen(seniales);
    if (len < 1)
    {
        return strdup("NULL");
    }
    if (len == 1)
    {
        if (seniales[0] == 'L')
        {
            return strdup("_");
        }
        if (seniales[0] == 'H')
        {
            return strdup("^");
        }
    }
    char *cadena = malloc(len);
    strncpy(cadena, seniales, len - 1);
    cadena[len - 1] = '\0';

    char *cadenaProcesada = ondaDigital(cadena);
    free(cadena);

    char *onda = malloc(strlen(cadenaProcesada) + 4);
    char ultChar = cadenaProcesada[strlen(cadenaProcesada) - 1];
    if (seniales[len - 1] == 'L')
    {
        if (ultChar == '^')
        {
            sprintf(onda, "%s|_", cadenaProcesada);
        }
        else
        {
            sprintf(onda, "%s_", cadenaProcesada);
        }
    }
    else if (seniales[len - 1] == 'H')
    {
        if (ultChar == '_')
        {
            sprintf(onda, "%s|^", cadenaProcesada);
        }
        else
        {
            sprintf(onda, "%s^", cadenaProcesada);
        }
    }
    free(cadenaProcesada);
    return onda;
}

// Ejercicio 8
int **subconjuntosQueSumanN(int conjunto[], int n)
{
}

// Ejercicio 9
bool divisiblePor7(int n)
{
    if (n <= 70)
    {
        if ((n % 7) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int parteDecimal = round((((n / 10.0f) - (n / 10)) * 10));
    int parteEntera = round(n / 10) - parteDecimal * 2;
    divisiblePor7(parteEntera);
}

// Ejercicio 10
int *explosion(int n, int b)
{
}
