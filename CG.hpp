#ifndef CG_HPP
#define CG_HPP

//*********************************
// Librerias Necesarias
#include "Iter.hpp"
//*********************************

class CG : public Iter
{
   private:
      Timer timer;
   public:
   // Constructor de la clase
   // Gradiente conjugado sin precondicionar
   CG() : Iter(){cname("CG");cprecond(false);};
   template <class T>
   void solve(T &A, Vector &x, Vector &b);
};
#include "CG_imp.hpp"

#endif