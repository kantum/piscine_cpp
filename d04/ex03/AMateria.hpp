/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:37:02 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:24:53 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>

class AMateria
{
	private:
		unsigned int	_xp;
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		~AMateria(void);

		AMateria& operator=(AMateria const & rhs);

		std::string const &	getType() const;
		unsigned int		getXP() const;
		
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
