#include <iostream>
#include <tclap/CmdLine.h>
#include <string>

#include "main.hpp"
#include "shopping_list.hpp"

using namespace std;


int main(int argc, char* argv[]) {

	string description("Template Tester\n\tThis is a template to launch a command line controled program.\n");
	
	cout << "Hello world !" << endl;

	try {

		TCLAP::CmdLine cmd(description,' ',VERSION,true);

		// TCLAP::ValueArg<std::string> nameArg("n","name","Name to print",true,"homer","string");
		// cmd.add( nameArg );
		// 
		// TCLAP::SwitchArg reverseSwitch("r","reverse","Print name backwards", cmd, false);
		// 
		// UnlabeledValueArg<float>  nolabel( "name", "unlabeled test", 
		// 									3.14, "nameString"  );
		// cmd.add( nolabel );

		TCLAP::SwitchArg IsJobActivated("j","JobActivated","Does effective program", cmd, false);

		cmd.parse(argc,argv);

		// std::string name = nameArg.getValue();
		// bool reverseName = reverseSwitch.getValue();
		// 
		// Insert your program here
		Article prout();
		cout << "prout instancié" << endl;
		


	} catch (TCLAP::ArgException &e) { // catch any exceptions
		cerr << "error: "  << e.error() << " for arg " << e.argId() << endl; 
	}

	return 0;
}