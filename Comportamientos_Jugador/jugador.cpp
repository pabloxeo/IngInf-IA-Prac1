#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){
	
	Action accion = actIDLE;
	
	switch (ultimaAccion){
		case actFORWARD:
			switch (brujula){
				case 0: fil--; break;
				case 1: col++; break;
				case 2: fil++; break;
				case 3: col--; break;
			}
			break;
		case actTURN_L:
			brujula = (brujula+3)%4;
			girarDcha = (rand()%2==0);
			break;
		case actTURN_R:
			brujula = (brujula+1)%4;
			girarDcha = (rand()%2==0);
			break;
	}

	if(sensores.terreno[0] == 'G' and !bien_situado){
		fil = sensores.posF;
		col = sensores.posC;
		brujula = sensores.sentido;
		bien_situado = true;
	}
	if (bien_situado){
		mapaResultado[fil][col] = sensores.terreno[0];
	}
//Decidir la nueva accion
	if((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'J') and sensores.superficie[2] == '_'){
		accion = actFORWARD;
	}else if (!girarDcha){
		accion = actTURN_L;
	}else{
		accion = actTURN_R;
	}


	// Determinar el efecto de la ultima accion enviada
	ultimaAccion = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
/*
git add . 
git commit -m "Cambiando el enlace del botón"
git push origin main 
*/