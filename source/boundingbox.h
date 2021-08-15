#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "geometrypoint.h"
#include <vector>

/**
 * Defines the BoundingBox object
 **/ 
class BoundingBox
{
public:
    const double m_minLatHeight = 0.002;
    const double m_minLonHeight = 0.002;

    /**
     * Default Constructor
     **/
    BoundingBox();

    /**
     * Copy constructor
     **/
    BoundingBox(const BoundingBox& box);

    /**
     * C-String representation of the BoundingBox 
     */ 
    operator const char*();

    /**
     * Assignment Operator overload
     */
    void operator=(const BoundingBox& box);

    /**
    * Gets the minimum latitude
    **/
    double getMinLat() const;

    /**
    * Gets the minimum longitude
    **/
    double getMinLon() const;

    /**
    * Gets the maximum latitude
    **/
    double getMaxLat() const;

    /**
    * Gets the maximum longitude
    **/
    double getMaxLon() const;

    /**
    * Calculates the bounding box of a single point
    */
    void calculateBoundingBox(const GeometryPoint& point);

    /**
     * Calculates the bounding box of a vector of points
     */
    void calculateBoundingBox(std::vector<GeometryPoint>& points);

private:

    /**
     * Compares two point objects and finds the point with the minimum latitude
     */ 
    bool minLatCompare(const GeometryPoint& p1, const GeometryPoint& p2);

    /**
     * Compares two point objects and finds the point with the minimum longitude
     **/
    bool minLonCompare(const GeometryPoint& p1, const GeometryPoint& p2);

    /**
     * Compares two point objects and finds the point with the maximum latitude
     */ 
    bool maxLatCompare(const GeometryPoint& p1, const GeometryPoint& p2);

    /**
     * Compares two point objects and finds the point with the maximum longitude
     **/
    bool maxLonCompare(const GeometryPoint& p1, const GeometryPoint& p2);

    double m_minLat;
    double m_minLon;
    double m_maxLat;
    double m_maxLon;
    std::string m_boxStr;
};

#endif //BOUNDING_BOX_H