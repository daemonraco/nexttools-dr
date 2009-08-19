/**
 * @file Tools.dr.hpp
 *
 * @date 2009-03-01
 * @author Alejandro Darío Simi
 * @copyright 2009 Alejandro Darío Simi
 * @license GPLv3
 */

/**
 *
 * NextTools - An amount of usefull functions.
 * Copyright (C) 2009 Alejandro Darío Simi
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __TOOLS_DR_H__
#define __TOOLS_DR_H__

#include <iostream>

#include <DRObject.dr.h>

namespace dr {
using namespace std;

/**
 * @todo documentar
 * @brief Tools is a singleton that merges all important things
 * and tools.
 */
class Tools  : public DRObject {
	protected:
		/**
		 * This is the pointer to the instance.
		 */
		static Tools*	_Instance;

	public:
		/**
		 * @todo documentar
		 */
		virtual ~Tools();

	protected:
		/**
		 * This is is the main constructor, it can only be called by
		 * the class itself, because the class works as a singleton.
		 */
		Tools();

	public:
		/**
		 * @todo documentar
		 * @return Return the singleton instance
		 */
		static Tools* getInstance() {
			if (Tools::_Instance == NULL) {
				Tools::_Instance = new Tools();
			}
			return Tools::_Instance;
		}
};

}

#endif /* __TOOLS_DR_H__ */
