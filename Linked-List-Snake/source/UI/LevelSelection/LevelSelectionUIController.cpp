#include "UI/LevelSelection/LevelSelectionUIController.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"
#include "Main/GameService.h"

namespace UI {
	namespace LevelSelection {
		using namespace UIElement;
		using namespace Global;
		void LevelSelectionUIController::createImage()
		{
			background_image = new ImageView();
		}
		void LevelSelectionUIController::createButtons()
		{
			level_one_button = new ButtonView();
			level_two_button = new ButtonView();
			menu_button = new ButtonView();
		}
		void LevelSelectionUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}
		void LevelSelectionUIController::initializeButtons()
		{

			level_one_button->initialize("LEVEL ONE", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(0 , level_one_button_y_position));
			level_two_button->initialize("LEVEL TWO", Config::level_two_button_texture_path, button_width, button_height,sf::Vector2f(0 ,level_two_button_y_position));
			menu_button->initialize("MENU", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

			level_one_button->setCentreAlinged();
			level_two_button->setCentreAlinged();
			menu_button->setCentreAlinged();
		}
		void LevelSelectionUIController::registerButtonCallback()
		{
			level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelOneButtonCallback, this));
			level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelTwoButtonCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuButtonCallback, this));
		}
		void LevelSelectionUIController::levelOneButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			Main::GameService::setGameState(Main::GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::ONE);
		}
		void LevelSelectionUIController::levelTwoButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			Main::GameService::setGameState(Main::GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::TWO);
		}
		void LevelSelectionUIController::menuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			Main::GameService::setGameState(Main::GameState::MAIN_MENU);
		}
		void LevelSelectionUIController::destroy()
		{
			delete(background_image);
			delete(level_one_button);
			delete(level_two_button);
			delete(menu_button);
		}
		LevelSelectionUIController::LevelSelectionUIController()
		{
			createImage();
			createButtons();
		}
		LevelSelectionUIController::~LevelSelectionUIController()
		{
			destroy();
		}
		void LevelSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}
		void LevelSelectionUIController::update()
		{
			background_image->update();
			level_one_button->update();
			level_two_button->update();
			menu_button->update();
		}
		void LevelSelectionUIController::render()
		{
			background_image->render();
			level_one_button->render();
			level_two_button->render();
			menu_button->render();
		}
		void LevelSelectionUIController::show()
		{
			background_image->show();
			level_one_button->show();
			level_two_button->show();
			menu_button->show();
		}
	}
}