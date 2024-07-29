#pragma once
#include <SFML\System\Vector2.hpp>
#include "Direction.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
	using namespace LinkedList;
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		const float movement_frame_duration = 0.1f;
		float elapsed_duration;

		SnakeState current_snake_state;
		Direction current_snake_direction = Direction::RIGHT;
		SingleLinkedList* single_linked_list;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void createLinkedList();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void delayedUpdate();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}