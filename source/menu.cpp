#include "Menu.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <csignal>

const uint32_t MAX_LINE_WIDTH = 20;

void signal_callback_handler(int signum) {
   // Terminate program
   exit(signum);
}

int Menu::displayMenu()
{
    std::cout << std::setw(MAX_LINE_WIDTH) << "Main Menu:" << std::endl 
    << "1. Add a client" << std::endl
    << "2. Delete a client" << std::endl
    << "3. Display all clients" << std::endl
    << "4. Exit" << std::endl
    << "Please enter your menu selection: " << std::endl;

    return readMenuSelection();
}

int Menu::readMenuSelection()
{
    int returnValue = DISPLAY_MENU;
    signal(SIGINT, signal_callback_handler);

    try {
        std::string menuSelection;
        std::getline(std::cin, menuSelection);
        for (auto c: menuSelection) 
        {
            if(!isdigit(c))
            {
                throw std::runtime_error("ERROR: The menu only accepts valid integer values. Please enter a valid menu selection");
            }
        }
        int selectionValue = stoi(menuSelection);
        if (selectionValue < ADD_CLIENT || selectionValue > EXIT_MENU)
        {
            throw std::runtime_error("ERROR: You have entered an invalid menu option. Please enter a valid menu selection");
        }
        returnValue = processMenuSelection(selectionValue);
    }
    catch (const std::exception& exp)
    {
        std::cerr << "ERROR: You have entered an invalid menu option. Please enter a valid menu selection" << std::endl;
    }
    return returnValue;
}

void Menu::setMenuTaskManager(MenuTaskManager* manager)
{
    m_manager = manager;
}

int Menu::processMenuSelection(int selection)
{
    int returnValue = DISPLAY_MENU;
    switch(selection){
        case ADD_CLIENT:
            addNewClient();
            returnValue = DISPLAY_MENU;
            break;
        case DELETE_CLIENT:
            deleteClient();
            returnValue = DISPLAY_MENU;
            break;
        case DISPLAY_CLENTS:
            displayClients();
            returnValue = DISPLAY_MENU;
            break;
        case EXIT_MENU:
            std::cout << "Exiting the Menu" << std::endl;
            returnValue = EXIT_MENU;
            break;
        default:
            returnValue = DISPLAY_MENU;
    }
    return returnValue;
}

void Menu::addNewClient()
{
    std::cout << "Enter the name of the client you wish to add: " << std::endl;
    std::string itemName;
    std::getline(std::cin, itemName);
    m_manager->addNewClients(itemName);
}
void Menu::deleteClient()
{
    if(m_manager->isEmpty())
    {
        std::cout << "There are no clients available. Please add a new client." << std::endl;
        return;
    }
    displayClients();
    std::cout << "Enter the name of the client you wish to delete: " << std::endl;
    std::string itemName;
    std::getline(std::cin,itemName);
    m_manager->deleteClients(itemName);
}
void Menu::displayClients()
{
    if(m_manager->isEmpty())
    {
        std::cout << "There are no clients available. Please add a new client." << std::endl;
        return;
    }
    std::cout << "Displaying all clients" << std::endl;
    m_manager->displayClients();
}
