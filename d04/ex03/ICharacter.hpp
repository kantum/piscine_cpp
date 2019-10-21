/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:02:36 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:18:49 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
       public:
              virtual ~ICharacter() {}
              virtual std::string const & getName() const = 0;
              virtual void equip(AMateria* m) = 0;
	      virtual void unequip(int idx) = 0;
	      virtual void use(int idx, ICharacter& target) = 0;
};

#endif
