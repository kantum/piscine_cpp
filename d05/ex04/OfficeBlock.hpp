#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP
#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock
{
	public:
		class MissingElementException : public std::exception
		{
			public:
				MissingElementException(void);
				MissingElementException(MissingElementException const & src);
				virtual ~MissingElementException(void) throw();

				MissingElementException& operator=(MissingElementException const & rhs);

				virtual const char* what() const throw()
				{
					return ("Someone is missing, you can't do this form");
				}	
		};
		class InternException : public std::exception
		{
			public:
				InternException(void);
				InternException(InternException const & src);
				virtual ~InternException(void) throw();

				InternException& operator=(InternException const & rhs);

				virtual const char* what() const throw()
				{
					return ("Intern was not able to sign form");
				}
		};
		class SignerException : public std::exception
		{
			public:
				SignerException(void);
				SignerException(SignerException const & src);
				virtual ~SignerException(void) throw();

				SignerException& operator=(SignerException const & rhs);

				virtual const char* what() const throw()
				{
					return ("The signer was not able to sign the form");
				}
		};
	private:
		Intern*		_intern;
		Bureaucrat*	_signer;
		Bureaucrat*	_executor;
		
	public:
		OfficeBlock(void);
		OfficeBlock(Intern & intern, Bureaucrat & sign, Bureaucrat & exe);
		~OfficeBlock(void);

		void		setIntern(Intern & intern);
		void		setSigner(Bureaucrat & sign);
		void		setExecutor(Bureaucrat & exe);

		void		doBureaucracy(std::string form, std::string target);
};

#endif
