#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      fil = col = 99;
      brujula = 0;
      ultimaAccion = actIDLE;
      bien_situado = false;
      tiempo = 0;
      zapatillas = false;
      bikini = false;
      girarDcha = false;
      tiempo_desc = 80;
      north = 0;
      east = 0;
      south = 0;
      west = 0;
      for(int i = 0; i < 200; ++i){
        for(int j = 0; j< 200; ++j){
          mover[i][j] = 0;
        }
      }
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Declarar aquí las variables de estado
  int fil, col, brujula, mover[200][200], tiempo, tiempo_desc, west, north, south, east;
  bool  bien_situado, zapatillas, bikini, front, rear, izqd, dcha, girarDcha;
  Action ultimaAccion;

};

#endif
