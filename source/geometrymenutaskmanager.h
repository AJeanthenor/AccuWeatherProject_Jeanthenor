#ifndef GEOMETRY_MENU_TASK_MANAGER_H
#define GEOMETRY_MENU_TASK_MANAGER_H

#include "menutaskmanager.h"
#include "geometryclient.h"
#include <map>
#include <string>

/**
 * Defines menu tasks implementations for menu class
 **/
class GeometryMenuTaskManager : public MenuTaskManager{
public:
    /**
     * Adds new clients to the client inventory
     **/
    void addNewClients(const std::string& clientName);

    /**
     * Displays all available clients in the client inventory
     **/
    void displayClients();

    /**
     * Deletes the client identified by the clientName
     **/
    void deleteClients(const std::string& clientName);

    /**
     * Checks if the client map is empty
     **/
    bool isEmpty();
private:
    /**
     * Prompts the user for the type of GeometryType they wish to set. Then
     * prompts the user for the geometry data
     **/
    void setClientGeometryData(GeometryClient& newClient);

    /**
     * Prompts the user to enter the data for a single point
     **/
    GeometryPoint getPointData();

    /**
     * Sets point data for a new client
     **/
    void setClientPointData(GeometryClient& newClient);

    /**
     * Sets line data for a new client
     **/
    void setClientLineData(GeometryClient& newClient);

    /**
     * Sets polygon data for a new client
     **/
    void setClientPolygonData(GeometryClient& newClient);

    std::map<std::string, GeometryClient> m_clientMap;
};

#endif //GEOMETRY_MENU_TASK_MANAGER_H