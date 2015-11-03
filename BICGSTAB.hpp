#ifndef BICGSTAB_HPP
#define BICGSTAB_HPP

//*********************************
// Librerias Necesarias
#include "Iter.hpp"
//*********************************

class BICGSTAB : public Iter
{
   private:
      Timer timer;
   public:
   // Constructor de la clase
   // Gradiente conjugado sin precondicionar
   BICGSTAB() : Iter(){cname("BICGSTAB");cprecond(false);};
   template <class T>
   void solve(T &A, Vector &x, Vector &b);
};
#include "BICGSTAB_imp.hpp"

#endif