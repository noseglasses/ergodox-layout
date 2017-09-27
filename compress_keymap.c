/* Copyright 2017 Florian Fleissner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ng_papageno_settings.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

static int uart_putchar(char c, FILE *stream) {
  if (c == '\n')
    uart_putchar('\r', stream);
//   loop_until_bit_is_set(UCSR1A, UDRE1);
  while(!(UCSR0A & _BV(UDRE0)));
  UDR1 = c;
  return 0;
}

static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,
                                         _FDEV_SETUP_WRITE);

// Just a dummy to enable linkage withoud
// the need to link actual qmk related stuff
//
int __xprintf(const char *format, ...)
{
   return 0;
}
 
// ********************************************************************************
// Main
// ********************************************************************************
int main(int argc, char**argv) {
 
    // setup our stdio stream
    stdout = &mystdout;

   init_papageno();
   
	cli();
	sleep_mode();
}
