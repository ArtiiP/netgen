/*  netgen - autorouting net generator for Polish Format map
 *  Copyright (C) 2005 Mariusz Dąbrowski 
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "TextStreamReader.h"
#include "netgen.h"
#include <cstdio>

using namespace std;

TextStreamReader::TextStreamReader (istream& istr): is (istr){
   lineCounter = 0;
}

char bufor[FGETS_BUFFER];

void TextStreamReader::process (){
   while (true){
#if __cplusplus >= 201103L // C++11
       if (&is != &cin) {
#else
       if (is != cin) {
#endif
          if (!getline (is, linebuf))
              break;
       } else {
          if (fgets(bufor,FGETS_BUFFER,stdin)==0)
              break;
          linebuf = bufor;
      }
      lineCounter++;
      linebuf = linebuf.substr (0,linebuf.rfind ('\r'));
      linebuf = linebuf.substr (0,linebuf.rfind ('\n'));
      unsigned start_of_comment = linebuf.find (COMMENT_DELIMITER);
      if (start_of_comment != string::npos){
	 if (start_of_comment == 0){
	    comment (linebuf);
	 }
	 else {
	    linebuf = linebuf.substr (0, start_of_comment);
	    line (linebuf);
	 }
      }
      else
	line (linebuf);      
   }
}
