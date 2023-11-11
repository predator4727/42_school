/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:05:46 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:28:47 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	
	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:

		Harl(void);
		~Harl(void);
		void complain( std::string level );
		
};

typedef void (Harl::*t_ptr) (void);

#endif //************************HARL_HPP