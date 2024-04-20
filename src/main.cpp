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

    fstream archivo;
    archivo.open("assets/images/moto.txt");
    string moto;
    archivo >> moto;
    while (archivo.good())
    {
        archivo >>moto;
    
    }
    archivo.close();
    



    int fotograma = 0;
    while (true)
    {
    fotograma++;
    Element personaje = spinner(21,fotograma) | bold | color(Color::Orange1) | bgcolor(Color::Black);
    Element eMoto = text(moto) | bold |color(Color::Red1);
    Element dibujo = hbox({personaje, eMoto}); 
    Screen pantalla = Screen::Create(Dimension::Full());
    Render(pantalla,dibujo);
    pantalla.Print();
    cout<<pantalla.ResetPosition();
    }
    

    return EXIT_SUCCESS;
    
}
