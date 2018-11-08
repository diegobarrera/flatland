#ifndef __SERVICE__HXX__
#define __SERVICE__HXX__

Service::Service()
:m_service(NULL),
m_popularity(0)
{}
//---------------------------------------------------------
Service::Service(std::string service, int popularity)
:m_service(service),
m_popularity(popularity)
{}
//---------------------------------------------------------
Service::Service(const Service & s)
:m_service(s.m_service),
m_popularity(s.m_popularity)
{}
//---------------------------------------------------------
Service::~Service()
{}
//---------------------------------------------------------
//GET
const std::string Service::getService() const
{
    return(m_service);
}
//---------------------------------------------------------
const int Service::getPopularity()const
{
    return(m_popularity);
}
//---------------------------------------------------------
//SET
void Service::setService(const std::string & s)
{
    this->m_service=s;
}
//---------------------------------------------------------
void Service::setPopularity(const int & p)
{
    this->m_popularity=p;
}
//---------------------------------------------------------

#endif
