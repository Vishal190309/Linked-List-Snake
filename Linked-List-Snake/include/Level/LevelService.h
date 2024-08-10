#pragma once
#include "LevelConfig.h"

namespace Level {
    class LevelController;

    class LevelService
    {
    private:
        LevelController* level_controller;
        LevelNumber current_level;
        LinkedListType current_linked_list_type;

        void createLevelController();
        void destroy();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();

        void createLevel(LinkedListType linked_list_type);
        void spawnLevelElements(LevelNumber level_to_load);
        void spawnPlayer();
        void spawnFood();

        void setCurrentLevelNumber(Level::LevelNumber level_number);

        float getCellWidth();
        float getCellHeight();
        LevelNumber getCurrentLevel();
    };
}