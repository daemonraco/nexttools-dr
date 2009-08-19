/**
* @file ValueOption.dr.cpp
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

#include <ValueOption.dr.h>
#include <Debug.dr.h>

namespace dr {
using namespace dr;

ValueOption::ValueOption() : Option() {
}

ValueOption::~ValueOption() {
}

bool ValueOption::check(string command) {
	bool	out = true;

	if(!this->needsMore()) {
		if(out = this->hasCommand(command)) {
			this->setActivated(true);
			this->_needsMore = true;
		}
	} else {
		this->_value = command;
		this->_needsMore = false;
	}

	return out;
}

string ValueOption::value() {
	return this->_value;
}

int ValueOption::valueCollection(vector<string> &values) {
	int	out = 0;
	values.clear();
	if(this->activated() && !this->needsMore()) {
		values.push_back(this->value());
		out = 1;
	}
	return out;
}

}

/* The open source means to speak clearly.					*/
