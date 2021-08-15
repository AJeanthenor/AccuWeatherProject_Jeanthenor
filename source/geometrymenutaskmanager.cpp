#include "geometrymenutaskmanager.h"
#include "geometryline.h"
#include "geometrypolygon.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>

void GeometryMenuTaskManager::addNewClients(const std::string& clientName)
{
    GeometryClient newClient;
    newClient.setName(clientName);
    setClientGeometryData(newClient);
    m_clientMap[clientName] = newClient; 
}

void GeometryMenuTaskManager::displayClients()
{
    if (m_clientMap.empty())
    {
        std::cout << "No clients available please add a new client to the inventory." << std::endl;
    }
    else
    {
        for (std::map<std::string, GeometryClient>::iterator itr = m_clientMap.begin();
        itr != m_clientMap.end(); ++itr)
        {
            std::cout << itr->second << std::endl;
        }
    }
}

bool GeometryMenuTaskManager::isEmpty()
{
    return m_clientMap.empty();
}

void GeometryMenuTaskManager::deleteClients(const std::string& clientName)
{
    if (m_clientMap.find(clientName) != m_clientMap.end())
    {
        m_clientMap.erase(clientName);
    }
    else
    {
        std::cout << clientName << " does not represent a valid client." << std::endl;
    }
}

void GeometryMenuTaskManager::setClientGeometryData(GeometryClient& newClient)
{
    std::string geometryTypeStr;
    bool invalidSelection = true;
    do {
        std::cout << "What is the client's geometry type: " << std::endl
        << "1) Point" << std::endl << "2) Line" << std::endl << "3) Polygon" 
        << std::endl;
        std::getline(std::cin, geometryTypeStr);
        for (auto c: geometryTypeStr) {
            if(!isdigit(c))
            {
                std::cout << "ERROR: Please enter a valid geometry type." << std::endl;
                continue;
            }
        }
        int selectionValue;
        try
        {
            selectionValue = stoi(geometryTypeStr);
        }
        catch (const std::exception& exp)
        {
            std::cerr << "ERROR: Please enter a valid geometry type." << std::endl;
            continue;
        }
        if (selectionValue < GeometryType::POINT || selectionValue > GeometryType::POLYGON)
        {
            std::cout << "ERROR: Please enter a valid geometry type." << std::endl;
            continue;
        }
        newClient.setType(GeometryType(selectionValue));
        invalidSelection = false;
    } while(invalidSelection);

    switch(newClient.getType())
    {
        case GeometryType::POINT:
        setClientPointData(newClient);
        break;
        case GeometryType::LINE:
        setClientLineData(newClient);
        break;
        case GeometryType::POLYGON:
        setClientPolygonData(newClient);
        break;
    }
}

GeometryPoint GeometryMenuTaskManager::getPointData()
{
    const double minlat = -90.0, maxlat = 90.0, minlon = -180.0, maxlon = 180.0;
    bool invalidInput = true;
    GeometryPoint newPoint;

    do{
        try { 

            std::cout << "Enter the latitude: " << std::endl;
            std::string line;
            std::getline(std::cin, line);
            newPoint.latitude = stof(line);
            if((newPoint.latitude < minlat) || (newPoint.latitude > maxlat))
            {
                throw std::runtime_error("ERROR: Please enter a valid latitude.");
            }
            invalidInput = false;
        }
        catch (const std::exception& exp)
        {
            std::cerr << "ERROR: Please enter a valid latitude." << std::endl;
            continue;
        }
    }while(invalidInput);

    invalidInput = true;
    do{
        try { 

            std::cout << "Enter the longitude: " << std::endl;
            std::string line;
            std::getline(std::cin, line);
            newPoint.longitude = stof(line);
            if((newPoint.longitude < minlon) || (newPoint.longitude > maxlon))
            {
                throw std::runtime_error("ERROR: Please enter a valid longitude.");
            }
            break;
        }
        catch (const std::exception& exp)
        {
            std::cerr << "ERROR: Please enter a valid longitude." << std::endl;
        }
    }while(invalidInput);

    return newPoint;
}

void GeometryMenuTaskManager::setClientPointData(GeometryClient& newClient)
{
    GeometryPoint newPoint(getPointData());
    newClient.setPoint(new GeometryPoint(newPoint));
}

void GeometryMenuTaskManager::setClientLineData(GeometryClient& newClient)
{
    std::vector<GeometryPoint> points;

    std::cout << "You must enter a minimum of two points." << std::endl;
    GeometryLine line(getPointData(), getPointData());
    
    while(true)
    {
        try
        {
            char response;
            std::cout << "Do you wish to enter another point? Enter 'y' for yes and 'n' for no. "
            << std::endl;
            std::string lineStr;
            std::getline(std::cin, lineStr);
            response = lineStr[0];
            if (!isalpha(response)) 
            {
                throw std::runtime_error("ERROR: Please enter an alphabetic character.");
            }
            else if ((response != 'y') && (response != 'n'))
            {
                throw std::runtime_error("ERROR: Please enter 'y' for yes or 'n' for no.");
            }
            else
            {
                if (response == 'y')
                {
                    line.addGeometryPoint(getPointData());
                }
                else
                {
                    break;
                }
            }
        }
        catch (const std::exception& exp)
        {
            std::cerr << exp.what() << std::endl;
        }
    }

    newClient.setPoint(new GeometryLine(line));
}

void GeometryMenuTaskManager::setClientPolygonData(GeometryClient& newClient)
{
    std::vector<GeometryPoint> points;

    std::cout << "You must enter a minimum of three points." << std::endl;
    GeometryPolygon polygon(getPointData(), getPointData(), getPointData());

    while(true)
    {
        try
        {
            char response;    
            std::cout << "Do you wish to enter another point? Enter 'y' for yes and 'n' for no. "
            << std::endl;
            std::string line;
            std::getline(std::cin, line);
            response = line[0];
            if (!isalpha(response)) 
            {
                throw std::runtime_error("ERROR: Please enter an alphabetic character.");
            }
            else if ((response != 'y') && (response != 'n'))
            {
                throw std::runtime_error("ERROR: Please enter 'y' for yes or 'n' for no.");
            }
            else
            {
                if (response == 'y')
                {
                    polygon.addGeometryPoint(getPointData());
                }
                else
                {
                    break;
                }
            }
        }
        catch (const std::exception& exp)
        {
            std::cerr << exp.what() << std::endl;
        }
    }

    newClient.setPoint(new GeometryPolygon(polygon));
}