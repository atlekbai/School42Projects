// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUI.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/05 13:26:43 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/05 13:26:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GUI_HPP
# define GUI_HPP

# include "Components.hpp"
# include <map>

class GUI
{
private:
	void	addLabel(int x, int y, std::string id);

public:
	GUI(void){}
	~GUI(void){}
	void	loadMenu(void);
	void	gameOver(void);
	void	addScore(int score, int id);
	static std::map<std::string, std::string> menu;
};

#endif