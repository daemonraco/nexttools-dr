/**
* @file Tools.dr.hpp
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

#ifndef __TOOLS_DR_H__
#define __TOOLS_DR_H__

#include <sys/stat.h>

#include <iostream>

#include <nexttools/DRObject.dr.h>

/**
* @todo documentar
*/
#define	LENGTH_MAXIMUM_FILE_BUFFER_SIZE	2048

namespace dr {
using namespace std;


/**
* @todo documentar
* @brief Tools is a singleton that merges all important things
* and tools.
*/
class Tools  : public DRObject {
	public:
		/**
		* List of possible errors.
		*/
		typedef enum {
			Success = 0,	//!< Success
			Unknown,	//!< Unknown
			NoSuchEntry,	//!< NoSuchEntry
			EntryExists,	//!< EntryExists
			IsDirectory,	//!< IsDirectory
			IsFile,		//!< IsFile
			NotADirectory,	//!< NotADirectory
			NotAFile,	//!< NotAFile
			UnableToOpen,	//!< UnableToOpen
			UnableToWrite,	//!< UnableToWrite
			WrittingError	//!< WrittingError
		} Errors;

	protected:
		/**
		* This is the pointer to the instance.
		*/
		static Tools*	_Instance;

	protected:
		Errors	_lastError;
		string	_lastErrorXMsg;

	public:
		/**
		* @todo documentar
		*/
		virtual ~Tools();

	protected:
		/**
		* This is is the main constructor, it can only be called by
		* the class itself, because the class works as a singleton.
		*/
		Tools();

	public:
		/**
		* @param path @todo documentar;
		* @return return the directory for a given path.
		*/
		virtual string basename(const string &path) const;
		/**
		* Tries to check if an entry exists or not.
		* @param info This parameter will contain the information of the
		* entry. Only if the entry exists and the info is a valid pointer.
		* @return Tools::Success if the file exists, Otherwise, returns
		* Tools::NoSuchEntry.
		*/
		virtual Errors chechFile(const string &path, struct stat* info=NULL);
		/**
		 * @todo documentar
		 * @param from @todo documentar
		 * @param to @todo documentar
		 * @return @todo documentar
		 */
		virtual Errors copyDirectory(const string &from, const string &to) throw();
		/**
		* Copies a file to another.
		* @param from It's the path to copy.
		* @param to It's the path for the file to be created.
		* @return On success returns Tools::Success.
		*/
		virtual Errors copyFile(const string &from, const string &to) throw();
		/**
		* @param path @todo documentar;
		* @return return the directory for a given path.
		*/
		virtual string dirname(const string &path) const;
		/**
		* @todo documentar
		* @param from It's the path to move.
		* @param to It's the path for destination.
		* @return On success returns Tools::Success.
		*/
		virtual Errors moveEntry(const string &from, const string &to) throw();
		/**
		 * @todo documentar
		 * @param from @todo documentar
		 * @param to @todo documentar
		 * @return @todo documentar
		 */
		virtual Errors removeDirectory(const string &path) throw();
		/**
		 * @todo documentar
		 * @param from @todo documentar
		 * @param to @todo documentar
		 * @return @todo documentar
		 */
		virtual Errors removeFile(const string &path) throw();
		/**
		 * Inherited.
		 */
		virtual string toString() const throw();

	public:
		/**
		* @todo documentar
		* @return Return the singleton instance
		*/
		static Tools* getInstance() {
			if (Tools::_Instance == NULL) {
				Tools::_Instance = new Tools();
			}
			return Tools::_Instance;
		}
};

}

#endif /* __TOOLS_DR_H__ */
