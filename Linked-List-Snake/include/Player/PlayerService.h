#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
namespace Player
{
	class SnakeController;
	enum class LinkedListOperations;
	enum class TimeComplexity;
	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();
		int getPlayerScore();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}