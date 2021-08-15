#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include "geometrypoint.h"
#include <vector>

/**
 * Defines a geometry line object, constructed with 
 * a minimum of two geometry point objects
 **/
class GeometryLine : public GeometryPoint {
public:
    /**
     * Requires a two sets of geometry points to be constructed
     **/
    explicit GeometryLine(const GeometryPoint& point1, const GeometryPoint& point2);

    /**
     * Adds a new to GeometryPoint to the list of points
     **/
    void addGeometryPoint(const GeometryPoint& point);

    /**
     * Gets a reference to the geometry points stored by this line
     **/
    std::vector<GeometryPoint>& getPoints();

    /**
     * Defines how a GeometryLine is displayed to screen
     **/
    operator const char*();
private:
    std::vector<GeometryPoint> m_points;
    std::string m_lineStr;
};

#endif //GEOMETRY_LINE_H