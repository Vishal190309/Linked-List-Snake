#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"
namespace UI {
	namespace LevelSelection {
		class LevelSelectionUIController : public Interface::IUIController {
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float level_one_button_y_position = 500.f;
			const float level_two_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			const float background_alpha = 85.f;

			UIElement::ImageView* background_image;

			UIElement::ButtonView* level_one_button;
			UIElement::ButtonView* level_two_button;
			UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void levelOneButtonCallback();
			void levelTwoButtonCallback();
			void menuButtonCallback();
			void destroy();
		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}