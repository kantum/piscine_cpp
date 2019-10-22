#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

void			ShrubberyCreationForm::setTarget(std::string s)
{
	this->_target = s;
}

std::string		ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void	ShrubberyCreationForm::executeFunction(void) const
{
	std::ofstream myfile;
	myfile.open (this->getTarget());

	myfile << "........................................................................................................................" << std::endl;
	myfile << "........................................................................................................................" << std::endl;
	myfile << "........................................................................................................................" << std::endl;
	myfile << "........................................................................................................................" << std::endl;
	myfile << "........................................................................................................................" << std::endl;
	myfile << "........................................................................................................................" << std::endl;
	myfile << ".........................................................=...=.........................................................." << std::endl;
	myfile << "......................................................=.====.===.=.=...................................................." << std::endl;
	myfile << "....................................................========.==========................................................." << std::endl;
	myfile << "...............................................===========I================............................................." << std::endl;
	myfile << ".........................................=...=========I===II=I=I=III=I======............................................" << std::endl;
	myfile << ".........................................=.========I==III=II=III=II==I======............................................" << std::endl;
	myfile << ".......................................=.=========III=IIIIII=I=IIII=I=====I=.===........................................" << std::endl;
	myfile << ".....................................=..========I===IIIIIIII=IIIIII=I=I==II======.==...................................." << std::endl;
	myfile << ".....................................============I=II=IIIIIIIAIIIAI=I====II===I====.==.................................." << std::endl;
	myfile << "....................................=====I=I===I=.=III=IIIIAAIIIIAI=I==IIII============................................." << std::endl;
	myfile << ".....................................=====II==III==IIAIIIIIAII=AIAIII=IIII===II=======.................................." << std::endl;
	myfile << "...................................==.======II=III==IAIIIIIAII=AAIII=II==I===II=I=====.==.=............................." << std::endl;
	myfile << "....................................========IIIIIII=IIAIIIAAIIIIAIII==I==I==IIIII==I=======............................." << std::endl;
	myfile << ".............................=....=========IIIIIIIIIIIAIIAAAIIIIAIII=IAIII=IIIIIIII=========..==........................" << std::endl;
	myfile << ".............................====.======I===IIAAAIIIIAAAIAAAAIAIAIIIIIAIIIAIIAAI======.=======.==......................." << std::endl;
	myfile << "............................===I===========IIIIAAAIIIIAAAAAAAIAIAIAI=IIIIAAIII=I=I==============........................" << std::endl;
	myfile << "..............................==I======III==IIIIIIAAI=AAIAAXAAAAIAAIIAAIAAIIIIII=I===IIII======....=...................." << std::endl;
	myfile << "............................=..=IAI===IIIIIIIIIIIAAAAAIAIXIXAAXAIAXAAIIAAAIIAII=IIIIIII========.====...................." << std::endl;
	myfile << "...........................====..IAII=IIIII=IIIIAIAIAAAAAXAXAAXAIAAAIAAAAIIIAIIIIIIIIII=====.=.===......................" << std::endl;
	myfile << "..................=.......========IIIIIIIIIAIIIIIIIAAXAAAXAAXXXAIXAIAXIAAAIAIIA==I=II=====I=====........................" << std::endl;
	myfile << "..................==......=========IIAIIIAIIIIAAAIIIAAAAAXAXXXXAAXAAAAAAAIAIIII==III=======.=========..................." << std::endl;
	myfile << "...................=I==..=====I======IIIIIAAIAIIIAAAAAXXAXXXXAXAAXAXXIAAIAIIIIIIAII==.==IIII==IIII==...................." << std::endl;
	myfile << "....................=II===II===IIIIIIIAAAAIAAAAAIIIAXXXXXXXXXXXAAAAAAAXAAAAAAAAAIIIAAAAAIIIIII====......................" << std::endl;
	myfile << "....................==IIIIIIIIIIIIAAAAAAXAAAAIIIAIIIAXXXMXXXMXAAXXIAXXAXAAAAIII=IIII======IIII=I=====..................." << std::endl;
	myfile << "................==..====IIIAAAAIIIIAIAAAAAXAAXAIIIAAAIXAAMXMMMXXAAXXXXXXAAIIIIIAIIIIIIIIIIIIIII========................." << std::endl;
	myfile << "...............=====I====IIAAAAAIII=====IIAXXAXXAAIAAAAXIAMMMMXAAAXMMXAIIAAAI=====IAIIIIIAII========...................." << std::endl;
	myfile << "...................=====IIIIIIAAAAAAAIIIIIIAAAIAAXMMXXXXXXMMXMMXXMMXAIAAAAAIII====IIAAAAIIII======.........=............" << std::endl;
	myfile << "...................========IIIIIAXXAAAAIAIIIIIAAAIAXAAAXXXXMMMXXMMMAAAAAAAAAIAIIIIAAAIAIII===========.=====............." << std::endl;
	myfile << "................=======II=========IAXAAXXXXAAAAAXXAAXAAIMMMMMXXMMMAIAAAAIAAXXAAAAAAI==II=========..=======.............." << std::endl;
	myfile << "..........========.======IIIIIIIIIIIAAAXXXXXXXXAAXXXMXXXAXMMMMMMXXAAAXAAAAAXAAAAAIIIIIIIIIIIIIIIIIII===................." << std::endl;
	myfile << "............===IIIAIIIIIIIIAAAAAAXXXXXXXXXXXXXAXXAXAXXMXXMMMMMMXMXXXXAAAAAAAIIAIIAAAAAAAAAAIIIIII=====.................." << std::endl;
	myfile << "................======IIIIIIIIAAAAAAAAAXAXAAAAXMMMXXAAMXIAMMMMMMMXMXXXXXXXXXXXAAAIIIIIIIIIIAIAII========................" << std::endl;
	myfile << ".................====II==I=IIIAIIIIAIAAXAAAAXXXXXXXMXXXMMAMMMMXIAMXAXXXXXXXXXXXAAAAAAAAAIAAIIIIII=I===.................." << std::endl;
	myfile << "...............====================IIAAAAXXXXXXXAXXMMMMMXMMWWMMMXXXXXAAAAAAAAAXXXAAAAAII=================..............." << std::endl;
	myfile << "....................===...======IIIAAAXXXXAAAXAXIAAIAXMMAAMWWMXAXXAXXXAXAAXXAXAXXXAIIIIIII====I==I====.=................" << std::endl;
	myfile << "..................=====IIIIIIAAAAAAAAAAAI=IAIAAA=IIAXXAXMXMWMMIAAAAXXXXXAXAIAAAXAAAAAAAAIIIIII==========................" << std::endl;
	myfile << ".................=====IIIIIIAAAIIIII=I=IIIIAXAAIAAIAXXXAIMMMMXIAIXAXXXAAXXXXXAIIIAAAIAAIAIIIII====II====................" << std::endl;
	myfile << ".................=======III=I======IIIIIIIAXAAAAIIAAIIIAAAMMMAAAAAIIIAXXXMXXXXAIII==IIIII==IIIII========................" << std::endl;
	myfile << "................=================II==IIIAAAAAAAIIAI===IIIMMMMXAIIAIIIIIAAXXXXXXXAAII==IIII========.====................." << std::endl;
	myfile << ".................=====..=============IIAAAAAIIIIIII===IIIXMMMAIIAIIAIII=IAAAAAXXAAAIAII==============..................." << std::endl;
	myfile << "........................============IAAAIAAI===I======I==AMMMAIII=IAI====IIIAAAAAAAAIIIIIII===========.................." << std::endl;
	myfile << "=....................=======..=====IIII===II============IIMMMIIIIIII=====I===IAAAAAAAI=I========........................" << std::endl;
	myfile << "===================....====...==============I=============MMMI=================IIAAIIIIIIII========....................." << std::endl;
	myfile << "===========================....===========================MMMI===================IIIIII====I==.==......................." << std::endl;
	myfile << "==============================================...=========MMMI=..=....=================I===I====........................" << std::endl;
	myfile << "==========================================================MMMA=============......===..===.===.==........................" << std::endl;
	myfile << "==========================================================MMMA===========================..=====...===========.=........" << std::endl;
	myfile << "==========================================================MMMX==========================================================" << std::endl;
	myfile << "=========================================================IMMMX==========================================================" << std::endl;
	myfile << "========II==IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIAAAIIAIIXMMMMAIIIIAAAIIIIIIIIIIIIIII=IIIII=IIIIIIIIIIII================" << std::endl;
	myfile << "XXXXXXXXXXXXXXXXXXXXXXXXXXMXXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXXXXMXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMWMMMMMMMWMWWWWMMMMMWWWWMMWWWWWWWWWWWWMWWWMMWMWWMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile.close();
}
