#include "Controller.h"

Controller::Controller(Size _Client) {
	this->Client = _Client;
	this->Barney = new Dino(_Client);
	this->indice_esc = 0;
	this->gameover = false;
}

Controller::~Controller() {
	delete Barney;
}

void Controller::animar(Graphics^ g, Bitmap^ img1, Bitmap^ img2, Bitmap^ img3) {


	g->Clear(Color::White);
	this->dibujar_Escenario(g, img2);

	dibujarEnemigos(g, img3);
	agregarEnemigo();
	limpiarEnemigos();
	ver_Colision();
	dibujar_Barney(g, img1);
}
void Controller::dibujarEnemigos(Graphics^ g, Bitmap^ img3) {
	for (unsigned int i = 0; i < this->enemigos.size(); i++) {
		this->enemigos.at(i)->dibujar(g, img3);
	}
}
void Controller::dibujar_Barney(Graphics^ g, Bitmap^ img1) {
	if (this->Barney == nullptr) {
		this->gameover = true;
	}
	else {
		this->Barney->Dibujar(g, img1);
	}


}
void Controller::limpiarEnemigos() {
	for (unsigned int i = 0; i < this->enemigos.size(); i++) {
		if (this->enemigos.at(i)->get_AreaDibujo().X < 0) {
			delete[] this->enemigos.at(i);
			this->enemigos.erase(this->enemigos.begin() + i);
		}
	}
}
void Controller::agregarEnemigo() {


	System::Random r;

	int n = 0;
	n = r.Next(0, 1001);

	if (n % 500 == 0) {
		this->enemigos.push_back(new Enemy(this->Client));
	}

}
void Controller::dino_Saltar() {
	this->Barney->realizarSalto();
}

void Controller::dino_Agachate() {
	this->Barney->agachate();
}
void Controller::dino_Parate() {
	this->Barney->parate();
}
bool Controller::En_el_aire() {
	return this->Barney->get_en_el_Aire();
}

void Controller::dibujar_Escenario(Graphics^ g, Bitmap^ img) {

	g->DrawImage(img, Rectangle(0, 0, Client.Width, Client.Height), obtenerSubImagen(img), GraphicsUnit::Pixel);
}

bool Controller::game_over() {
	return this->gameover;
}

void Controller::ver_Colision() {
	for (unsigned int i = 0; i < this->enemigos.size(); i++) {
		if (this->Barney->retornarAreaDibujo().IntersectsWith(this->enemigos.at(i)->get_AreaDibujo())) {
			delete this->Barney;
			this->Barney = nullptr;
		}
	}
}

Rectangle Controller::obtenerSubImagen(Bitmap^ img) {

	Rectangle f;

	this->indice_esc == 1280 ? this->indice_esc = 0 : this->indice_esc += 10;

	f = Rectangle(indice_esc, 0, 640, img->Height);

	return f;
}