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

#include <MultivalueOption.dr.h>
#include <Debug.dr.h>

namespace dr {
using namespace dr;

MultivalueOption::MultivalueOption() : Option() {
	this->_value.clear();
}

MultivalueOption::~MultivalueOption() {
}

bool MultivalueOption::check(string command) {
	bool	out = true;

	if(!this->needsMore()) {
		if(out = this->hasCommand(command)) {
			this->setActivated(true);
			this->_needsMore = true;
		}
	} else {
		vector<string>	auxV;
		this->splitValues(command, auxV);
		for(vector<string>::iterator i=auxV.begin(); i!=auxV.end(); i++) {
			this->_value.push_back(*i);
		}
		this->_needsMore = false;
	}

	return out;
}

bool MultivalueOption::setActivated(bool active) {
	if(!active) {
		this->_value.clear();
	}
	return this->Option::setActivated(active);
}

void MultivalueOption::splitValues(const string &command, vector<string> &auxV) {
	string::size_type	pos    = 0;
	string::size_type	prepos = 0;

	auxV.clear();
	while(prepos != string::npos) {
		pos = command.find(MULTIVALUEOPTION_SEPARATOR, prepos);
		if(pos != string::npos) {
			auxV.push_back(command.substr(prepos, pos-prepos));
			prepos = pos + 1;
			if(prepos >= command.length()) {
				prepos = string::npos;
			}
		} else {
			auxV.push_back(command.substr(prepos));
			prepos = string::npos;
		}
	}
}

string MultivalueOption::value() {
	return "";
}

int MultivalueOption::valueCollection(vector<string> &values) {
	values = this->_value;
	return values.size();
}

}

/* The open source means to speak clearly.					*/
