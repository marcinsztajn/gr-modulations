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
#include "pi_2_bpsk_impl.h"

namespace gr {
  namespace pi_modulators {

    pi_2_bpsk::sptr
    pi_2_bpsk::make()
    {
      return gnuradio::get_initial_sptr
        (new pi_2_bpsk_impl());
    }


    /*
     * The private constructor
     */
    pi_2_bpsk_impl::pi_2_bpsk_impl()
      : gr::sync_block("pi_2_bpsk",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(gr_complex))) // nie wiem czy to gr_complex jest ok
    {

    }

    /*
     * Our virtual destructor.
     */
    pi_2_bpsk_impl::~pi_2_bpsk_impl()
    {
    }

    int
    pi_2_bpsk_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      // Do <+signal processing+>
      for(int i = 0; i < noutput_items; i++){
	if (last_constellation == 2){ // run first constellation
	    out[i] = first_constellation[in[i]];
	    last_constellation = 1;	
	}
	else
	{ // run second constellation
	    out[i] = second_constellation[in[i]];
	    last_constellation = 2;	
	}
      }					
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace pi_modulators */
} /* namespace gr */

