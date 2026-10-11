Proceso DobleDivisionSintetica
    Definir coeficientes Como Real;
    Definir grado, i, iteraciones Como Entero;
    Definir x0, R1, R2 Como Real;
    Definir a, b, fa, fb Como Real;
    
    Escribir "Ingrese el grado del polinomio: ";
    Leer grado;
    
    Dimensionar coeficientes[grado+1];
    
    Escribir "Ingrese los coeficientes del polinomio (desde el mayor grado hasta el termino independiente):";
    Para i <- 0 Hasta grado Hacer
        Leer coeficientes[i];
    FinPara
    
    Escribir "Ingrese el valor de a: ";
    Leer a;
    Escribir "Ingrese el valor de b: ";
    Leer b;
    
    fa <- EvaluarPolinomio(coeficientes, a);
    fb <- EvaluarPolinomio(coeficientes, b);
    
    Si (fa * fb) < 0 Entonces
        Escribir "Existe al menos una raiz en el intervalo [", a, ",", b, "]";
        x0 <- (a + b) / 2;
        
        iteraciones <- 0;
        Repetir
            Dimensionar b_aux[grado+1];
            Dimensionar c_aux[grado];
            
            b_aux[0] <- coeficientes[0];
            Para i <- 1 Hasta grado Hacer
                b_aux[i] <- (b_aux[i-1] * x0) + coeficientes[i];
            FinPara
            
            R1 <- b_aux[grado];
            
            c_aux[0] <- b_aux[0];
            Para i <- 1 Hasta (grado-1) Hacer
                c_aux[i] <- (c_aux[i-1] * x0) + b_aux[i];
            FinPara
            
            R2 <- c_aux[grado-1];
            
            Si R2 <> 0 Entonces
                x0 <- x0 - (R1 / R2);
            FinSi
            
            iteraciones <- iteraciones + 1;
        Hasta Que (Abs(R1) <= 0.000001) O (iteraciones >= 100)
        
        Escribir "Su raiz aproximada es: ", x0;
    Sino
        Escribir "No hay una raiz garantizada en el intervalo [", a, ",", b, "]";
    FinSi
FinProceso

Funcion EvaluarPolinomio(coeficientes,x) 
    Definir resultado Como Real;
    Definir i, grado Como Entero;
    
    resultado <- 0;
    grado <- Longitud(coeficientes) - 1;
    
    Para i <- 0 Hasta grado Hacer
        resultado <- resultado + (coeficientes[i] * (x^(grado - i)));
    FinPara
	
    
    
FinFuncion

















