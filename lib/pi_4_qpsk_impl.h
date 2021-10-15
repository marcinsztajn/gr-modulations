/* -*- c++ -*- */
/*
 * Copyright 2021 Marcin Puchlik.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PI_MODULATORS_PI_4_QPSK_IMPL_H
#define INCLUDED_PI_MODULATORS_PI_4_QPSK_IMPL_H

#include <pi_modulators/pi_4_qpsk.h>
#include <math.h>

namespace gr {
  namespace pi_modulators {

    class pi_4_qpsk_impl : public pi_4_qpsk
    {
     private:
//     float pi_2 {std::numbers::pi / 2.0};

     //gr_complex *p_tablica = {nullptr}; 	


     const gr_complex first_constellation[4] = {std::polar<float>(1,M_PI/4), std::polar<float>(1,M_PI/4*3), std::polar<float>(1,M_PI/4*7), std::polar<float>(1,M_PI/4*5)}; 
     const gr_complex second_constellation[4] = {std::polar<float>(1,M_PI/4 + M_PI/4), std::polar<float>(1,M_PI/4*3 + M_PI/4), std::polar<float>(1,M_PI/4*7 + M_PI/4), std::polar<float>(1,M_PI/4*5 + M_PI/4)}; 
     int last_constellation = 2;

     public:
      pi_4_qpsk_impl();
      ~pi_4_qpsk_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace pi_modulators
} // namespace gr

#endif /* INCLUDED_PI_MODULATORS_PI_4_QPSK_IMPL_H */

