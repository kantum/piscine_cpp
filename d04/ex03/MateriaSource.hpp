/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:22:06 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:24:47 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource : public IMateria
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource(void);

		MateriaSource& operator=(MateriaSource const & rhs);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
