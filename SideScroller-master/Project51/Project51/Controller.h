#pragma once

#include "Dino.h"
#include "Enemy.h"
#include "vector"

using namespace std;

class Controller {
	Size Client;
	Dino* Barney;
	vector<Enemy*> enemigos;
	int indice_esc;
	bool gameover;
public:
	Controller(Size _Client);

	~Controller();

	void animar(Graphics^ g, Bitmap^ img1, Bitmap^ img2, Bitmap^ img3);
	void dibujarEnemigos(Graphics^ g, Bitmap^ img3);
	void dibujar_Barney(Graphics^ g, Bitmap^ img1);
	void limpiarEnemigos();
	void agregarEnemigo();
	void dino_Saltar();
	void dino_Agachate();
	void dino_Parate();
	bool En_el_aire();
	void dibujar_Escenario(Graphics^ g, Bitmap^ img);
	bool game_over();
	void ver_Colision();
	Rectangle obtenerSubImagen(Bitmap^ img);
};
