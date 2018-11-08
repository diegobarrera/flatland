#ifndef __POINT__HXX__
#define __POINT__HXX__

Point::Point()
:m_id(NULL)
{
   this->m_x=0;
   this->m_y=0;

   Place place;
   this->m_place=place;
}
//----------------------------------------------------------------
Point::Point(std::string id, float x,float y, Place place)
:m_id(id),
m_x(x),
m_y(y),
m_place(place)
{
}
//----------------------------------------------------------------
Point::Point(const Point & p)
:m_id(p.m_id),
m_x(p.m_x),
m_y(p.m_y),
m_place(p.m_place)
{
}
//----------------------------------------------------------------
Point::~Point()
{
}
//----------------------------------------------------------------
//GET
const std::string Point::getId() const
{
    return(m_id);
}
//----------------------------------------------------------------
const float Point::getX() const
{
    return(m_x);
}
//----------------------------------------------------------------
const float Point::getY() const
{
    return(m_y);
}
//----------------------------------------------------------------
const Place Point::getPlace() const
{
    return(m_place);
}
//----------------------------------------------------------------
Place Point::getPlace()
{
    return(m_place);
}
//----------------------------------------------------------------
//SET
void Point::setId(const std::string & s)
{
    this->m_id=s;
}
//----------------------------------------------------------------
void Point::setX(const float & x)
{
    this->m_x=x;
}
//----------------------------------------------------------------
void Point::setY(const float & y)
{
    this->m_y=y;
}
//----------------------------------------------------------------
void Point::setPlace(const Place & p)
{
    this->m_place=p;
}
//----------------------------------------------------------------

#endif
