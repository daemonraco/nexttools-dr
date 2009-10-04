/**
* @file Options.dr.h
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

#ifndef __OPTIONS_DR_H__
#define __OPTIONS_DR_H__

#include <nexttools/DRObject.dr.h>
#include <nexttools/options/Option.dr.h>

namespace dr {
using namespace dr;

/**
* @todo documentar
* @brief Options is a manager for parameters.
*/
class Options : public DRObject {
	protected:
		OptionsMap*	_opts;
		string		_programName;
		bool		_needsMore;
		vector<string>	_otherParams;

	public:
		Options();
		virtual ~Options();

	public:
		/**
		 * @param optionName It's the option name.
		 * @return Returns true only if the option is loaded and it was
		 * activated.
		 */
		virtual bool activated(const string &optionName) const;
		/**
		* @return Retuns true where the option is successfully added.
		*/
		virtual bool addOption(const string &name);
		/**
		* @todo documentar
		* @param opt @todo documentar
		* @param name @todo documentar
		* @return @todo documentar
		*/
		virtual bool addOption(const string &name, Option* opt);
		/**
		* @todo documentar
		* @param optionName @todo documentar
		* @param command @todo documentar
		* @return @todo documentar
		*/
		virtual bool addOptionCommand(const string &optionName, const string &command);
		/**
		* @todo documentar
		* @param counter @todo documentar
		* @param params @todo documentar
		* @return @todo documentar
		*/
		virtual bool check(int counter, char** params);
		/**
		* @todo documentar
		* @param command @todo documentar
		*/
		virtual void checkCommand(const string &command);
		/**
		* @todo documentar
		* @param optionName @todo documentar
		* @return @todo documentar
		*/
		virtual Option* getOption(const string &optionName) const;
		/**
		 * @return @todo documentar
		 */
		virtual string help() const;
		/**
		 * @param optionName @todo documentar
		 * @return @todo documentar
		 */
		virtual string helpText(const string &optionName) const;
		/**
		 * @todo documentar
		 * @return @todo documentar
		 */
		virtual bool needsMore() const;
		/**
		 * @todo documentar
		 * @return @todo documentar
		 */
		virtual vector<string> otherParams() const;
		/**
		* @return Returns the name program.
		* @warning Remember that this method is useful only after the use
		* of method #check().
		*/
		virtual string programName();
		/**
		 * @todo documentar
		 * @param optionName @todo documentar
		 * @param text @todo documentar
		 * @return @todo documentar
		 */
		virtual string setHelpText(const string &optionName, const string &text);
		/**
		 * Inherited.
		 */
		virtual string toString() const throw();
		/**
		* @todo documentar
		* @param optionName @todo documentar
		* @return @todo documentar
		*/
		virtual string value(const string &optionName);
		/**
		 * @todo documentar
		 * @param optionName @todo documentar
		 * @param values @todo documentar
		 * @return Return the number of values in the options. Otherwise,
		 * returns a value lower than 0 (zero).
		 */
		virtual int valueCollection(const string &optionName, vector<string> &values);
};

}

#endif /* __OPTIONS_DR_H__ */

/* The open source means to speak clearly.					*/
