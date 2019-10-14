#include "contact.class.hpp"

Contact::Contact(void)
{
	this->index = getSize() + 1;
	return;
}

Contact::~Contact(void)
{
	return;
}

bool	Contact::increaseSize(void)
{
	Contact::_size++;
	if (_size > 8)
		return 1;
	else
		return 0;
}

int		Contact::getSize(void)
{
	return Contact::_size;
}

void	Contact::inc(void)
{
	this->index++;
}

int		Contact::getIndex(void)
{
	return (this->index);
}

int	Contact::_size = 0;
