/** \file Event.cpp
 **   \date  2005-12-07
 **   \author grymse@alhem.net
**/
/*
Copyright (C) 2005,2007  Anders Hedstrom

This library is made available under the terms of the GNU GPL.

If you would like to use this library in a closed-source application,
a separate license agreement is available. For information about
the closed-source license agreement for the C++ sockets library,
please visit http://www.alhem.net/Sockets/license.html and/or
email license@alhem.net.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#include "framework.h"
#ifdef _WIN32
#else
////#include <sys/time.h>
#endif


namespace sockets
{

   // statics
   int Event::m_unique_id = 0;


   Event::Event(IEventOwner *from,long sec,long usec) : m_from(from), m_time(sec, usec), id()(++m_unique_id)
   {
   }


   Event::~Event()
   {
   }


   bool Event::operator<(Event& e)
   {
      return m_time < e.m_time;
   }


   int Event::GetID()
   {
      return id();
   }


   const EventTime& Event::get_time() const
   {
      return m_time;
   }


   IEventOwner *Event::GetFrom()
   {
      return m_from;
   }

} // namespace sockets

