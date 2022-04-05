#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){
	
	Action accion = actIDLE;
	
	switch (ultimaAccion){
		case actFORWARD:
			switch (brujula){
				case 0:fil--; break;
				case 1:col++; break;
				case 2:fil++; break;
				case 3:col--; break;
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
		if(sensores.sentido == norte){
			if(sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P')
				mover[fil-1][col] = 50000;
			if(sensores.terreno[2] == 'A' && !bikini)
				mover[fil-1][col] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			if(sensores.terreno[2] == 'B' && !zapatillas)
				mover[fil-1][col] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
		
			mapaResultado[fil-1][col-1] = sensores.terreno[1];
			mapaResultado[fil-1][col] = sensores.terreno[2];
			mapaResultado[fil-1][col+1] = sensores.terreno[3];
			mapaResultado[fil-2][col-2] = sensores.terreno[4];
			mapaResultado[fil-2][col-1] = sensores.terreno[5];
			mapaResultado[fil-2][col] = sensores.terreno[6];
			mapaResultado[fil-2][col+1] = sensores.terreno[7];
			mapaResultado[fil-2][col+2] = sensores.terreno[8];
			mapaResultado[fil-3][col-3] = sensores.terreno[9];
			mapaResultado[fil-3][col-2] = sensores.terreno[10];
			mapaResultado[fil-3][col-1] = sensores.terreno[11];
			mapaResultado[fil-3][col] = sensores.terreno[12];
			mapaResultado[fil-3][col+1] = sensores.terreno[13];
			mapaResultado[fil-3][col+2] = sensores.terreno[14];
			mapaResultado[fil-3][col+3] = sensores.terreno[15];


		}else if(sensores.sentido == sur){
			if(sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P')
				mover[fil+1][col] = 50000;
			if(sensores.terreno[2] == 'A' && !bikini)
				mover[fil+1][col] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			if(sensores.terreno[2] == 'B' && !zapatillas)
				mover[fil+1][col] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			mapaResultado[fil+1][col+1] = sensores.terreno[1];
			mapaResultado[fil+1][col] = sensores.terreno[2];
			mapaResultado[fil+1][col-1] = sensores.terreno[3];
			mapaResultado[fil+2][col+2] = sensores.terreno[4];
			mapaResultado[fil+2][col+1] = sensores.terreno[5];
			mapaResultado[fil+2][col] = sensores.terreno[6];
			mapaResultado[fil+2][col-1] = sensores.terreno[7];
			mapaResultado[fil+2][col-2] = sensores.terreno[8];
			mapaResultado[fil+3][col+3] = sensores.terreno[9];
			mapaResultado[fil+3][col+2] = sensores.terreno[10];
			mapaResultado[fil+3][col+1] = sensores.terreno[11];
			mapaResultado[fil+3][col] = sensores.terreno[12];
			mapaResultado[fil+3][col-1] = sensores.terreno[13];
			mapaResultado[fil+3][col-2] = sensores.terreno[14];
			mapaResultado[fil+3][col-3] = sensores.terreno[15];
		}else if(sensores.sentido == este){
			if(sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P' )
				mover[fil][col+1] = 50000;
			if(sensores.terreno[2] == 'A' && !bikini)
				mover[fil][col+1] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			if(sensores.terreno[2] == 'B' && !zapatillas)
				mover[fil][col+1] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			mapaResultado[fil-1][col+1] = sensores.terreno[1];
			mapaResultado[fil][col+1] = sensores.terreno[2];
			mapaResultado[fil+1][col+1] = sensores.terreno[3];
			mapaResultado[fil-2][col+2] = sensores.terreno[4];
			mapaResultado[fil-1][col+2] = sensores.terreno[5];
			mapaResultado[fil][col+2] = sensores.terreno[6];
			mapaResultado[fil+1][col+2] = sensores.terreno[7];
			mapaResultado[fil+2][col+2] = sensores.terreno[8];
			mapaResultado[fil-3][col+3] = sensores.terreno[9];
			mapaResultado[fil-2][col+3] = sensores.terreno[10];
			mapaResultado[fil-1][col+3] = sensores.terreno[11];
			mapaResultado[fil][col+3] = sensores.terreno[12];
			mapaResultado[fil+1][col+3] = sensores.terreno[13];
			mapaResultado[fil+2][col+3] = sensores.terreno[14];
			mapaResultado[fil+3][col+3] = sensores.terreno[15];
		}else if(sensores.sentido == oeste){
			if(sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P')
				mover[fil][col-1] = 50000;
			if(sensores.terreno[2] == 'A' && !bikini)
				mover[fil][col-1] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			if(sensores.terreno[2] == 'B' && !zapatillas)
				mover[fil][col-1] = tiempo + tiempo_desc;
			else
				mover[fil][col-1] = tiempo - 80;
			mapaResultado[fil+1][col-1] = sensores.terreno[1];
			mapaResultado[fil][col-1] = sensores.terreno[2];
			mapaResultado[fil-1][col-1] = sensores.terreno[3];
			mapaResultado[fil+2][col-2] = sensores.terreno[4];
			mapaResultado[fil+1][col-2] = sensores.terreno[5];
			mapaResultado[fil][col-2] = sensores.terreno[6];
			mapaResultado[fil-1][col-2] = sensores.terreno[7];
			mapaResultado[fil-2][col-2] = sensores.terreno[8];
			mapaResultado[fil+3][col-3] = sensores.terreno[9];
			mapaResultado[fil+2][col-3] = sensores.terreno[10];
			mapaResultado[fil+1][col-3] = sensores.terreno[11];
			mapaResultado[fil][col-3] = sensores.terreno[12];
			mapaResultado[fil-1][col-3] = sensores.terreno[13];
			mapaResultado[fil-2][col-3] = sensores.terreno[14];
			mapaResultado[fil-3][col-3] = sensores.terreno[15];
		}

		
	}
	
//Decidir direccion
	north = mover[fil-1][col];
	south = mover[fil+1][col];
	east = mover[fil][col+1];
	west = mover[fil][col-1];
	
//Decidir la nueva accion
	if(sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'
	 and sensores.superficie[2] == '_' and (sensores.terreno[2] != 'A' or bikini) and (sensores.terreno[2] != 'B' or zapatillas)){
		switch (brujula)
		{
		case norte:
			if(north <= east && north <= west && north <= south){
				accion = actFORWARD;
			}else{ 
				accion = actTURN_L;
			}
			break;
		case este:
			if(east <= north && east <= west && east <= south){
				accion = actFORWARD;
			}else{
				accion = actTURN_L;
			}
			break;
		case sur:
			if(south <= north && south <= east && south <= west){
				accion = actFORWARD;
			}else{
				accion = actTURN_L;
			}
			break;
		case oeste:
			if(west <= north && west <= east && west <= south){
				accion = actFORWARD;
			}else{
				accion = actTURN_L;
			}
			break;
		
		}
	}else if(girarDcha){
		accion = actTURN_R;
	}else{
		accion = actTURN_L;
	}
	if(sensores.terreno[0] == 'D'){
			zapatillas = true;
	}else if(sensores.terreno[0] == 'K'){
			bikini = true;
	}





	
// 	cout << mover[fil][col] << " ";

	// Determinar el efecto de la ultima accion enviada
	ultimaAccion = accion;
	mover[fil][col] = tiempo;
	tiempo++;
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


