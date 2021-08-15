#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include <string>
#include <sstream>

/**
 * Defines a GeometryPoint, consists of a latitude and longitude
 **/
class GeometryPoint {
public:
    /**
     * Default constructor
     **/
    GeometryPoint();

    /**
     * Requires a single set of data to be constructed
     **/
    GeometryPoint(double latitude, double longitude);

    /**
     * Copy Constructor
     **/
    GeometryPoint(const GeometryPoint& point);

    /**
     * Defines how to assign a GeometryData object to 
     * the GeometryPoint
     **/
    void operator=(const GeometryPoint& data);

    /**
     * Adds a new GeometryPoint
     **/
    virtual void addGeometryPoint(const GeometryPoint& point);

    /**
     * Defines how to display a geometry point
     **/
    virtual operator const char*();

    double latitude;
    double longitude;
    std::string m_pointStr;
};

#endif //GEOMETRY_POINT_H