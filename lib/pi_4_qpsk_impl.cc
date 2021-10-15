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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "pi_4_qpsk_impl.h"

namespace gr {
  namespace pi_modulators {

    pi_4_qpsk::sptr
    pi_4_qpsk::make()
    {
      return gnuradio::get_initial_sptr
        (new pi_4_qpsk_impl());
    }


    /*
     * The private constructor
     */
    pi_4_qpsk_impl::pi_4_qpsk_impl()
      : gr::sync_block("pi_4_qpsk",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
        // p_tablica = new gr_complex[10];
    
    }

    /*
     * Our virtual destructor.
     */
    pi_4_qpsk_impl::~pi_4_qpsk_impl()
    {
	/*
	delete [] p_tablica;
	p_tablica = nullptr;
	*/
    }

    int
    pi_4_qpsk_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      for (int i = 0; i < noutput_items; i++){
      	if (last_constellation == 1){
      	  out[i] = second_constellation[in[i]]; 
      	  last_constellation = 2;
      	}
      	else {
      	  out[i] = first_constellation[in[i]]; 
      	  last_constellation = 1;
      	}
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace pi_modulators */
} /* namespace gr */

