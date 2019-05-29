//Create a program that would compute the following values based on the given sides of the triangle. Let the measurements of the sides be a user-input

#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
 
double angle(double a,double b,double c)
{
	double theta = acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b))*180/PI;
	return theta;
}

int main()
{
	double a,b,c;
	double A,B,C;
	double per, area, p;
	double apothem, circumcenter;

//asking for input
	cout<<"ENTER side a: "; 
	cin>>a;
	cout<<"ENTER side b: "; 
	cin>>b;
	cout<<"ENTER side c: "; 
	cin>>c;
	cout<<" "<<endl;


//if-else statements for all conditions
//A. Compute for all interior angles.
	if(a+b>c && b+c>a && c+a>b){
		A=angle(b,c,a);
		B=angle(c,a,b);
		C=180-A-B;
		
		cout<<"Compute for all interior angles: "<<endl;
		cout<<"Angle A: "<<A<<endl;
		cout<<"Angle B: "<<B<<endl;
		cout<<"Angle C: "<<C<<endl<<endl;
		
//B. Classify whether scalene, isosceles, or equilateral.
		//if all three sides are equal	
		if(a == b && a == c && b == c)
		{
		cout<<"Classify whether scalene, isosceles, or equilateral: "<<endl;
		cout<<"Equilateral Triangle"<<endl<<endl;
		}
		
		//all sides are different, no same length
		else if(a != b && a != c && b != c)
		{
		cout<<"Classify whet her scalene, isosceles, or equilateral: "<<endl;
		cout<<"Scalene Triangle"<<endl<<endl;
		}

        		//only two sides are equal		  
		else
		{
		cout<<"Classify whether scalene, isosceles, or equilateral: "<<endl;
		cout<<"Isosceles Triangle"<<endl<<endl;
		}

//C. Determine the area and perimeter.
		//perimeter is all sides added together
		per = a + b + c;
		p=.5*per;
		//area is the square root of (p *(p - a)*(p - b)*(p - c))
		area=sqrt(p *(p - a)*(p - b)*(p - c)); 
		
		cout<<"Determine the area and perimeter: "<<endl;
		cout<<"Area: "<<area<<endl;
		cout<<"Perimeter: "<<per<<endl<<endl;
		
//D. Classify whether acute triangle, right triangle, or obtuse triangle.	
        		//all angles are acute/ less than 90 degrees
		if(A>0 && A<90 && B>0 && B<90 && C>0 && C<90)
		{
			cout<<"Classify whether acute triangle, right triangle, or obtuse triangle: "<<endl;
			cout<<"Acute Triangle"<<endl<<endl;
		}
		
		//one angle is obtuse/ more than 90 degrees	
		else if(A>90 || B>90 || C>90)
		{
			cout<<"Classify whether acute triangle, right triangle, or obtuse triangle: "<<endl;
			cout<<"Obtuse Triangle"<<endl<<endl;
		}

		//one angle is a right angle/90 degrees	
		else if(a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
		{
			cout<<"Classify whether acute triangle, right triangle, or obtuse triangle: "<<endl;
			cout<<"Right Triangle"<<endl<<endl;
		}
	
//E. Compute for length of apothem and circumcenter.	
		//circumcenter is all sides multiplied divided by the square root of ((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)))
		circumcenter = (a*b*c) / sqrt(((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));

		//apothem is area x 2 divided by the perimeter
		apothem = 2*area/per;
		
		cout<<"Compute for length of apothem and circumcenter: "<<endl;
		cout<<"Length of Apothem: "<<apothem<<endl;
		cout<<"Circumcenter: "<<circumcenter<<endl<<endl;
	}

	//if entered does not fit requirements
	else
		cout<<"Not a triangle";

	return 0;
}

