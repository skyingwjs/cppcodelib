#include "mcmf.h"
////////////////////////////////////////////////////////////////////////////////
//
// main
//
////////////////////////////////////////////////////////////////////////////////

int main( int argc, char *argv[])
{
	//"p min 6 8
	//c min-cost flow problem with 6 nodes and 8 arcs
	//n 1 10
	//c supply of 10 at node 1
	//n 6 -10
	//c demand of 10 at node 6
	//c arc list follows
	//c arc has <tail> <head> <capacity l.b.> <capacity u.b> <cost>
	//a 1 2 0 4 1
	//a 1 3 0 8 5
	//a 2 3 0 5 0
	//a 3 5 0 10 1
	//a 5 4 0 8 0
	//a 5 6 0 8 9
	//a 4 2 0 8 1
	//a 4 6 0 8 1"
	int num_nodes = 6;
	int num_arcs = 8;
	MCMF_CS2 my_mcmf_problem( num_nodes, num_arcs);

	my_mcmf_problem.set_arc( 1, 2, 0, 4, 1);
	my_mcmf_problem.set_arc( 1, 3, 0, 8, 5);
	my_mcmf_problem.set_arc( 2, 3, 0, 5, 0);
	my_mcmf_problem.set_arc( 3, 5, 0, 10, 1);
	my_mcmf_problem.set_arc( 5, 4, 0, 8, 0);
	my_mcmf_problem.set_arc( 5, 6, 0, 8, 9);
	my_mcmf_problem.set_arc( 4, 2, 0, 8, 1);
	my_mcmf_problem.set_arc( 4, 6, 0, 8, 1);
	my_mcmf_problem.set_supply_demand_of_node( 1, 10);
	my_mcmf_problem.set_supply_demand_of_node( 6, -10);

	my_mcmf_problem.run_cs2();

	return 0;
}
