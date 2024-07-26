#pragma once

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		SnakeState current_snake_state;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}