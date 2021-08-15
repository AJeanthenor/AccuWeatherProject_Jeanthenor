#include "geometryclient.h"
#include "geometryline.h"
#include "geometrypolygon.h"
#include <iomanip>

GeometryClient::GeometryClient()
{
}

GeometryClient::GeometryClient(const GeometryClient& client)
{
    *this = client;
}

GeometryClient::operator const char*()
{
    std::ostringstream oss;
    oss << "Name: " << m_clientName.c_str() << std::endl;
    getGeometryDataString(oss);
    getBoundingBoxString(oss);
    m_geometryClientStr = oss.str();
    return m_geometryClientStr.c_str();
}

void GeometryClient::operator=(const GeometryClient& client)
{
    setName(client.getName());
    setType(client.getType());
    setPoint(client.getPoint());
    setBoundingBox(client.getBoundingBox());
}

void GeometryClient::setType(GeometryType type)
{
    m_geometryType = type;
}

void GeometryClient::setName(const std::string& name)
{
    m_clientName = name;
}

void GeometryClient::setPoint(GeometryPoint* point)
{
    m_point = point;
    generateBoundingBox();
}

void GeometryClient::generateBoundingBox()
{
    switch (m_geometryType)
    {
    case POINT:
        m_boundingBox.calculateBoundingBox(*m_point);
        break;
    case LINE:
    {
        GeometryLine* line = dynamic_cast<GeometryLine*>(m_point);
        std::vector<GeometryPoint> points = line->getPoints();
        m_boundingBox.calculateBoundingBox(points);
        break;
    }
    case POLYGON:
    {
        GeometryPolygon* poly = dynamic_cast<GeometryPolygon*>(m_point);
        std::vector<GeometryPoint> points = poly->getPoints();
        m_boundingBox.calculateBoundingBox(poly->getPoints());
        break;
    }
    }
}

void GeometryClient::setBoundingBox(BoundingBox box)
{
    m_boundingBox = box;
}

const GeometryType GeometryClient::getType() const
{
    return m_geometryType;
}

const std::string GeometryClient::getName() const
{
    return m_clientName;
}

GeometryPoint* GeometryClient::getPoint() const
{
    return m_point;
}

void GeometryClient::getGeometryDataString(std::ostringstream& oss)
{
    switch(m_geometryType)
    {
        case GeometryType::POINT:
        {
            oss << "Geometry Type: " << "Point" << std::endl
                << std::fixed << std::setprecision(4) << "Geometry Data: "
                << "(" << m_point->latitude << "," << m_point->longitude << ")"
                << std::endl;
        }
        break;
        case GeometryType::LINE:
        {
            GeometryLine* line = dynamic_cast<GeometryLine*>(m_point);
            oss << "Geometry Type: " << "Line" << std::endl
                << std::fixed << std::setprecision(4) << "Geometry Data: ";
            std::vector<GeometryPoint> points = line->getPoints();
            for (std::vector<GeometryPoint>::iterator it = points.begin(); it != points.end(); ++it)
            {
                oss << "(" << it->latitude << "," << it->longitude << "),";
            }
            oss << std::endl;
        }
            break;
        case GeometryType::POLYGON:
        {
            GeometryPolygon* poly = dynamic_cast<GeometryPolygon*>(m_point);
            oss << "Geometry Type: " << "Polygon" << std::endl
                << std::fixed << std::setprecision(4) << "Geometry Data: ";
            std::vector<GeometryPoint> points = poly->getPoints();
            for (std::vector<GeometryPoint>::iterator it = points.begin(); it != points.end(); ++it)
            {
                oss << "(" << it->latitude << "," << it->longitude << "),";
            }
            oss << std::endl;
        }
            break;
    }
}

void GeometryClient::getBoundingBoxString(std::ostringstream& oss)
{
    oss << "Bounding Box: " << std::fixed << std::setprecision(4)
        << "(" << m_boundingBox.getMinLat() << "," << m_boundingBox.getMinLon() << "),"
        << "(" << m_boundingBox.getMaxLat() << "," << m_boundingBox.getMaxLon() << ")"
        << std::endl;
}

BoundingBox GeometryClient::getBoundingBox() const
{
    return m_boundingBox;
}