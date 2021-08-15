#include "geometrypoint.h"

GeometryPoint::GeometryPoint()
{
    
}


GeometryPoint::GeometryPoint(double lat, double lon)
{
    latitude  = lat;
    longitude = lon;
}

GeometryPoint::GeometryPoint(const GeometryPoint& data)
{
    *this = data;
}

void GeometryPoint::operator=(const GeometryPoint& data)
{
    this->latitude  = data.latitude;
    this->longitude = data.longitude;
}

void GeometryPoint::addGeometryPoint(const GeometryPoint& point)
{
    return;
}

GeometryPoint::operator const char *()
{
    std::ostringstream oss;
    oss << "(" << latitude << "," << longitude << ")";
    m_pointStr = oss.str();
    return m_pointStr.c_str();
}