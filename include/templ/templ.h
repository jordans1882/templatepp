#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include <iostream>
#include <vector>

namespace templ {

class Templ {
   public:
      void helloWorld( void );
      Templ();  // This is the constructor
   private:
      double length;
};

// Member functions definitions including constructor
Templ::Templ(void) {
   std::cout << "Object is being created" << std::endl;
}

// Member functions definitions including constructor
void Templ::helloWorld( void ) {
  length = 1.23;
   std::cout << "Hello World" << std::endl;
   std::cout << "Length is " << length << std::endl;
}

};
#endif
