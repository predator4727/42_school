/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:19:15 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/12 17:49:56 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <iomanip>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        int         _index;

    public:
        Contact(void);
        ~Contact(void);
        void    createContact(int i);
        void    showTable(int index) const;
        void    find(int index) const;
        std::string display(std::string str) const;
        std::string fillContact(std::string str) const;
};

#endif //*************************************************CONTACT_CLASS_H //