#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

// 15 features used in this program:
// 1) vector
// 2) generate()
// 3) rand()
// 4) range based for loop
// 5) class
// 6) inheritance
// 7) sort()
// 8) default constructor
// 9) const
// 10) auto
// 11) virtual destructor
// 12) min_element()
// 13) friend function
// 14) string
// 15) insert()

  
// base class 
class Base  
{ 
    private:
    int q;
    public: 
    int x;
    Base(int tx) :  x(tx)
    { 
      std::cout << "Base constructor" << std::endl; 
      std::cout << "Value is " << x<< std::endl;
    } 
    virtual ~Base(){
        std::cout << "Base destructor" << std::endl; 
    }
    int FindMin(const std::vector<int> &v){
        return *std::min_element(v.begin(), v.end());
    }
    
}; 
// sub class derived from base class
class Derived: public Base
{   
    private:
    int a, b;
    public: 
    Derived() : Base(5)
    { 
      std::cout<<"Derived constructor"<<std::endl; 
    } 
    ~Derived(){
         std::cout<<"Derived destructor"<<std::endl; 
    }
    void printVector(const std::vector<int> &v)
    {
        std::cout<< "Vector: ";
        for (auto x:v)
            std::cout<< x<<" " ;
        std::cout<< std::endl;
    }
    void getdata(int x, int y)
  {
    a = x;
    b = y;
  }
  friend void fun(Derived);
    
}; 

void fun(Derived obj)
{
  std::cout << "The value of 1st private member: " << obj.a << std::endl;
  std::cout << "The value of 2nd private member: " << obj.b << std::endl;
}
// main function 
int main() 
{    
    //creating strings and insert one string to another
    std::string str1="Fun Program";
    std::string str2="ny";
    str1.insert(3,str2);  
    std::cout << str1 << '\n';

     //creating vector with random numbers
    std::vector<int> v(10);
    std::generate(v.begin(), v.end(), []{
            return rand()%10+1;
        });
    //sorting the vector
    std::sort(v.begin(), v.end(), [](auto l, auto r){
        return r>l;
    });
 
    //creating object of sub class will invoke the constructor of base class
    Derived obj; 
    obj.printVector(v); //calling function printVector from Derived class
    std::cout<<"Min element: "<< obj.FindMin(v)<<std::endl; //calling FindMin function from Base class
    obj.getdata(4, 5); //calling getdata function from Derived class and putting values
    
    return 0; 
} 


