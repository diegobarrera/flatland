#ifndef __POINT__H__
#define __POINT__H__

#include "Place.h"

class Point
{
 public:
	Point();
	Point(std::string id, float x,float y, Place place);
	Point(const Point & p);
	virtual ~Point();

//GET
	const std::string getId() const;
	const float getX() const;
	const float getY() const;
	virtual const Place getPlace() const;
	virtual Place getPlace();

//SET
	void setId(const std::string & s);
	void setX(const float & x);
	void setY(const float & y);
	void setPlace(const Place & p);


 protected:
	std::string m_id;
        float m_x;
        float m_y;
        Place m_place;
};

#include "Point.hxx"
#endif
