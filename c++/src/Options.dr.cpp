/**
* @file Options.dr.cpp
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

#include <Options.dr.h>
#include <Debug.dr.h>

namespace dr {
using namespace dr;

Options::Options() : DRObject() {
	this->_opts        = new OptionsMap;
	this->_programName = "";
}

Options::~Options() {
	this->_opts->clear();
	delete this->_opts;
}

bool Options::addOption(string name) {
	bool	out = true;
	Option*	opt = new Option();

	if(!this->addOption(name, opt)) {
		delete opt;
		out = false;
	}

	return out;
}

bool Options::addOption(string name, Option* opt) {
	bool	out = true;

	if(this->getOption(name) == NULL) {
		opt->setName(name);
		(*this->_opts)[name] = opt;
	} else {
		out = false;
	}

	return out;
}

bool Options::addOptionCommand(string optionName, string command) {
	bool	out = true;
	Option*	opt = this->getOption(optionName);

	if(opt != NULL) {
		opt->addCommand(command);
	} else {
		out = false;
	}

	return out;
}

bool Options::check(int counter, char** params) {
	if(counter > 1) {
		this->_programName = params[0];
		for(int i=1; i<counter; i++) {
			this->checkCommand(params[i]);
			XVDBG(params[i])
		}
	} else {
		/**
		* @todo esto debe arrojar una excepsion, algo del tipo
		* DRException.
		*/
	}
}

void Options::checkCommand(string command) {
	bool	used = false;
	for(OptionsMap::iterator i=this->_opts->begin(); !used && i!=this->_opts->end(); i++) {
		if(i->second->enabled()) {
			if(used = i->second->check(command)) {
				this->_needsMore = i->second->needsMore();
			}
		}
	}
	if(!used) {
		this->_otherParams.push_back(command);
	}
}

Option* Options::getOption(string optionName) {
	Option*	out = NULL;

	bool	found = false;
	for(OptionsMap::iterator i=this->_opts->begin(); !found && i!=this->_opts->end(); i++) {
		if(i->first == optionName) {
			found = true;
			out = i->second;
		}
	}

	return out;
}

bool Options::needsMore() const {
	return this->_needsMore;
}

vector<string> Options::otherParams() const {
	return this->_otherParams;
}

string Options::programName() {
	return this->_programName;
}

string Options::value(string optionName) {
	Option*	out = this->getOption(optionName);

	return (out ? out->value() : "");
}

int Options::valueCollection(string optionName, vector<string> &values) {
	Option*	out = this->getOption(optionName);

	return (out ? out->valueCollection(values) : -1);
}

}

/* The open source means to speak clearly.					*/
