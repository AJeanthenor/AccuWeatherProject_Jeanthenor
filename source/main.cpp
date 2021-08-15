#include <iostream>
#include "Menu.h"
#include "geometrymenutaskmanager.h"

int main(int argc, char** argv) 
{
    Menu newMenu;
    MenuTaskManager* taskManager = new GeometryMenuTaskManager();
    newMenu.setMenuTaskManager(taskManager);
    int8_t menu_selection = 0;
    do{
        menu_selection = newMenu.displayMenu();
    }
    while (menu_selection != Menu::EXIT_MENU);

    return 0;    
}