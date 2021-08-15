#include "boundingbox.h"
#include <algorithm>

BoundingBox::BoundingBox()
{
    
}

BoundingBox::BoundingBox(const BoundingBox& box)
{
    *this = box;
}

BoundingBox::operator const char*()
{
    std::ostringstream oss;
    oss << "(" << m_minLat << "," << m_minLon << ")"
    << "," << "(" << m_maxLat << "," << m_maxLon << ")";
    m_boxStr = oss.str();
    return m_boxStr.c_str();
}

void BoundingBox::operator=(const BoundingBox& box)
{
    this->m_minLat = box.m_minLat;
    this->m_maxLat = box.m_maxLat;
    this->m_minLon = box.m_minLon;
    this->m_maxLon = box.m_maxLon;
}

void BoundingBox::calculateBoundingBox(const GeometryPoint& point)
{
    m_minLat = point.latitude - m_minLatHeight;
    m_minLon = point.longitude - m_minLonHeight;
    m_maxLat = point.latitude + m_minLatHeight;
    m_maxLon = point.longitude + m_minLonHeight;
}

void BoundingBox::calculateBoundingBox(std::vector<GeometryPoint>& points)
{
    auto minMaxLat = std::minmax_element(points.begin(), points.end(), [](const GeometryPoint& p1, const GeometryPoint& p2) {return (p1.latitude < p2.latitude); });
    auto minMaxLon = std::minmax_element(points.begin(), points.end(), [](const GeometryPoint& p1, const GeometryPoint& p2) {return (p1.longitude < p2.longitude); });
    m_minLat = minMaxLat.first->latitude - m_minLatHeight;
    m_minLon = minMaxLon.first->longitude - m_minLonHeight;
    m_maxLat = minMaxLat.second->latitude + m_minLatHeight;
    m_maxLon = minMaxLon.second->longitude + m_minLonHeight;
}

double BoundingBox::getMinLat() const
{
    return m_minLat;
}

double BoundingBox::getMinLon() const
{
    return m_minLon;
}

double BoundingBox::getMaxLat() const
{
    return m_maxLat;
}

double BoundingBox::getMaxLon() const
{
    return m_maxLon;
}