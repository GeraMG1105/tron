#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>  //Hilos de procesos
#include <fstream> // COntrol de cadenas
#include <string>  // control de cadenas
#include <dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])

{
    Dibujo moto("./assets/images/moto.txt");
    Dibujo bloque("./assets/images/bloque.txt");

    int fotograma = 0;
    while (true)
    {
        fotograma++;
        Element personaje = spinner(21, fotograma) | bold | color(Color::Orange1) | bgcolor(Color::Black);
        // declaracion
        Element dibujo = hbox({personaje, moto.GetElement(), bloque.GetElement()});
        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla, dibujo);
        pantalla.Print();
        cout << pantalla.ResetPosition();
    }

    return EXIT_SUCCESS;
}
