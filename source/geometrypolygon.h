#ifndef GEOMETRY_POLYGON_H
#define GEOMETRY_POLYGON_H

#include "geometrypoint.h"
#include <vector>

/**
 * Defines a polygon object, constructed with a minimum of three
 * geometry point objects 
 **/
class GeometryPolygon : public GeometryPoint{
public:
    /**
     * Requires three sets of Geometry data to be constructed
     **/
    explicit GeometryPolygon(const GeometryPoint& pont1, const GeometryPoint& point2, const GeometryPoint& point3);

    /**
     * Adds a new to GeometryPoint to the list of points
     **/
    void addGeometryPoint(const GeometryPoint& point);

    /**
     * Gets a reference to the geometry points stored by this polygon
     **/
    std::vector<GeometryPoint>& getPoints();

    /**
     * Defines how a GeometryPolygon is displayed 
     **/
    operator const char*();
private:
    std::vector<GeometryPoint> m_points;
    std::string m_polygonStr;
};

#endif //GEOMETRY_POLYGON_H