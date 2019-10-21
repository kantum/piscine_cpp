/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:00:43 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:01:20 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
#include <iostream>

class Cure : public AMateria
{
	private:
		std::string	_type;

	public:
		Cure(void);
		Cure(std::string const & type);
		Cure(Cure const & src);
		~Cure(void);

		Cure& operator=(Cure const & rhs);

		std::string const &	getType() const;

		virtual AMateria*	clone() const;
};

#endif
