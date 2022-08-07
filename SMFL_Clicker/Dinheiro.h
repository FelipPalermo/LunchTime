#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ctime>

class Dinheiro{


public:


	Dinheiro(int posX, int posY) {
	
		bebasNeue.loadFromFile("C:/Users/Felipe/source/repos/Render_Dog/Render_Dog/BebasNeue-Regular.otf");
		
		valorText.setFont(bebasNeue);
		valorText.setPosition(posX, posY);


	}


	// Mostra o dinheiro todo frame. Evita bugs visuais
	void MostrarDinheiro(unsigned __int64& dinheiro) {
	
		valorText.setString("Dinheiros = " + std::to_string(dinheiro));

	
	}


	// Adicionar dinheiro quando clique for detectado
	void clickAddMoney(unsigned __int64 & dinheiro, bool click, int valor = 1) {
		
		if (click == true){

				std::cout << dinheiro << "\n";
				dinheiro += valor;	}
		}

	


	void render(sf::RenderWindow& window) {
		
		window.draw(valorText);
	
	}


private:



	sf::Text valorText;	sf::Font bebasNeue; 
	sf::Clock clock;



};