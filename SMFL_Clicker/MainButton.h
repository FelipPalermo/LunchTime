#pragma once

#include <SFML/Graphics.hpp>


class mainButton {

	

public:

	mainButton(int posX, int posY, sf::Vector2f size) {


		// Setando fonte
		BebasNeus.loadFromFile("C:/Users/Felipe/source/repos/Render_Dog/Render_Dog/BebasNeue-Regular.otf");
		

		// Setando posicao e tamanho do quadrado principal
		mainButtonForm.setPosition(posX, posY);	mainButtonForm.setSize(size);	
		mainButtonForm.setOrigin(mainButtonForm.getSize().x / 2, mainButtonForm.getSize().y / 2);
		mainButtonForm.setFillColor(sf::Color::White);
		
		// setando texto 
		mainTexts.setFont(BebasNeus);	mainTexts.setFillColor(sf::Color::Black);
		mainTexts.setCharacterSize(25);	
		mainTexts.setString(menssagem);	
		
		mainTexts.setPosition(posX-50, posY-15);
	
	}	


	// Detecta clicks e retorna true
	bool click(int mouseX, int mouseY, sf::Event& event) {
	
		unsigned short mfX = mainButtonForm.getPosition().x;
		unsigned short mfY = mainButtonForm.getPosition().y;
		
		unsigned short mfXS = mainButtonForm.getSize().x;
		unsigned short mfYS = mainButtonForm.getSize().y;
		


		if (mouseX >= mfX - mfXS /2 && mouseY >= mfY - mfYS /2
			&& mouseX <= mfX + mfXS /2 && mouseY <= mfY + mfYS /2) {
			
			mainButtonForm.setFillColor(sf::Color::Red);


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && lock_click != true) {
				
				lock_click = true; 

				mainButtonForm.setFillColor(sf::Color::Green);

				return true;	}	
		}
		
		
		else mainButtonForm.setFillColor(sf::Color::White);


		// Seguranca para o mouse nao ficar clicando infinitamente
		// Se o programa detectar que algum botao do mouse foi levantado
		if (event.type == sf::Event::MouseButtonReleased) {
			

			// e se o programa detectar que foi o botao esquerdo
			if (event.mouseButton.button == sf::Mouse::Left) {
				
				// Lockclick fica falso e podemos clickar denovo
				lock_click = false;	}	
		}

	}




	void Render(sf::RenderWindow& window) {
	
		window.draw(mainButtonForm);
		window.draw(mainTexts);
	
	
	}




private: 

	bool lock_click; 

	sf::RectangleShape mainButtonForm; 

	sf::Text mainTexts;	sf::String menssagem = "Clique aqui!";
	sf::Font BebasNeus;
	

};