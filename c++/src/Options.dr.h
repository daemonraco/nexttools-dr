/**
 * @file Options.dr.h
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

#ifndef OPTIONS_DR_H_
#define OPTIONS_DR_H_

#include <DRObject.dr.h>

namespace dr {
using namespace dr;

/**
 * @todo documentar
 * @brief Options is a manager for parameters.
 */
class Options : public DRObject {
	public:
		Options();
		virtual ~Options();

	public:
		virtual bool load(int counter, char** params);
};

}

#endif /* OPTIONS_DR_H_ */
