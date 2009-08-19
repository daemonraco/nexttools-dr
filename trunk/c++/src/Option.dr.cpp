/**
* @file Option.dr.cpp
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

#include <Option.dr.h>
#include <Debug.dr.h>

#include <map>
#include <string>

namespace dr {
using namespace std;
using namespace dr;

Option::Option() : DRObject() {
	this->_needsMore = false;

	this->setName("");
	this->setEnabled(true);
	this->setActivated(false);
}

Option::~Option() {
	this->_commands.clear();
}

bool Option::activated() const {
	return this->_activated;
}

bool Option::addCommand(string command) {
	bool	out = true;
	if(this->hasCommand(command)) {
		out = false;
	} else {
		this->_commands.push_back(command);
	}

	return out;
}

bool Option::check(string command) {
	bool	out = this->hasCommand(command);

	if(out) {
		this->setActivated(true);
		XDBG(como que active una opcion)
	}

	return out;
}

bool Option::enabled() const {
	return this->_enabled;
}

bool Option::hasCommand(string command) {
	bool	found = false;
	for(vector<string>::iterator i=this->_commands.begin(); !found && i!=this->_commands.end(); i++) {
		found = ((*i) == command);
	}
	return found;
}

string Option::name() const {
	return this->_name;
}

bool Option::needsMore() {
	return this->_needsMore;
}

bool Option::setActivated(bool active) {
	this->_activated = active;
	return this->activated();
}

bool Option::setEnabled(bool enable) {
	this->_enabled = enable;
	return this->enabled();
}

string Option::setName(string name) {
	this->_name = name;
	return this->name();
}

string Option::value() {
	return "";
}

int Option::valueCollection(vector<string> &values) {
	values.clear();
	return 0;
}

}

/* The open source means to speak clearly.					*/
