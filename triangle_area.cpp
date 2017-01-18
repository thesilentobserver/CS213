//-----Include required headers here-----
#include <math.h>
//-----End of headers-----

//-----Don't change/delete structs-----
struct vertex{
   float x;
   float y;
};

struct triangle{
    vertex vertices[3];
};
//-----Structs end here


//-----Add new functions here(if any)-----

//-----New functions end here-----

float cal_area(triangle aTriangle) {
    //Write your solution below this line
    
    float a=sqrt(pow((aTriangle.vertices[0].x-aTriangle.vertices[1].x),2)+pow((aTriangle.vertices[0].y-aTriangle.vertices[1].y),2));
    float b=sqrt(pow((aTriangle.vertices[1].x-aTriangle.vertices[2].x),2)+pow((aTriangle.vertices[1].y-aTriangle.vertices[2].y),2));
    float c=sqrt(pow((aTriangle.vertices[2].x-aTriangle.vertices[0].x),2)+pow((aTriangle.vertices[2].y-aTriangle.vertices[0].y),2));
    
    float s=(a+b+c)/2;
    float area=sqrt(s*(s-a)*(s-b)*(s-c));
    
    return (-1);
    //Dont write below this line
}//-----Include required headers here-----
#include <math.h>
//-----End of headers-----

//-----Don't change/delete structs-----
struct vertex{
   float x;
   float y;
};

struct triangle{
    vertex vertices[3];
};
//-----Structs end here


//-----Add new functions here(if any)-----

//-----New functions end here-----

float cal_area(triangle aTriangle) {
    //Write your solution below this line
    
    float a=sqrt(pow((aTriangle.vertices[0].x-aTriangle.vertices[1].x),2)+pow((aTriangle.vertices[0].y-aTriangle.vertices[1].y),2));
    float b=sqrt(pow((aTriangle.vertices[1].x-aTriangle.vertices[2].x),2)+pow((aTriangle.vertices[1].y-aTriangle.vertices[2].y),2));
    float c=sqrt(pow((aTriangle.vertices[2].x-aTriangle.vertices[0].x),2)+pow((aTriangle.vertices[2].y-aTriangle.vertices[0].y),2));
    
    float s=(a+b+c)/2;
    float area=sqrt(s*(s-a)*(s-b)*(s-c));
    
    return (area);
    //Dont write below this line
}

/*

int main() 
{
    
}

*/