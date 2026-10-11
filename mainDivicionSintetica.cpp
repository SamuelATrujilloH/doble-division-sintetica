#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

void setColor(int text, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text + background * 16);
}

double evaluarPolinomio(const std::vector<double>& coeficientes, double x) {
    double resultado = 0;
    int grado = coeficientes.size() - 1;
    for (int i = 0; i <= grado; ++i) {
        resultado += coeficientes[i] * pow(x, grado - i);
    }
    return resultado;
}

void dobleDivisionSintetica(std::vector<double> coeficientes, double x0) {
    int n = coeficientes.size() - 1;
    std::vector<double> b(n + 1), c(n);
    double R1, R2;
    int iteraciones = 0;
    
    do {
        setColor(15, 1);
        std::cout << "\nIteracion " << iteraciones + 1 << ": x0 = " << x0 << "\n";
        setColor(15, 0); 
        
        b[0] = coeficientes[0];
        for (int i = 1; i <= n; ++i) {
            b[i] = b[i - 1] * x0 + coeficientes[i];
        }
        R1 = b[n];
        
        c[0] = b[0];
        for (int i = 1; i < n; ++i) {
            c[i] = c[i - 1] * x0 + b[i];
        }
        R2 = c[n - 1];
        
        setColor(15, 0);
        std::cout << "    | ";
        for (size_t i = 0; i < coeficientes.size(); ++i) {
            std::cout << coeficientes[i] << "  ";
        }
        std::cout << "\n";
        
        std::cout << x0 << " | ";
        for (int i = 0; i < n; ++i) {
            std::cout << b[i] << "  ";
        }
        std::cout << "\n";
        
        std::cout << x0 << " | ";
        for (int i = 0; i < n - 1; ++i) {
            std::cout << c[i] << "  ";
        }
        std::cout << "\n";
        
        x0 = x0 - (R1 / R2);
        iteraciones++;
    } while (fabs(R1) > 1e-6 && iteraciones < 100);
    
    setColor(14, 0);
    std::cout << "\nRaiz aproximada: " << x0 << "\n";
    setColor(15, 0);
}

bool bolzano(double a, double b, const std::vector<double>& coeficientes) {
    double fa = evaluarPolinomio(coeficientes, a);
    double fb = evaluarPolinomio(coeficientes, b);
    
    std::cout << "f(" << a << ") = " << fa << "\n";
    std::cout << "f(" << b << ") = " << fb << "\n";
    
    if (fa * fb < 0) {
        std::cout << "Existe al menos una raiz en el intervalo [" << a << ", " << b << "]\n";
        double x0 = (a + b) / 2;
        dobleDivisionSintetica(coeficientes, x0);
        return true;
    } else {
        std::cout << "No hay una raiz garantizada en el intervalo [" << a << ", " << b << "]\n";
        return false;
    }
}

int main() {
    system("cls");
    setColor(11, 0);
    std::cout << "\nEste programa calcula las raices de un polinomio con el metodo de doble division sintetica\n";
    setColor(15, 0);
    char opcion;
    do {
        int grado;
        std::cout << "Ingrese el grado del polinomio: ";
        std::cin >> grado;
        
        std::vector<double> coeficientes(grado + 1);
        std::cout << "Ingrese los coeficientes del polinomio en orden descendente:\n";
        for (int i = 0; i <= grado; ++i) {
            std::cin >> coeficientes[i];
        }
        
        double a, b;
        std::cout << "Ingrese el valor de a: ";
        std::cin >> a;
        std::cout << "Ingrese el valor de b: ";
        std::cin >> b;
        
        system("cls");
        
        if (!bolzano(a, b, coeficientes)) {
            std::cout << "Desea ingresar otro polinomio? (s/n): ";
            std::cin >> opcion;
            system("cls");
        } else {
            opcion = 'n';
        }
    } while (opcion == 's' || opcion == 'S');
    
    return 0;
}









