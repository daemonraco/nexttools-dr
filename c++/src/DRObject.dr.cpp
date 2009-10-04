/**
 * @file DRObject.dr.cpp
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

#include <nexttools/DRObject.dr.h>

#include <string>
#include <iostream>
#include <nexttools/DRException.dr.h>

namespace dr {
using namespace dr;
using namespace std;

DRObject::DRObject() {
}

DRObject::~DRObject() {
}

string DRObject::toString() const throw() {
	throw DRSubclassResponsabily("'DRObject' does not implements the method 'toString'. It always depends on the child class.");
	return string("DRObject");
}

ostream& operator<<(ostream &out, const DRObject &obj) {
	out << obj.toString();
	return out;
}

string& operator+(string &str, const DRObject &obj) {
	str+=obj.toString();
	return str;
}

string& operator+=(string &str, const DRObject &obj) {
	str = str + obj;
	return str;
}

bool operator==(const string &str, const DRObject &obj) {
	return str == obj.toString();
}

bool operator==(const DRObject &obj, const string &str) {
	return str == obj.toString();
}

}
