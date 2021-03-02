#include <iostream>


void try_func() try {
  // stuff...
  int y = 0; // should fail
  
  throw "FATAL ERROR";

}
catch (std::exception& err) {
  throw "DAMN";
}
catch (char const& err) {
  throw "DAMN";
}


int main() {

  try_func();

  return 0;
}
