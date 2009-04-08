/**
 * @file Debug.dr.h
 * @author Alejandro Darío Simi
 * @date 2009-03-01
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

#ifndef	__DR_DEBUG_H__
#define	__DR_DEBUG_H__

/********************************************************************************
 * DEFINITIONS									*
 ********************************************************************************/
/* Standart Macro.								*/
#define	DEBUG		fprintf(stderr,"DEBUG\n");
#define	XDEBUG(x)	fprintf(stderr,"DEBUG: %s\n",#x);
/* Boolean Macros.								*/
#define	BDEBUG(x)	fprintf(stderr,"DEBUG: %s\n",((x)?"TRUE":"FALSE"));
#define	SBDEBUG(x,y)	fprintf(stderr,"DEBUG: %s%s\n",x,((y)?"TRUE":"FALSE"));
#define	SBSDEBUG(x,y,z)	fprintf(stderr,"DEBUG: %s%s%s\n",(x),((y)?		 \
	"TRUE":"FALSE"),(z));
#define	XBDEBUG(x)	fprintf(stderr,"DEBUG: %s: %s\n",#x,((x)?"TRUE":"FALSE"));
/* Character Macros.								*/
#define	CDEBUG(x)	fprintf(stderr,"DEBUG: %c\n",(x));
#define	SCDEBUG(s,x)	fprintf(stderr,"DEBUG: %s%c\n",(s),(x));
#define	SCSDEBUG(x,y,z)	fprintf(stderr,"DEBUG: %s%c%s\n",(x),(y),(z));
#define	XCDEBUG(x)	fprintf(stderr,"DEBUG: %s: %c\n",#x,(x));
/* Floting Macros.								*/
#define	FDEBUG(x)	fprintf(stderr,"DEBUG: %f\n",(x));
#define	SFDEBUG(s,x)	fprintf(stderr,"DEBUG: %s%f\n",(s),(x));
#define	SFSDEBUG(x,y,z)	fprintf(stderr,"DEBUG: %s%f%s\n",(x),(y),(z));
#define	XFDEBUG(x)	fprintf(stderr,"DEBUG: %s: %f\n",#x,(x));
/* Integer Macros.								*/
#define	IDEBUG(x)	fprintf(stderr,"DEBUG: %d\n",(x));
#define	SIDEBUG(s,x)	fprintf(stderr,"DEBUG: %s%d\n",(s),(x));
#define	SISDEBUG(x,y,z)	fprintf(stderr,"DEBUG: %s%d%s\n",(x),(y),(z));
#define	XIDEBUG(x)	fprintf(stderr,"DEBUG: %s: %d\n",#x,(x));
/* Strings Macros.								*/
#define	SDEBUG(x)	fprintf(stderr,"DEBUG: %s\n",(x));
#define	SSDEBUG(x,y)	fprintf(stderr,"DEBUG: %s%s\n",(x),(y));
#define	SSSDEBUG(x,y,z)	fprintf(stderr,"DEBUG: %s%s%s\n",(x),(y),(z));
#define	XSDEBUG(x)	fprintf(stderr,"DEBUG: %s: %s\n",#x,(x));
/* Error Macros.								*/
#define	EDEBUG		fprintf(stderr,"ERROR: [%d] %s\n", errno,		\
	strerror(errno));
/* Step-debugging Macros.							*/
#define	DEBUG_STARTSTEPS	int DEBUG_step=0;fprintf(stderr,"DEBUG STEP: Starts at %d\n",DEBUG_step++);
#define	DEBUG_STEP		fprintf(stderr,"DEBUG STEP: %d\n",DEBUG_step++);
#define	PDEBUG_STARTSTEPS(x)	int x=0;fprintf(stderr,"DEBUG STEP [%s]: Starts at %d\n",#x,x++);
#define	PDEBUG_STEP(x)		fprintf(stderr,"DEBUG STEP [%s]: %d\n",#x,x++);

#endif /* __DR_DEBUG_H__ */

/* The open source means to speak clearly.					*/
