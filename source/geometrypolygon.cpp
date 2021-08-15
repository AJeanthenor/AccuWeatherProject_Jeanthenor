#include "geometrypolygon.h"
#include <iterator>

GeometryPolygon::GeometryPolygon(const GeometryPoint& point1, const GeometryPoint& point2, const GeometryPoint& point3)
{
    m_points.push_back(point1);
    m_points.push_back(point2);
    m_points.push_back(point3);
}
void GeometryPolygon::addGeometryPoint(const GeometryPoint& point)
{
    m_points.push_back(point);
}

std::vector<GeometryPoint>& GeometryPolygon::getPoints()
{
    return m_points;
}

GeometryPolygon::operator const char*()
{
    std::ostringstream oss;
    for(std::vector<GeometryPoint>::const_iterator it = m_points.begin(); it != m_points.end(); ++it)
    {
        oss << "(" << it->latitude << "," << it->longitude << "),";
    }
    m_polygonStr = oss.str();
    return m_polygonStr.c_str();
}