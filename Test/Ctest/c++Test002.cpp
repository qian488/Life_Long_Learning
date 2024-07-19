#include <iostream>
 
using namespace std;
 
// 基类 Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// 基类 PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// 派生类
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

int main(void)
{
   Rectangle Rect;
   int area;
   int cWidth, cHeight;

   cout << "Width:";
   cin >> cWidth;
   Rect.setWidth(cWidth);
   cout << "Height:";
   cin >> cHeight;
   Rect.setHeight(cHeight);
 
   area = Rect.getArea();
   
   cout << "Total area: " << Rect.getArea() << endl;

   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
 
   return 0;
}