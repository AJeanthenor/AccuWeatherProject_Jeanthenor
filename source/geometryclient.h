#ifndef GEOMETRY_CLIENT_H
#define GEOMETRY_CLIENT_H

#include <string>
#include "geometrytype.h"
#include "geometrypoint.h"
#include "boundingbox.h"

/**
 * Defines the GeometryClient object
 * GeometryClient has a name, type, geometrydata and a bounding box
 **/
class GeometryClient
{
public:
    /**
     * Default constructor
     **/ 
    GeometryClient();

    /**
     * Copy constructor
     **/
    GeometryClient(const GeometryClient& client);

    /**
     * Defines how the GeometryClient will be displayed as a c-string
     **/
    operator const char*();

    /**
     * Gets the client Data as a c-string
     **/
    const char* getClientData();

    /**
     * Assignment Operator overload
     **/
    void operator=(const GeometryClient& client);

    /**
     * Sets the GeometryType
     **/
    void setType(GeometryType type);

    /**
     * Sets the client name
     **/
    void setName(const std::string& name);

    /**
     * Sets the GeometryPoint
     **/
    void setPoint(GeometryPoint* point);

    /**
     * Sets the bounding box
     */
    void setBoundingBox(BoundingBox box);

    /**
     * Gets the GeometryType
     **/
    const GeometryType getType() const;

    /**
     * Gets the client name
     */
    const std::string getName() const;

    /**
     * Gets the GeometryPoint
     **/
    GeometryPoint* getPoint() const;

    /**
     * Gets the BoundingBox
     **/
    BoundingBox getBoundingBox() const;

private:
    /**
    * Gets the c-string representation of the geometry type
    * and geometry data
    **/
    void getGeometryDataString(std::ostringstream& oss);

    /**
    * Gets the c-string representations of the geometry data
    **/
    void getBoundingBoxString(std::ostringstream& oss);

    /**
    * Commands GeometryClient to generate it's bounding box
    **/
    void generateBoundingBox();

    std::string    m_clientName;
    GeometryType   m_geometryType;
    GeometryPoint* m_point;
    BoundingBox    m_boundingBox;
    std::string    m_geometryClientStr;
};

#endif //GEOMETRY_CLIENT_H