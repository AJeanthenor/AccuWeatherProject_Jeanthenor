#include "geometryline.h"

GeometryLine::GeometryLine(const GeometryPoint& point1, const GeometryPoint& point2)
{
    m_points.push_back(point1);
    m_points.push_back(point2);
}

void GeometryLine::addGeometryPoint(const GeometryPoint& point)
{
    m_points.push_back(point);
}

GeometryLine::operator const char*()
{
    std::ostringstream oss;
    for(std::vector<GeometryPoint>::const_iterator it = m_points.begin(); it != m_points.end(); ++it)
    {
        oss << "(" << it->latitude << "," << it->longitude << "),";
    }
    m_lineStr = oss.str();
    return m_lineStr.c_str();
}

std::vector<GeometryPoint>& GeometryLine::getPoints()
{
    return m_points;
}
