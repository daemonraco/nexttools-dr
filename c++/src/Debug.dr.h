/**
* @file debug.dr.h
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

#warning "This file is just a develop-time. Please, remove any inclution of this file before releasing your applications."

#ifndef __DEBUG_DR_H__
#define __DEBUG_DR_H__

#define	DBG	fprintf(stderr, "NextTools:DBG\n");
#define	XDBG(x)	fprintf(stderr, "NextTools:DBG: " #x "\n");

/**
 * This section contains special stuff for C++.
 * @{
 */
#ifdef	__cplusplus

#include <iostream>

#define	VDBG(x)		std::cerr << "NextTools:DBG: " <<  (x) << endl;
#define	XVDBG(x)	std::cerr << "NextTools:DBG: " << #x << ": " <<  (x) << endl;

#endif	// __cplusplus
/* @} */

#endif /* __DEBUG_DR_H__ */

/* The open source means to speak clearly.					*/
