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

#ifndef INCLUDED_PI_MODULATORS_PI_2_BPSK_H
#define INCLUDED_PI_MODULATORS_PI_2_BPSK_H

#include <pi_modulators/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace pi_modulators {

    /*!
     * \brief <+description of block+>
     * \ingroup pi_modulators
     *
     */
    class PI_MODULATORS_API pi_2_bpsk : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<pi_2_bpsk> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pi_modulators::pi_2_bpsk.
       *
       * To avoid accidental use of raw pointers, pi_modulators::pi_2_bpsk's
       * constructor is in a private implementation
       * class. pi_modulators::pi_2_bpsk::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace pi_modulators
} // namespace gr

#endif /* INCLUDED_PI_MODULATORS_PI_2_BPSK_H */

