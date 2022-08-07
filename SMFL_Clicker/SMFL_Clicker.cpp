#include <SFML/Graphics.hpp>
#include <C:\Users\Felipe\source\repos\SMFL_Clicker\SMFL_Clicker\MainButton.h>
#include <C:\Users\Felipe\source\repos\SMFL_Clicker\SMFL_Clicker\Dinheiro.h>
#include <C:\Users\Felipe\source\repos\SMFL_Clicker\SMFL_Clicker\Upfuncionario.h>



int main(int argc, char* argv[]) {
	
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Lunch Time!");
	window.setFramerateLimit(60.f);


	// Variavel dinheiro
	unsigned __int64 dinheiroHolder = 0;


	mainButton botaoPrincipal(400, 400, sf::Vector2f(120, 120));
	UPfuncionario addFuncionario(900,120);
	Dinheiro dinheiro(350, 100);
	

	
	// Main Loop
	while (window.isOpen()) {
		
		
		sf::Event event;



		// Variaveis que dao update sempre
		unsigned short mouseX = sf::Mouse::getPosition(window).x;
		unsigned short mouseY = sf::Mouse::getPosition(window).y;
		


		// Deixa o display da variavel dinheiro sempre atualizado 
		dinheiro.MostrarDinheiro(dinheiroHolder);


		addFuncionario.funcionarios(dinheiroHolder);


		// Loop de eventos
		while (window.pollEvent(event)) {
			

			// Fechar programa com esc ou pelo X
			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
			
			

			// Funcoes
			dinheiro.clickAddMoney(dinheiroHolder,botaoPrincipal.click(mouseX, mouseY, event));
			addFuncionario.click(mouseX, mouseY, event, dinheiroHolder);

		}
		 

		// Renrderizacao 

		addFuncionario.render(window);
		botaoPrincipal.Render(window);
		dinheiro.render(window);
		window.display();
		window.clear();

	}


	return 0;
}