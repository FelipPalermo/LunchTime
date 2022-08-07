#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <C:\Users\Felipe\source\repos\SMFL_Clicker\SMFL_CLICKER\Dinheiro.h>




class UPfuncionario {

public:

	UPfuncionario(int posX, int posY, sf::Vector2f size = sf::Vector2f(120,80)) {
	
		body.setSize(size);
		body.setPosition(posX, posY);	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);


	}


	 // Detecta clicks e retorna true
	 void click(int mouseX, int mouseY, sf::Event& event, unsigned __int64 & dinheiro) {

		static unsigned short mfX = body.getPosition().x;
		static unsigned short mfY = body.getPosition().y;

		static unsigned short mfXS = body.getSize().x;
		static unsigned short mfYS = body.getSize().y;


		if (mouseX >= mfX - mfXS / 2 && mouseY >= mfY - mfYS / 2
			&& mouseX <= mfX + mfXS / 2 && mouseY <= mfY + mfYS / 2) {

			body.setFillColor(sf::Color::Red);


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && lock_click != true && dinheiro >= 10) {


				std::cout << dinheiro;
				lock_click = true;

				body.setFillColor(sf::Color::Green);

				upgrades++;
				nFuncionarios += 1;
				dinheiro -= 10;
				
			}
			
		}


		else body.setFillColor(sf::Color::White);


		// Seguranca para o mouse nao ficar clicando infinitamente
		// Se o programa detectar que algum botao do mouse foi levantado
		if (event.type == sf::Event::MouseButtonReleased) {


			// e se o programa detectar que foi o botao esquerdo
			if (event.mouseButton.button == sf::Mouse::Left) {

				// Lockclick fica falso e podemos clickar denovo
				lock_click = false;

				
			}
		}

	}



	 // Adicionar +1 ao dinheiro para cada funcionario 
	 void funcionarios(unsigned __int64& dinheiro) {

		 if (cF.getElapsedTime().asSeconds() > 5) {

			 std::cout << nFuncionarios << "\n";
			 cF.restart();
			 dinheiro += nFuncionarios;
		 }
	 }

	void render(sf::RenderWindow& window) {
		window.draw(body);
	}

private:



	bool lock_click; 
	unsigned short int upgrades = 0; 
	unsigned int nFuncionarios = 0;


	sf::RectangleShape body; 
	sf::Clock cF; 


};