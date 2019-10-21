/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:50:47 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:21:06 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
#include <iostream>

class Ice : public AMateria
{
	private:
		std::string	_type;

	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(Ice const & src);
		~Ice(void);

		Ice& operator=(Ice const & rhs);

		std::string const &	getType() const;

		virtual AMateria*	clone() const;
};

#endif
