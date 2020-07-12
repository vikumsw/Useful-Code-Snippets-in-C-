// Example program
#include <iostream>
#include <string>
#include <initializer_list>


void minusOneFinder(std::initializer_list<int> list)
{
    for( auto elem : list )
    {
        if( elem == -1 )
        {
            std::cout << "-1 found" << std::endl;
            return;
        }
        
        std::cout << elem << std::endl;
    }
};


int main()
{  
  minusOneFinder({1,2,3,-1,4,5,5});
}
