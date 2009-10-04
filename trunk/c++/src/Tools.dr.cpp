/**
* @file Tools.dr.cpp
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

#include <nexttools/Tools.dr.h>

#include <exception>
#include <fstream>
#include <nexttools/Debug.dr.h>

namespace dr {
using namespace dr;

using namespace std;

/**
* @todo documentar
*/
Tools*	Tools::_Instance = NULL;

Tools::Tools() : DRObject () {
	this->_lastError     = Tools::Success;
	this->_lastErrorXMsg = "";
}

Tools::~Tools() {
}

string Tools::basename(const string &path) const {
	string out = path;

	size_t	pos = path.rfind('/');
	if(pos != string::npos) {
		pos++;
		out = path.substr(pos, path.length()-pos);
	}

	return out;
}

Tools::Errors Tools::chechFile(const string &path, struct stat* info) {
	Errors	outError = Tools::Success;

	bool	removeInfo = (info == NULL);

	if(removeInfo) {
		info = new struct stat;
	}

	if(stat(path.c_str(), info)) {
		outError = Tools::NoSuchEntry;
	}

	if(removeInfo) {
		delete info;
		info = NULL;
	}

	return outError;
}

Tools::Errors Tools::copyFile(const string &from, const string &to) throw() {
	Errors	outError = Tools::Success;

	try {
		if(this->chechFile(from) == Tools::Success) {
			FILE*	fin = fopen(from.c_str(), "r");
			if(fin) {
				FILE*	fout = fopen(to.c_str(), "w");
				if(fout) {
					char	buffer[LENGTH_MAXIMUM_FILE_BUFFER_SIZE];
					int	lenIn;
					int	lenOut;
					while(outError == Tools::Success && !feof(fin)) {
						lenIn  = fread(buffer,  sizeof(char), LENGTH_MAXIMUM_FILE_BUFFER_SIZE, fin);
						lenOut = fwrite(buffer, sizeof(char), lenIn, fout);
						if(lenIn != lenOut) {
							outError = this->_lastError = Tools::WrittingError;
							this->_lastErrorXMsg = "";
							this->_lastErrorXMsg+= lenIn;
							this->_lastErrorXMsg+= "read, ";
							this->_lastErrorXMsg+= lenOut;
							this->_lastErrorXMsg+= " written";
						}
					}

					fclose(fout);
				} else {
					outError = this->_lastError = Tools::UnableToWrite;
					this->_lastErrorXMsg        = to;
				}
				fclose(fin);
			} else {
				outError = this->_lastError = Tools::UnableToOpen;
				this->_lastErrorXMsg        = from;
			}
		} else {
			outError = this->_lastError = Tools::NoSuchEntry;
			this->_lastErrorXMsg        = from;
		}
	} catch(exception e) {
		outError = this->_lastError = Tools::Unknown;
		this->_lastErrorXMsg        = e.what();
	} catch(...) {
		outError = this->_lastError = Tools::Unknown;
		this->_lastErrorXMsg        = "Unspected exception";
	}

	return outError;
}

Tools::Errors Tools::copyDirectory(const string &from, const string &to) throw() {
	Errors	outError = Tools::Success;

	cerr<<"TODO: COPIAR DIRECTORIOS"<<endl;

	return outError;
}

string Tools::dirname(const string &path) const {
	string out = "";

	size_t	pos = path.rfind('/');
	if(pos != string::npos) {
		out = path.substr(0, pos);
	}

	if(out.length() == 0) {
		out = (path.at(0) == '/' ? "/" : ".");
	}

	return out;
}

Tools::Errors Tools::moveEntry(const string &from, const string &to) throw() {
	Errors	outError = Tools::Success;

	struct stat	stIn;
	struct stat	stOut;

	bool	existIn;
	bool	existOut;

	try {
		if(existIn = (this->chechFile(from, &stIn) == Tools::Success)) {
			/*
			 * Checks if the destination is an existing entry.
			 * If exists, it will try to check if both are of
			 * the same type.
			 * If it doesn't exist, i will try to check if the
			 * destination is an existing directory.
			 */
			if(existOut = (this->chechFile(to, &stOut) == Tools::Success)) {
				/*
				 * Case: Both exist.
				 */
				if(!S_ISDIR(stIn.st_mode) && S_ISDIR(stOut.st_mode)) {
					outError = this->_lastError = Tools::IsDirectory;
					this->_lastErrorXMsg        = to;
				} else if(S_ISDIR(stIn.st_mode) && !S_ISDIR(stOut.st_mode)) {
					outError = this->_lastError = Tools::IsFile;
					this->_lastErrorXMsg        = to;
				}
			} else {
				/*
				 * Case: Only the original exists.
				 *
				 * It tries to obtain information from the directory that will
				 * contain the things to be moved.
				 */
				string		aux = this->dirname(to);
				struct stat	stAux;
				if(this->chechFile(aux, &stAux) == Tools::Success) {
					/*
					 * Case: Both exist.
					 */
					if(!S_ISDIR(stAux.st_mode)) {
						outError = this->_lastError = Tools::NotADirectory;
						this->_lastErrorXMsg        = aux;
					}
					stOut.st_dev = stAux.st_dev;
				} else {
					outError = this->_lastError = Tools::NoSuchEntry;
					this->_lastErrorXMsg        = aux;
				}
			}
		} else {
			outError = this->_lastError = Tools::NoSuchEntry;
			this->_lastErrorXMsg        = from;
		}
	} catch(exception e) {
		outError = this->_lastError = Tools::Unknown;
		this->_lastErrorXMsg        = e.what();
	} catch(...) {
		outError = this->_lastError = Tools::Unknown;
		this->_lastErrorXMsg        = "Unspected exception";
	}

	/*
	 * If the execution reaches this point is because it knows everything
	 * it needs to perform the operation.
	 */
	if(outError == Tools::Success) {
		/*
		 * File Moving.
		 */
		if(S_ISREG(stIn.st_mode)) {
			if(existOut) {
				/// TODO: controlar la salida para ver que no haya problemas
				this->removeFile(to);
			}
			/*
			 * If both files are in the same device, it's just renamed.
			 * Else it is copied and the original is removed.
			 */
			if(stIn.st_dev == stOut.st_dev) {
				/// TODO: controlar la salida para ver que no haya problemas
				rename(from.c_str(), to.c_str());
			} else {
				if(this->copyFile(from, to) == Tools::Success) {
					this->removeFile(from);
				}
			}
		} else if(S_ISDIR(stIn.st_mode)) {
			/*
			 * Directory Moving.
			 */
			if(!existOut) {
				/*
				 * If both directories are in the same device,
				 * it's just renamed. Else it is copied and the
				 * original is removed.
				 */
				if(stIn.st_dev == stOut.st_dev) {
					/// TODO: controlar la salida para ver que no haya problemas
					rename(from.c_str(), to.c_str());
				} else {
					/// TODO: controlar la salida para ver que no haya problemas
					if(this->copyDirectory(from, to) == Tools::Success) {
						/// TODO: controlar la salida para ver que no haya problemas
						this->removeDirectory(from);
					}
				}
			} else {
				outError = this->_lastError = Tools::EntryExists;
				this->_lastErrorXMsg        = to;
			}
		}
	}

	return outError;
}

Tools::Errors Tools::removeDirectory(const string &path) throw() {
	Errors	outError = Tools::Success;

	cerr<<"TODO: BORRAR DIRECTORIOS"<<endl;

	return outError;
}

Tools::Errors Tools::removeFile(const string &path) throw() {
	Errors	outError = Tools::Success;

	/// TODO: controlar la salida para ver que no haya problemas.
	unlink(path.c_str());

	return outError;
}

string Tools::toString() const throw() {
	return "dr::Tools";
}

}
