#ifndef __PLACE__H__
#define __PLACE__H__

class Place
{
 public:

 protected:
    std::string m_name;
    double m_capacity;
    double m_area;
    double m_year;
    std::list<Service> * m_services;
};

#endif
