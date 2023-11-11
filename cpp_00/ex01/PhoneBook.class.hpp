/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:22:41 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/11 18:08:12 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void    add(void);
		void    search(void) const;
		void    intro(void) const;
};

#endif //*************************************************PHONEBOOK_CLASS_H //