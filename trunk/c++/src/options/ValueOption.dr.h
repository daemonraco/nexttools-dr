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

#ifndef __VALUEOPTION_DR_H__
#define __VALUEOPTION_DR_H__

#include <nexttools/options/Option.dr.h>

namespace dr {
using namespace dr;

/**
* @class ValueOption @todo documentar
*/
class ValueOption: public dr::Option {
	protected:
		/**
		* @todo documentar
		*/
		string	_value;

	public:
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		ValueOption();
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		virtual ~ValueOption();

	public:
		/**
		* @todo documentar
		* @param command @todo documentar
		* @return Returns true if the command was accepted by the option.
		*/
		virtual bool check(string command);
		/**
		* @return Retunrs the value taken from the commands.
		*/
		virtual string value() const;
		/**
		 * @return returns 1 (one) when the option is activated and needs no
		 * more params. Otherwise, it returns 0 (zero).
		 */
		virtual int valueCollection(vector<string> &values) const;

	protected:
		/**
		 * @todo documentar
		 * @return @todo documentar
		 */
		virtual string commands();
		/**
		 *
		 * @param value It's the command portion to check.
		 * @param cmd It's always the command calculated.
		 * @param prm It's the command extra value. It can be an empty string.
		 * @return Returns true when the option is divided.
		 */
		virtual bool splitCommand(const string &value, string &cmd, string &prm) const;
};

}

#endif /* __VALUEOPTION_DR_H__ */

/* The open source means to speak clearly.					*/
