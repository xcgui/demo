#ifndef tween_h__
#define tween_h__

#include <math.h>

// #define t4 double t,double b,double c,double d
// #define t6 double t,double b,double c,double d,double a,double p
// #define tween(name,tk,i_b,o_b,iob) \
// class t##name \
// {\
// public: \
// 	double In(##t4##) \
// 	{ \
// 		i_b \
// 	} \
// 	double Out(##t4##) \
// 	{ \
// 		o_b \
// 	} \
// 	double InOut(##t4##) \
// 	{ \
// 		iob \
// 	} \
// };
// 
// #define Quadib return (c*(t/=d)*t + b);
// #define Quadob return -c *(t/=d)*(t-2) + b;
// #define Quadiob  if ((t/=d/2) < 1) return c/2*t*t + b; return -c/2 * ((--t)*(t-2) - 1) + b;
// #define tweenQuad() tween(Quad,t4,Quadib,Quadob,Quadiob)
// tweenQuad()

namespace easings
{

enum est{
	est_Quad = 0,
	est_Cubic,
	est_Quart,
	est_Quint,
	est_Sine,
	est_Expo,
	est_Circ,
	est_Elastic,
	est_Back,
	est_Bounce,
};

typedef struct  _tagEasingsParam
{
	double t;
	double b;
	double c;
	double d;
	double s;
	double a;
	double p;
}param;


param CreateParam_Common(double t,double b,double c,double d)
{
	param pm;
	pm.t = t;
	pm.b = b;
	pm.c = c;
	pm.d = d;
	return pm;
}
param CreateParam_Back(double t,double b,double c,double d,double s = 1.70158)
{
	param pm;
	pm.t = t;
	pm.b = b;
	pm.c = c;
	pm.d = d;
	pm.s = s;
	return pm;
}
param CreateParam_Elastic(double t,double b,double c,double d,double a/*a=c*/,double p = 0)
{
	param pm;
	pm.t = t;
	pm.b = b;
	pm.c = c;
	pm.d = d;
	pm.a = a;
	pm.p = p;
	return pm;
}
param CreateParam_All(double t,double b,double c,double d)
{
	double s = 1.70158;
	double a = c/*a=c*/;
	double p = 0;
	param pm;
	pm.t = t;
	pm.b = b;
	pm.c = c;
	pm.d = d;
	pm.s = s;
	pm.a = a;
	pm.p = p;
	return pm;
}

class Object
{
public:
	virtual double In(param p) = 0;
	virtual double Out(param p) = 0;
	virtual double InOut(param p) = 0;
};

class Quad : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
        return c * (t /= d) * t + b;
    }
	double Out(double t, double b, double c, double d)
    {
        return -c * (t /= d) * (t - 2) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
        if ((t /= d / 2) < 1) return c / 2 * t * t + b;
        return -c / 2 * ((--t) * (t - 2) - 1) + b;
    }
};

class Cubic : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
        return c*(t/=d)*t*t + b;
    }
	double Out(double t, double b, double c, double d)
    {
        return c*((t=t/d-1)*t*t + 1) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
		if ((t/=d/2) < 1) return c/2*t*t*t + b;
		return c/2*((t-=2)*t*t + 2) + b;
    }
};


class Quart : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
        return c*(t/=d)*t*t*t + b;
    }
	double Out(double t, double b, double c, double d)
    {
        return -c * ((t=t/d-1)*t*t*t - 1) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
		if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
		return -c/2 * ((t-=2)*t*t*t - 2) + b;
    }
};


class Quint : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
       return c*(t/=d)*t*t*t*t + b;
    }
	double Out(double t, double b, double c, double d)
    {
        return c*((t=t/d-1)*t*t*t*t + 1) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
            if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
            return c/2*((t-=2)*t*t*t*t + 2) + b;
    }
};

#define PI 3.141592653

class Sine : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
		return -c * cos(t/d * (PI/2)) + c + b;
    }
	double Out(double t, double b, double c, double d)
    {
         return c * sin(t/d * (PI/2)) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
		return -c/2 * (cos(PI*t/d) - 1) + b;
    }
};

class Expo : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
		return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
    }
	double Out(double t, double b, double c, double d)
    {
		return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
		if (t==0) return b;
		if (t==d) return b+c;
		if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
            return c/2 * (-pow(2, -10 * --t) + 2) + b;
    }
};


class Circ : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
		return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
    }
	double Out(double t, double b, double c, double d)
    {
		return c * sqrt(1 - (t=t/d-1)*t) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
            if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
            return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
    }
};




class Elastic : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d,p.a,p.p);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d,p.a,p.p);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d,p.a,p.p);
	}
public:
    double In(double t, double b, double c, double d,double a/*a=c*/,double p = 0)
    {
		double s = 1.70158;
		if (t==0) return b;
		if ((t/=d)==1) return b+c;
		if (!p) p=d*.3;
		if (!a || a < abs(c))
		{
			a=c; double s=p/4;
		}
		else
		{
			s = p/(2*PI) * asin (c/a);	
		}
		return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*PI)/p )) + b;
    }
	double Out(double t, double b, double c, double d,double a,double p)
    {
		double s = 1.70158;
		if (t==0) return b;
		if ((t/=d)==1) return b+c;
		if (!p) p=d*.3;
		if (!a || a < abs(c))
		{
			a=c; double s=p/4;
		}
		else
		{
			s = p/(2*PI) * asin (c/a);
		}
		return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
    }
	double InOut(double t, double b, double c, double d,double a,double p)
    {
		double s = 1.70158;
		if (t==0) return b;
		if ((t/=d/2)==2) return b+c;
		if (!p) p=d*(.3*1.5);
		if (!a || a < abs(c))
		{
			a=c; double s=p/4;
		}
		else
		{
			s = p/(2*PI) * asin (c/a);
			if (t < 1) 
				return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*PI)/p )) + b;
			
		}
		return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*(2*PI)/p )*.5 + c + b;
    }
};



class Back : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d,p.s);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d,p.s);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d,p.s);
	}
public:
    double In(double t, double b, double c, double d,double s = 1.70158)
    {
        return c*(t/=d)*t*((s+1)*t - s) + b;
    }
	double Out(double t, double b, double c, double d,double s = 1.70158)
    {
            return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
    }
	double InOut(double t, double b, double c, double d,double s = 1.70158)
    {
            if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525))+1)*t - s)) + b;
            return c/2*((t-=2)*t*(((s*=(1.525))+1)*t + s) + 2) + b;
    }
};


class Bounce : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
public:
    double In(double t, double b, double c, double d)
    {
		return c - Out(d-t, 0, c, d) + b;
    }
	double Out(double t, double b, double c, double d)
    {
		if ((t/=d) < (1/2.75)) {
			return c*(7.5625*t*t) + b;
		} else if (t < (2/2.75)) {
			return c*(7.5625*(t-=(1.5/2.75))*t + .75) + b;
		} else if (t < (2.5/2.75)) {
			return c*(7.5625*(t-=(2.25/2.75))*t + .9375) + b;
		} else {
			return c*(7.5625*(t-=(2.625/2.75))*t + .984375) + b;
            }
    }
	double InOut(double t, double b, double c, double d)
    {
        if (t < d/2) return In(t*2, 0, c, d) * .5 + b;
        else return Out(t*2-d, 0, c, d) * .5 + c*.5 + b;
    }
};

class BounceEx : public Object
{
public:
	virtual double In(param p)
	{
		return In(p.t,p.b,p.c,p.d);
	}
	virtual double Out(param p)
	{
		return Out(p.t,p.b,p.c,p.d);
	}
	virtual double InOut(param p)
	{
		return InOut(p.t,p.b,p.c,p.d);
	}
	
public:
    double In(double t, double b, double c, double d)
    {
		return c - Out(d-t, 0, c, d) + b;
    }
	double Out(double t, double b, double c, double d)
    {
		if ((t/=d) < (1/2.75))
		{
			return c*(7.5625*t*t) + b;
		} else if (t < (2/2.75))
		{
			return c*(7.5625*(t-=(1.5/2.75))*t + .75) + b;
		} else if (t < (2.5/2.75)) {
			return c*(7.5625*(t-=(2.25/2.75))*t + .9375) + b;
		} else {
			return c*(7.5625*(t-=(2.625/2.75))*t + .984375) + b;
		}
    }
	double InOut(double t, double b, double c, double d)
    {
		if (t < d/2) return In(t*2, 0, c, d) * .5 + b;
		else return Out(t*2-d, 0, c, d) * .5 + c*.5 + b;
    }
};

}; //easings

#endif // tween_h__