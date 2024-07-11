/* 
  Copyright (c) 2015 Hristo Gochkov. All rights reserved.
  This file is part of the RaspberryPi core for Arduino environment.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef PGMSPACE_INCLUDE
#define PGMSPACE_INCLUDE

inline uint32_t pgm_read_dword( const uint32_t* p) { return *p; }
inline uint16_t pgm_read_word( const uint16_t* p) { return *p; }
inline uint8_t pgm_read_byte( const uint8_t* p) { return *p; }


#endif
