#ifndef MENU_TASK_MANAGER_H
#define MENU_TASK_MANAGER_H

#include <map>
#include <string>

/**
 * Defines the abstract MenuTaskManager type
 **/
class MenuTaskManager {
public:
    virtual void addNewClients(const std::string&) = 0;
    virtual void displayClients() = 0;
    virtual void deleteClients(const std::string&) = 0;
    virtual bool isEmpty() = 0;
};

#endif //MENU_TASK_MANAGER_H