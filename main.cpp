#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new IsoscelesTriangle(5, 1, 20, 7);

     
    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo isoscele");


    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]";
        shapes[i]->Dump();
        cout << endl;
    }

    // 5. Test function Scale()
    cout << endl << "===== TEST SCALE(5x) =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]";
        shapes[i]->Scale(5.);
        shapes[i]->Dump();
        cout << endl;
    }

    // 6. Test function Scale() WARNING
    cout << endl << "Figura [2] - Warning test" << endl;
    shapes[2]->Scale(-10.2);
    shapes[2]->Dump();
    
    // 7. Chiamata dinamica a distruttori polimorfici (virtual ~Shape)
    for (int i = 0; i < nShapes; i++) { 
        if (shapes[i] != nullptr) {
            delete shapes[i];
            shapes[i] = nullptr;
        }
    }

    cout << endl << "===== FINE TEST =====" << endl;

 
    
    return 0;
}

//array di puntatori a shape che punterà attraverrso il polimorfismo alle funzioni giusto del sottopoligono
//verificare coerenza input utente