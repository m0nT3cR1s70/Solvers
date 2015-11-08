#ifndef DIRECT_HPP
#define DIRECT_HPP

class Direct: public Solvers
{
	private:
		double etimer;
		std::string sname;
	public:
		// Nombre del metodo usado
		inline void cname(std::string name){sname = name;};
		// Tiempo usado en la factorizacion
		inline void ctime(double tictoc){etimer = tictoc;};
		// Reporte de daños
		void report();
};
// Reporte de daños
void Direct :: report()
{
	std::cout<<sname<<std::endl;
	std::cout<<"Tiempo de calculo: " << etimer << std::endl;
}


#endif // DIRECT_HPP
