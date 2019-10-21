#include "Squad.hpp"
#include <iostream>
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"

Squad::Squad(void)
{
	this->_nbUnits = 0;
	this->_lst = NULL;

}

Squad::Squad(Squad const & src)
{
	*this = src;
}

Squad::~Squad(void)
{
	t_unitPtr*	tmp;
	
	while (this->_lst)  
	{  
		tmp = this->_lst;  
		delete tmp->marine_ptr;
		this->_lst = this->_lst->next;
		delete tmp;
	}
}

Squad & Squad::operator=(Squad const & rhs)
{
	t_unitPtr*	current;
	t_unitPtr*	tmp;
	t_unitPtr*	head;

	if (this != &rhs && rhs._lst)
	{
		while (this->_lst)  
		{  
			std::cout << "QQQQQQQQQQQQQQQQQQQQ" << std::endl;
			tmp = this->_lst;  
    			delete tmp->marine_ptr;
			this->_lst = this->_lst->next;
			delete tmp;
		}
		tmp = rhs._lst;
    		head = new t_unitPtr();
		head->marine_ptr = tmp->marine_ptr->clone();
		head->next = NULL;
		current = head;
		tmp = tmp->next;
    		while (tmp)
		{
	        	current->next = new t_unitPtr();
			current = current->next;
			current->marine_ptr = tmp->marine_ptr->clone();
			current->next = NULL;
			tmp = tmp->next;
    		}
		this->_lst = head;
		this->_nbUnits = rhs._nbUnits;
	}
	return (*this);
}

int		Squad::getCount() const
{
	return this->_nbUnits;
}

ISpaceMarine*	Squad::getUnit(int N) const
{
	
	if (N <= this->_nbUnits)
	{
		t_unitPtr* lst = this->_lst;
		while (N--)
			lst = lst->next;	
		return lst->marine_ptr;
	}
	else
		return NULL;
}

int		Squad::push(ISpaceMarine* ptr)
{
	t_unitPtr*	new_node;
	t_unitPtr*	lst;

	new_node = NULL;
	lst = this->_lst;
	if (lst == NULL && ptr)
	{
		lst = new t_unitPtr();
		lst->marine_ptr = ptr;
		lst->next = NULL;
		this->_lst = lst;
		this->_nbUnits++;
		std::cout << "* NEW * Squad has now " << this->_nbUnits << " member" << std::endl;
		return this->_nbUnits;
	}
	else if (ptr == NULL)
		return getCount();
	while (lst && lst->next)
	{
		if (lst->marine_ptr == ptr)
			return getCount();
		lst = lst->next;
	}
	new_node = new t_unitPtr();
	new_node->marine_ptr = ptr;
	new_node->next = NULL;
	lst->next = new_node;
	this->_nbUnits++;
	std::cout << "* NEW * Squad has now " << this->_nbUnits << " members" << std::endl;
	return this->_nbUnits;
}
