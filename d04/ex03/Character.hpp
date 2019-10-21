/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:03:26 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:21:59 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character : public ICharacter
{
	private:
		AMateria*	_inventory[4];
		std::string	_name;
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character(void);

		Character& operator=(Character const & rhs);

		virtual std::string const &	getName() const;
		
		virtual void			equip(AMateria* m);
		virtual void			unequip(int idx);
		virtual void			use(int idx, ICharacter& target);
};

#endif
