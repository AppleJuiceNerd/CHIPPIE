#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main(int argc, char** argv) {
	// Create window
	sf::RenderWindow window(sf::VideoMode({640, 480}), "ImGui + SFML = <3");
	
	// Limit to 60FPS
	window.setFramerateLimit(60);

	// Initialize ImGui
	ImGui::SFML::Init(window);

	// Create test shape
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// Create a clock
	sf::Clock deltaClock;

	// Render loop
	while (window.isOpen())
	{
		// Poll for events
		while (const auto event = window.pollEvent()) {
			ImGui::SFML::ProcessEvent(window, *event);

			// If the window is closed, close the window (woah)
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
		
		// Update ImGui with deltaClock
		ImGui::SFML::Update(window, deltaClock.restart());

		// Show the ImGui demo window
		ImGui::ShowDemoWindow();

		// Start doing ImGui things
		ImGui::Begin("When button:");

		ImGui::Button("button.");
		ImGui::Text("yes btw");

		// Stop doing ImGui things
		ImGui::End();

		// Clear drawing window
		window.clear();

		// Draw the Shape
		window.draw(shape);

		// Render ImGui things
		ImGui::SFML::Render(window);
		
		// Display what has been drawn
		window.display();
	}

	// Shut down ImGui when done
	ImGui::SFML::Shutdown();
}