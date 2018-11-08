#ifndef __SERVICE__H__
#define __SERVICE__H__

class Service
{
 public:
	Service();
	Service(std::string service, int popularity);
	Service(const Service & s);
	virtual ~Service();

//GET
	const std::string getService() const;
	const int getPopularity()const;

//SET
	void setService(const std::string & s);
	void setPopularity(const int & p);

 protected:
    std::string m_service;
    int m_popularity;
};

#include "Service.hxx"
#endif
