/**
* @file ValueOption.dr.h
*
* @date 2009-06-15
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

#ifndef __MULTIVALUEOPTION_DR_H__
#define __MULTIVALUEOPTION_DR_H__

#include <nexttools/options/ValueOption.dr.h>

namespace dr {
using namespace dr;

/**
* @todo documentar
*/
#define MULTIVALUEOPTION_SEPARATOR	','

/**
* @class MultivalueOption @todo documentar
*/
class MultivalueOption: public dr::ValueOption {
	protected:
		/**
		* @todo documentar
		*/
		vector<string>	_valueCollection;

	public:
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		MultivalueOption();
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		virtual ~MultivalueOption();

	public:
		/**
		* @todo documentar
		* @param command @todo documentar
		* @return Returns true if the command was accepted by the option.
		*/
		virtual bool check(string command);
		/**
		* @todo documentar
		* @param active @todo documentar
		* @return @todo documentar
		*/
		virtual bool setActivated(bool active);
		/**
		* @return returns 1 (one) when the option is activated and needs no
		* more params. Otherwise, it returns 0 (zero).
		*/
		virtual int valueCollection(vector<string> &values) const;

	protected:
		/**
		 *
		 * @param command
		 * @param auxV
		 */
		virtual void splitValues(const string &command, vector<string> &auxV);
};

}

#endif /* __MULTIVALUEOPTION_DR_H__ */

/* The open source means to speak clearly.					*/
