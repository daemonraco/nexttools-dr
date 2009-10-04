/**
* @file Option.dr.h
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

#ifndef __OPTION_DR_H__
#define __OPTION_DR_H__

#include <map>
#include <string>
#include <vector>

#include <nexttools/DRObject.dr.h>

namespace dr {
using namespace std;
using namespace dr;

/**
* @class Option @todo documentar
*/
class Option : public DRObject {
	protected:
		bool		_activated;
		vector<string>	_commands;
		bool		_enabled;
		string		_helpText;
		string		_helpTextFmt;
		string		_name;
		bool		_needsMore;

	public:
		Option();
		virtual ~Option();

	public:
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		virtual bool activated() const;
		/**
		* @todo documentar
		* @param command @todo documentar
		* @return @todo documentar
		*/
		virtual bool addCommand(string command);
		/**
		* @todo documentar
		* @param command @todo documentar
		* @return Returns true if the command was accepted by the option.
		*/
		virtual bool check(string command);
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		virtual bool enabled() const;
		/**
		* @todo documentar
		* @param command @todo documentar
		* @return @todo documentar
		*/
		virtual bool hasCommand(string command);
		/**
		 * @return @todo documentar
		 */
		virtual string help() const;
		/**
		 * @return @todo documentar
		 */
		virtual string helpText() const;
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		virtual string name() const;
		/**
		* @todo documentar
		* @return @todo documentar
		*/
		virtual bool needsMore() const;
		/**
		* @todo documentar
		* @param active @todo documentar
		* @return @todo documentar
		*/
		virtual bool setActivated(bool active);
		/**
		* @todo documentar
		* @param enable @todo documentar
		* @return @todo documentar
		*/
		virtual bool setEnabled(bool enable=true);
		/**
		 * @todo documentar
		 * @param text @todo documentar
		 * @return @todo documentar
		 */
		virtual string setHelpText(const string &text);
		/**
		* @todo documentar
		* @param name @todo documentar
		* @return @todo documentar
		*/
		virtual string setName(string name);
		/**
		 * Inherited.
		 * In this case, it is the same to call value()
		 */
		virtual string toString() const throw();
		/**
		* @warning This method is useless for this class.
		* @return returns an empty string;
		*/
		virtual string value() const;
		/**
		* @warning This method is useless for this class and clears the vector.
		* @return returns 0 (zero);
		*/
		virtual int valueCollection(vector<string> &values) const;

	protected:
		/**
		 * @todo documentar
		 * @return @todo documentar
		 */
		virtual string commands();
		/**
		 * @todo documentar
		 * @param out @todo documentar
		 * @param in @todo documentar
		 * @param length @todo documentar
		 */
		virtual void wrapHelp(string &out, const string &in, const int length) const;
};

typedef	map<string,Option*>	OptionsMap;

}

#endif /* __OPTION_DR_H__ */

/* The open source means to speak clearly.					*/
