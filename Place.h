#ifndef __PLACE__H__
#define __PLACE__H__

#include "Service.h"

class Place
{

 public:
	Place();
	Place(std::string m_name,double m_capacity,double m_area,
		double m_year,std::list<Service> m_services);
	Place(const Place & p);
	virtual ~Place();
//GET
	const std::string getName() const;
	const double getCapacity() const;
	const double getArea() const;
	const double getYear() const;
	virtual const std::list<Service> getServices() const;
	virtual std::list<Service> getServices();

//SET
	void setName(const std::string & name);
	void setCapacity(const double & capacity);
	void setArea(const double & area);
	void setYear(const double & year);
	void setServices(const std::list<Service> & service);


 protected:
    std::string m_name;
    double m_capacity;
    double m_area;
    double m_year;
    std::list<Service> m_services;
};

#include "Place.hxx"
#endif
