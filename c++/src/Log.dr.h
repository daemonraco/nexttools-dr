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

#ifndef __LOG_DR_H__
#define __LOG_DR_H__

#include <fstream>
#include <map>

#include <nexttools/DRObject.dr.h>

namespace dr {
using namespace std;

class LogFactory;

/**
* @class Log @todo doc
*/
class Log : public DRObject {
	public:
		/**
		* @todo doc
		* @warning The order of this tags is VERY important.
		*/
		enum Levels {
			CriticalError,		//!< CriticalError @todo doc
			Error,			//!< Error @todo doc
			None,			//!< None @todo doc
			Info,			//!< Info @todo doc
			InfoMinimal,		//!< InfoMinimal @todo doc
			InfoUnneeded,		//!< InfoUnneeded @todo doc
			Debugging,		//!< Debugging @todo doc
			DebuggingMinimal,	//!< DebuggingMinimal @todo doc
			DebuggingUnneeded	//!< DebuggingUnneeded @todo doc
		};
		/**
		* @todo doc
		*/
		enum OpenMode {
			Append,		//!< Append @todo doc
			Overwrite	//!< Overwrite @todo doc
		};
		/**
		* @todo doc
		*/
		enum Tricks {
			Reset,		//!< Reset @todo doc
			ResetLevel,	//!< ResetLevel @todo doc
			AddDate,	//!< AddDate Adds a date
			ToggleEndLine,	//!< ToggleEndLine Sets on/off the addition of an end line.
			ToggleTagname	//!< ToggleTagname Sets on/off the tag printting.
		};

	protected:
		string		_filepath;
		string		_tag;
		fstream		_output;
		Levels		_maximumLevel;
		Levels		_currentLevel;
		OpenMode	_mode;
		bool		_isOk;
		bool		_appendTagname;
		bool		_appendEndLine;

	protected:
		/**
		* @todo doc
		* @param tag @todo doc
		* @param level @todo doc
		* @param filepath @todo doc
		* @param mode @todo doc
		* @return @todo doc
		*/
		Log(const string &tag, const Levels level, const string &filepath, const OpenMode mode);

	public:
		/**
		* @todo doc
		* @return @todo doc
		*/
		virtual ~Log();

	public:
		/**
		* @return Returns the path where the is beening written.
		*/
		virtual string filepath() const {
			return this->_filepath;
		};
		virtual string toString() const throw();
		/**
		* Tries to write in the log using the current level. In other
		* words, it's an abbrevation of the overloaded method using the
		* current level of log.
		* @param msg @todo doc
		*/
		virtual void write(const string &msg);
		/**
		* Tries to write in the log using the level past by parameter.
		* @param msg @todo doc
		* @param level @todo doc
		*/
		virtual void write(const string &msg, const Levels &level);
		/**
		* @todo doc
		* @param msg @todo doc
		* @return @todo doc
		*/
		virtual int operator<<(const string &msg);
		/**
		* @todo doc
		* @param level @todo doc
		* @return @todo doc
		*/
		virtual int operator<<(const Levels &level);
		/**
		* @todo doc
		* @param trick @todo doc
		* @return @todo doc
		*/
		virtual int operator<<(const Tricks &trick);

	protected:
		friend class LogFactory;
};

/**
* @class LogFactory
*/
class LogFactory : public DRObject {
	protected:
		/**
		* @todo doc
		*/
		typedef	map<string,Log*>	LogMap;

	protected:
		/**
		* @todo doc
		*/
		static LogFactory*	_Instance;

	protected:
		/**
		* @todo doc
		*/
		LogMap	_logs;

	protected:
		/**
		* @todo doc
		* @return
		*/
		LogFactory();

	public:
		/**
		* @todo doc
		* @return @todo doc
		*/
		virtual ~LogFactory();

	protected:
		/**
		* @todo doc
		* @param tag @todo doc
		* @param level @todo doc
		* @param filepath @todo doc
		* @param mode @todo doc
		* @return @todo doc
		*/
		Log* _buildLog(const string &tag, const Log::Levels level, const string &filepath, const Log::OpenMode mode);
		/**
		* @todo doc
		*/
		void _freeAll();
		/**
		* @todo doc
		* @param tag @todo doc
		* @return @todo doc
		*/
		Log* _get(const string &tag);

	public:
		virtual string toString() const throw();

	public:
		/**
		* @todo doc
		* @param tag @todo doc
		* @param level @todo doc
		* @param filepath @todo doc
		* @param mode @todo doc
		* @return @todo doc
		*/
		static Log* BuildLog(const string &tag, const Log::Levels level, const string &filepath, const Log::OpenMode mode=Log::Append);
		/**
		* @todo doc
		* @return @todo doc
		*/
		static LogFactory* Instance();
		/**
		* @todo doc
		*/
		static void FreeAll();
		/**
		* @todo doc
		* @param tag @todo doc
		* @return @todo doc
		*/
		static Log* Get(const string &tag);
};

}

#endif /* __LOG_DR_H__ */
