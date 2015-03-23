
/////////////////////////////
// Point 2D Class
////////////////////////////

#ifndef __P2Point_H__
#define __P2Point_H__
#include <math.h>
template<class TYPE>

class P2Point
{
public:
	TYPE x, y;

	 P2Point operator - (const P2Point &v) const
	{
		 P2Point tmp;
		 tmp.x = x - v.x;
		 tmp.y = y - v.y;
		 return(tmp);
	 }

	 P2Point operator + (const P2Point &v) const
	 {
		 P2Point tmp;
		 tmp.x = x + v.x;
		 tmp.y = y - v.y;
		 return(tmp);
	 }
	 
	 const P2Point &operator -= (const P2Point &v)
	 {
		 P2Point tmp;
		 x -= v.x;
		 y -= v.y;
	 }

	 const P2Point &operator += (const P2Point &v)
	 {
		 P2Point tmp;
		 x += v.x;
		 y += v.y;
	 }

	 bool operator == (const P2Point &v)
	 {
		 return(x == v.x && y == v.y)
	 }

	 bool operator != (const P2Point &v)
	 {
		 return(x != v.x || y != v.y)
	 }

	 /////////////////
	 // Utils
	 ////////////////

	 bool isZero() const
	 {
		 return (x == 0 && y == 0)
	 }

	 P2Point &setZero()
	 {
		 x = y = 0;
		 return(*this);
	 }

	 P2Point &negate()
	 {
		 x = -x;
		 y = -y;
		 return(*this);
	 }

	 //////////////
	 // Distances
	 /////////////

	 TYPE DistanceTo(const P2point &v) const
	 {
		 TYPE fx = x - v.x;
		 TYPE fy = y - v.y;

		 return sqrt((fx*fx) + (fy*fy));
	 }




};



#endif
