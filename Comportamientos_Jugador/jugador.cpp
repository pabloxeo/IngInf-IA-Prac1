#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actFORWARD;

	if(sensores.terreno[2] != 'p' and sensores.terreno[2] != 'M')
	  accion = actFORWARD;
	else if(ultVezDcha){
	  accion = actTURN_L;
	  ultVezDcha = true;
	}
	else{
	  accion = actTURN_R;
	  ultVezDcha = true;
	}



	// Determinar el efecto de la ultima accion enviada
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
