#ifndef MENU_H
#define MENU_H
 
 #include <iostream>
 #include "menutaskmanager.h"
 
/** 
 * Defines menu class. Menu class displays main menu and forwards
 * user selections to task manager implementation
**/

class Menu{
public:
    enum{
    /**
     * Describes the menu states
     **/
        DISPLAY_MENU   = 0,
        ADD_CLIENT     = 1,
        DELETE_CLIENT  = 2,
        DISPLAY_CLENTS = 3,
        EXIT_MENU      = 4
    };

    /**
     * Displays the main menu
     * @return DISPLAY_MENU state if exit option not selection otherwise EXIT_MENU
     **/
    int displayMenu();

    /**
     * Sets MenuTaskManager. MenuTaskManager handles the implementation
     * of adding, deleting and displaying clients
     **/
    void setMenuTaskManager(MenuTaskManager* manager);

private:
    /**
     * Reads user input for the menu selection and
     * validates the user input before forwarding the menu selection to
     * the MenuTaskManager
     * @return DISPLAY_MENU state if exit option not selection otherwise EXIT_MENU
     **/
    int readMenuSelection();

    /**
     * Handles the add new client functionality
     **/
    void addNewClient();

    /**
     * Handles the deleting of clients
     **/
    void deleteClient();

    /**
     * Handles the displaying of clients
     **/
    void displayClients();

    /**
     * Processes the menu selection
     * @param[in] selection - The menu selection
     * @return The menu state resulting from the menu selection processing
     **/
    int processMenuSelection(int selection);

    MenuTaskManager* m_manager;
};
 
#endif /* SHAPE_H */