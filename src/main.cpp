#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread> //Hilos de procesos
#include <fstream> // COntrol de cadenas
#include <string> // control de cadenas


using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])

{
    this_thread::sleep_for(0.1s);

    ifstream archivo;
    archivo.open("assets/images/moto.txt");
    
    Elements elementos;
    string linea;
    // Funcion para imprimir moto
        while (getline(archivo,linea))
        {
            elementos.emplace_back(text(linea));
        }
        Element moto=vbox(elementos);
        archivo.close();
    
    
    // Funcion para imprimir todo el bloque
        string linea2;
        ifstream archivo2;
        archivo2.open("assets/images/bloque.txt");
        while (getline(archivo2, linea2))
        {
            elementos.emplace_back(text(linea2));

        }
        Element bloque=vbox(elementos);
        archivo2.close();

    



    int fotograma = 0;
    while (true)
    {
    fotograma++;
    Element personaje = spinner(21,fotograma) | bold | color(Color::Orange1) | bgcolor(Color::Black);
    //declaracion 
    Element dibujo = hbox({personaje, moto, bloque}); 
    Screen pantalla = Screen::Create(Dimension::Full());
    Render(pantalla,dibujo);
    pantalla.Print();
    cout<<pantalla.ResetPosition();
    }
    

    return EXIT_SUCCESS;
    
}
