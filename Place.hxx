#ifndef __PLACE__HXX__
#define __PLACE__HXX__

Place::Place()

:m_name(NULL)

//,m_capacity(0),
//m_area(0),
//m_year(0)
//,m_services()
{
//   this->m_name=NULL;               
   this->m_capacity=0;
   this->m_area=0;
   this->m_year=0;
   
   std::list<Service> services;
   this->m_services=services;
}
//------------------------------------------------------
Place::Place(std::string name,double capacity,double area,
       double year,std::list<Service> services)
:m_name(name),
m_capacity(capacity),
m_area(area),
m_year(year),
m_services(services)
{
}
//------------------------------------------------------
Place::Place(const Place & p)
:m_name(p.m_name),
m_capacity(p.m_capacity),
m_area(p.m_area),
m_year(p.m_year),
m_services(p.m_services)
{
}
//------------------------------------------------------
Place::~Place()
{
//    delete(m_services);
}
//------------------------------------------------------
//GET
const std::string Place::getName() const
{
    return(m_name);
}
//------------------------------------------------------
const double Place::getCapacity() const
{
    return(m_capacity);
}
//------------------------------------------------------
const double Place::getArea() const
{
    return(m_area);
}
//------------------------------------------------------
const double Place::getYear() const
{
    return(m_year);
}
//------------------------------------------------------
const std::list<Service> Place::getServices() const
{
    return(m_services);
}
//------------------------------------------------------
std::list<Service> Place::getServices()
{
    return(m_services);
}
//------------------------------------------------------
//SET
void Place::setName(const std::string & name)
{
    this->m_name=name;
}
//------------------------------------------------------
void Place::setCapacity(const double & capacity)
{
    this->m_capacity=capacity;
}
//------------------------------------------------------
void Place::setArea(const double & area)
{
    this->m_area=area;
}
//------------------------------------------------------
void Place::setYear(const double & year)
{
    this->m_year=year;
}
//------------------------------------------------------
void Place::setServices(const std::list<Service> & service)
{
    this->m_services=service;
}
//------------------------------------------------------

#endif
