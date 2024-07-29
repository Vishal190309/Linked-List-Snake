#include "Player/BodyPart.h"
#include "Global/Config.h"

namespace Player {
	using namespace Global;
	using namespace UI::UIElement;
	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}
	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}
	BodyPart::BodyPart()
	{
		createBodyPartImage();
		grid_position = sf::Vector2i(0, 0);
	}
	BodyPart::~BodyPart()
	{
		delete(bodypart_image);
	}
	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}
	void BodyPart::update()
	{
	}
	void BodyPart::render()
	{
		bodypart_image->render();
	}
}