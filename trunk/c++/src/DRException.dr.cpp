/**
* @file DRException.dr.cpp
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

#include <nexttools/DRException.dr.h>

namespace dr {
using namespace dr;
using namespace std;

DRException::DRException(const string &what) : exception(), DRObject() {
	__class__ = "DRException";
	this->_what = what;
	this->what();
}

string DRException::toString() const throw() {
	return __class__ + string(": ") + string(this->what());
}

const char* DRException::what() const throw() {
	return this->_what.c_str();
}

DRSubclassResponsabily::DRSubclassResponsabily(const string &what) : DRException(what) {
	__class__ = "DRSubclassResponsabily";
}

}
