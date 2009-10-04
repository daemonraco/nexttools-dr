/**
* @file Log.dr.cpp
*
* @date 2009-05-26
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

#include <nexttools/Log.dr.h>

#include <time.h>
#include <iostream> //DEBUG
#include <nexttools/Debug.dr.h>

namespace dr {

Log::Log(const string &tag, Levels level, const string &filepath, const OpenMode mode) : DRObject() {
	this->_filepath     = filepath;
	this->_maximumLevel = level;
	this->_currentLevel = level;
	this->_mode         = mode;
	this->_tag          = tag;

	this->_appendEndLine = true;
	this->_appendTagname = true;

	this->_output.open(this->_filepath.c_str(), ios::out|(this->_mode==Append ? ios::app : ios::trunc));

	this->_isOk = this->_output.is_open();
}

Log::~Log() {
	if(this->_output.is_open()) {
		this->_output.close();
	}

}

string Log::toString() const throw() {
	return "dr::LogFactory";
}

void Log::write(const string &msg) {
	this->write(msg, this->_currentLevel);
}

void Log::write(const string &msg, const Levels &level) {
	if(level <= this->_maximumLevel) {
		if(this->_appendTagname) {
			this->_output << this->_tag << ": ";
		}
		this->_output << msg;
		if(this->_appendEndLine) {
			this->_output << endl;
		}
	}
}

int Log::operator<<(const string &msg) {
	this->write(msg);

	return 0;
}

int Log::operator<<(const Levels &level) {
	this->_currentLevel = level;

	return 0;
}

int Log::operator<<(const Tricks &trick) {
	switch(trick) {
		case AddDate: {
			char	buff[128]; ///@fixme Replace number by a constant.
			time_t	rawtime;
			time(&rawtime);
			strftime(buff, sizeof(buff), "Date: %Y-%m-%d %H:%M:%S", localtime(&rawtime)); ///@fixme Replace format by a constant.
			(*this) << buff;
			break;
		}
		case Reset: {
			this->_appendEndLine = true;
			this->_appendTagname = true;
		}
		case ResetLevel: {
			this->_currentLevel = this->_maximumLevel;
			break;
		}
		case ToggleEndLine: {
			this->_appendEndLine = !this->_appendEndLine;
			break;
		}
		case ToggleTagname: {
			this->_appendTagname = !this->_appendTagname;
			break;
		}
		default: {
			break;
		}
	}

	return 0;
}

/* ---------------------------------------------------------------------------- */

LogFactory*	LogFactory::_Instance = NULL;

LogFactory::LogFactory() : DRObject() {
}

LogFactory::~LogFactory() {
	this->_freeAll();
}

Log* LogFactory::_buildLog(const string &tag, const Log::Levels level, const string &filepath, const Log::OpenMode mode) {
	Log*	out = NULL;

	if(this->_logs.find(tag) == this->_logs.end()) {
		out = new Log(tag, level, filepath, mode);
		this->_logs[tag] = out;
	} else {
		out = this->_logs[tag];
	}

	return out;
}

void LogFactory::_freeAll() {
	for(LogMap::iterator it=this->_logs.begin(); it!=this->_logs.end(); it++) {
		delete it->second;
	}
	this->_logs.clear();
}

Log* LogFactory::_get(const string &tag) {
	Log*	out = NULL;

	if(this->_logs.find(tag) != this->_logs.end()) {
		out = this->_logs[tag];
	}

	return out;
}

string LogFactory::toString() const throw() {
	return "dr::LogFactory";
}

Log* LogFactory::BuildLog(const string &tag, const Log::Levels level, const string &filepath, const Log::OpenMode mode) {
	return LogFactory::Instance()->_buildLog(tag, level, filepath, mode);
}

void LogFactory::FreeAll() {
	LogFactory::Instance()->_freeAll();
}

Log* LogFactory::Get(const string &tag) {
	return LogFactory::Instance()->_get(tag);
}

LogFactory* LogFactory::Instance() {
	if(LogFactory::_Instance == NULL) {
		LogFactory::_Instance = new LogFactory();
	}
	return LogFactory::_Instance;
}

}
