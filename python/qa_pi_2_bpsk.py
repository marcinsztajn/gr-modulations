#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 Marcin Puchlik.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import pi_modulators_swig as pi_modulators

class qa_pi_2_bpsk(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        src_data = (0, 1, 1, 0, 0, 0, 0)
        expected_result = [-1+0j, 0+1j, 1+0j, 0-1j, -1+0j, 0-1j, -1+0j]
        src = blocks.vector_source_b(src_data)
        mod = pi_modulators.pi_2_bpsk()
        dst = blocks.vector_sink_c()
        self.tb.connect(src, mod, dst)
        # set up fg
        self.tb.run()
        # check data
        result_data = dst.data()
        print("Expected result: ",expected_result)
        print("Actual result: ", result_data)
        self.assertListEqual(list(expected_result),list(result_data))

if __name__ == '__main__':
    gr_unittest.run(qa_pi_2_bpsk)
