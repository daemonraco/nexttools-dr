/**
* @file DRObject.dr.h
*
* @date 2009-04-07
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

#ifndef DROBJECT_DR_H_
#define DROBJECT_DR_H_

#include <string>
using namespace std;

namespace dr {

/**
* class DRObject @todo documentar
*/
class DRObject {
	public:
		DRObject();
		virtual ~DRObject();

	public:
		/**
		* Converts the object to a string.
		* @return @todo documentar
		*/
		virtual string toString() const throw();
};

/**
 * General Operators
 * @{
 */
ostream&	operator<<(ostream &out, const DRObject &obj);
string&		operator+ (string  &str, const DRObject &obj);
string&		operator+=(string  &str, const DRObject &obj);
bool		operator==(const string   &str, const DRObject &obj);
bool		operator==(const DRObject &obj, const string   &str);
/** @} */

}

#endif /* DROBJECT_DR_H_ */
