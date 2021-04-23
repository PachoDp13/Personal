#include <iostream>
#include <sstream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
 
using big_int = boost::multiprecision::cpp_int;
 
big_int ipow(big_int b, big_int a)
 {
  big_int value(1);
  while (a) {
    if (a & 1)
    {
      value *= b;
    }
    a >>= 1;
    b *= b;
  }
  return value;
}

big_int Ackermann(unsigned m, unsigned n) 
{
  static big_int (*Ack)(unsigned, big_int) =
      [](unsigned m, big_int n)->big_int {
      if (n == 0)
      {
        return 1;
      }
      if (m == 0)
      {
       return ipow(big_int(2), n);
      }
      return Ack(m - 1, Ack(m, n - 1));
  };
  return Ack(m, big_int(n));
}
 
int main()
 {
  std::stringstream value;
  int x = 1;
  int y = 5;   // Para x=1 y y>5 el tiempo de computo es muy grande.
  value << Ackermann(x,y);
  auto texto = value.str();
  std::cout << "A(" << x << ", " << y << ") = (" << texto.length() << " digitos)\n"<< texto.substr(0, 40) << "\n...\n" << texto.substr(texto.length() - 40) << "\n";

  
}