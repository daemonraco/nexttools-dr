/**
* @file DRException.dr.h
*
* @date 2009-09-27
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

#ifndef DREXCEPTION_DR_H_
#define DREXCEPTION_DR_H_

#include <exception>
#include <string>
#include <nexttools/DRObject.dr.h>

namespace dr {
using namespace std;

/**
 * @class DRException This class representes an generic or unknown error
 * thrown by a DRObject.
 */
class DRException : public exception, public DRObject {
	protected:
		string	__class__;
		string	_what;

	public:
		DRException(const string &what);
		virtual ~DRException() throw() {};

	public:
		virtual string toString() const throw();
		virtual const char* what() const throw();
};

/**
 * @class DRSubclassResponsabily This class representes an generic or unknown error
 * thrown by a DRObject.
 */
class DRSubclassResponsabily : public DRException {
	public:
		DRSubclassResponsabily(const string &what);
		virtual ~DRSubclassResponsabily() throw() {};
};

}

#endif /* DREXCEPTION_DR_H_ */
