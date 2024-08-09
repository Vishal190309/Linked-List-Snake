#pragma once
#include "UI/UIElement/ImageView.h"
#include "Direction.h"
namespace Player {
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();
		void initializeBodyPartImage();

		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionLeft();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void render();
		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();
		void setDirection(Direction direction);
		void updatePosition();
		
		void setPosition(sf::Vector2i position);

		Direction getDirection();
		sf::Vector2i getPosition();

		sf::Vector2i getNextPosition();

		sf::Vector2i getPrevPosition();


	};
}