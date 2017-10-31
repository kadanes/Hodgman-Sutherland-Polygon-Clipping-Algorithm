#include<stdio.h>
#include<graphics.h>
typedef struct coordinate {

int x;
int y;

} point;


point findX(point start, point end, int y ){
  point intersection;
  int x1 = start.x;
  int y1 = start.y;
  int x2 = end.x;
  int y2 = end.y;
  int x = x1 + ( (y-y1) * (x2 - x1) /(y2 - y1));

  intersection.x = x;
  intersection.y = y;

  return intersection;
}

point findY(point start, point end, int x ){
  point intersection;
  int x1 = start.x;
  int y1 = start.y;
  int x2 = end.x;
  int y2 = end.y;
  int y = y1 + ( (y2-y1) * (x - x1) /(x2 - x1));

  intersection.x = x;
  intersection.y = y;

  return intersection;

}


void boundryFill(int x, int y, int color, int boundryColor ){

  if(getpixel(x,y) !=  color &&  getpixel(x,y) != boundryColor){
    putpixel(x,y,color);
    boundryFill(x+1,y,color,boundryColor);
    boundryFill(x,y+1,color,boundryColor);
    boundryFill(x-1,y,color,boundryColor);
    boundryFill(x,y-1,color,boundryColor);
  }

}

int main(){

int left = 100, right = 450, top = -50, bottom = -400;
int offset = 50;
int counter, size = 20;

int boundries[4];
boundries[0] = left;
boundries[1] = top;
boundries[2] = right;
boundries[3] = bottom;


/*
/ Set number of points and there values here, 
/ keeping in mind that they need to be in cyclic order
/ You can take input from user. 
*/

point points[size];
int innitialPointCount = 5;
int orignalPointCount = innitialPointCount;
//First point - left of left
points[0].x = left - 40;
points[0].y = top - 90;
//Second point = top of top, left of left
points[1].x = left + 80;
points[1].y = top + 30;
//Third point - right of right
points[2].x = right + 60;
points[2].y = bottom + 80;
//Forth point - below - bottom
points[3].x = right  - 100;
points[3].y = bottom - 80;
//Fifth point - Inside the polygon
points[4].x = left + 30;
points[4].y = bottom + 20;

point orignalPoints[size];

for (counter = 0; counter < size; counter += 1){
  orignalPoints[counter] = points[counter];
}

int boundryCount;

for (boundryCount = 0; boundryCount < 4; boundryCount += 1){

  int currentBoundry = boundries[boundryCount];
  point newPoints[size];
  int newPointCount = 0;

  int pointToGoThrough;
  printf("Iteration: %d\n",boundryCount);
  for (pointToGoThrough = 0; pointToGoThrough < innitialPointCount; pointToGoThrough += 1){
    point start = points[pointToGoThrough], end = points[(pointToGoThrough + 1) % innitialPointCount];
    printf("Points are: \nStart: X:%d Y:%d\nEnd: X:%d Y:%d\n",start.x,start.y,end.x,end.y);
    switch (boundryCount) {


      case 0: { //Left
        if( start.x < currentBoundry && end.x < currentBoundry){//Out
          printf("Both out:\n" );
          break;
        } else if ( start.x >= currentBoundry && end.x >= currentBoundry){//Both in
            printf("Both in:\n" );
            newPoints[newPointCount] = end;
            newPointCount += 1;
        } else if ( start.x < currentBoundry && end.x > currentBoundry) {//Out to In
            printf("Out In:\n" );
            point leftIntersect = findY(start, end, currentBoundry);
            newPoints[newPointCount] = leftIntersect;
            newPointCount += 1;
            newPoints[newPointCount] = end;
            newPointCount += 1;
        } else if (start.x > currentBoundry && end.x < currentBoundry) {//In to Out
            printf("In Out:\n" );
            point leftIntersect = findY(start, end, currentBoundry);
            newPoints[newPointCount] = leftIntersect;
            newPointCount += 1;

            printf("Point is: X:%d Y:%d\n",leftIntersect.x,leftIntersect.y);
        }
        break;
      }
      case 1: { //Top
        if( start.y > currentBoundry && end.y > currentBoundry){//Out
          printf("Both out:\n" );
          break;
        } else if ( start.y <= currentBoundry && end.y <= currentBoundry){//Both in
            printf("Both in:\n" );
            newPoints[newPointCount] = end;
            newPointCount += 1;
        } else if ( start.y > currentBoundry && end.y < currentBoundry) {//Out to In
            printf("Out In:\n" );
            point topIntersect = findX(start, end, currentBoundry);
            newPoints[newPointCount] = topIntersect;
            newPointCount += 1;
            newPoints[newPointCount] = end;
            newPointCount += 1;

        } else if (start.y < currentBoundry && end.y > currentBoundry) {//In to Out
            printf("In Out:\n" );
            
            point topIntersect = findX(start, end, currentBoundry);
            newPoints[newPointCount] = topIntersect;
            newPointCount += 1;

            printf("Point is: X:%d Y:%d\n",topIntersect.x,topIntersect.y);
        }
        break;
      }
      case 2: { //Right
        if( start.x > currentBoundry && end.x > currentBoundry){//Out
          printf("Both out:\n" );
          break;
        } else if ( start.x <= currentBoundry && end.x <= currentBoundry){//Both in
            printf("Both in:\n" );
            newPoints[newPointCount] = end;
            newPointCount += 1;
        } else if ( start.x > currentBoundry && end.x < currentBoundry) {//Out to In
            printf("Out In:\n" );
            point leftIntersect = findY(start, end, currentBoundry);
            newPoints[newPointCount] = leftIntersect;
            newPointCount += 1;
            newPoints[newPointCount] = end;
            newPointCount += 1;
        } else if (start.x < currentBoundry && end.x > currentBoundry) {//In to Out
            printf("In Out:\n" );
            point leftIntersect = findY(start, end, currentBoundry);
            newPoints[newPointCount] = leftIntersect;
            newPointCount += 1;
        }
        break;
      }
      case 3: { //Bottom
        if( start.y < currentBoundry && end.y < currentBoundry){//Out
          printf("Both out:\n" );
          break;
        } else if ( start.y >= currentBoundry && end.y >= currentBoundry){//Both in
            printf("Both in:\n" );
            newPoints[newPointCount] = end;
            newPointCount += 1;
        } else if ( start.y < currentBoundry && end.y > currentBoundry) {//Out to In
            printf("Out In\n");
            point topIntersect = findX(start, end, currentBoundry);
            newPoints[newPointCount] = topIntersect;
            newPointCount += 1;
            newPoints[newPointCount] = end;
            newPointCount += 1;

        } else if (start.y > currentBoundry && end.y < currentBoundry) {//In to Out
            printf("In Out:\n" );
            point topIntersect = findX(start, end, currentBoundry);
            newPoints[newPointCount] = topIntersect;
            newPointCount += 1;
        }
        break;
      }
    }
  }


  for (counter = 0; counter < size; counter += 1){
    points[counter] = newPoints[counter];
  }
  innitialPointCount = newPointCount;
  printf("\n");
  for (int count = 0; count < innitialPointCount; count += 1 ){
    printf("Point %d: X:%d Y:%d\n",count, points[count].x, points[count].y );
  }
  printf("\n");
}

int gd = DETECT, gm;
initgraph(&gd, &gm, "");

printf("                               Hodgman Sutherland Algorithm");
int fullShapeColor = 0;
int clippedShapeColor = 2;
int pointToGoThrough;
setcolor(15);
for (pointToGoThrough = 0; pointToGoThrough < orignalPointCount ; pointToGoThrough += 1){
  point start = orignalPoints[pointToGoThrough], end = orignalPoints[(pointToGoThrough + 1) % orignalPointCount];
  line(start.x,-1 * start.y,end.x, -1 * end.y);
}
//boundryFill(orignalPoints[0].x + 15 , -1 * orignalPoints[0].y + 1, fullShapeColor, 8 );

setcolor(5);
line(left,-1 * top,right,-1 * top);
line(left,-1 * bottom,right,-1 * bottom);
line(left,-1 * top,left,-1 * bottom);
line(right,-1 * top,right,-1 * bottom);

setcolor(8);

for (pointToGoThrough = 0; pointToGoThrough < innitialPointCount; pointToGoThrough += 1){
  point start = points[pointToGoThrough], end = points[(pointToGoThrough + 1) % innitialPointCount];
  line(start.x,-1 * start.y,end.x, -1 * end.y);
}

boundryFill( ( points[0].x + points[3].x )   / 2  , -1 * points[0].y - 1 , clippedShapeColor, 8 );


getch();
closegraph();
}
