#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <Level/LevelConfig.h>
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

		void spawnPlayer(Level::LinkedListType linkedlist_type);
		int getPlayerScore();
		bool isPlayerDead();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}