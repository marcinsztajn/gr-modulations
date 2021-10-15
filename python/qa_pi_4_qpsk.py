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
import cmath
import numpy as np

class qa_pi_4_qpsk(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        src_data = (0, 1, 2, 3, 3, 2, 2)
        pi = cmath.pi
        expected_result = np.angle([cmath.rect(1,pi/4), cmath.rect(1,pi), cmath.rect(1,7*pi/4), cmath.rect(1,6*pi/4), cmath.rect(1,5*pi/4), cmath.rect(1,0), cmath.rect(1,7*pi/4)]).tolist()
        expected_result = np.multiply(expected_result, 180/pi)
        print("PI/4 complex: ", cmath.rect(1,pi/4))
        print("PI/4 angle: ", np.angle(cmath.rect(1,pi/4)) *180/pi)
        src = blocks.vector_source_b(src_data)
        mod = pi_modulators.pi_4_qpsk()
        dst = blocks.vector_sink_c()
        self.tb.connect(src, mod, dst)
        # set up fg
        self.tb.run()
        # check data
        result_data = dst.data()
        print("Expected result: ",expected_result)
        print("Actual result: ", np.round(np.multiply(np.angle(result_data),180/pi)))
        result_data = np.multiply(np.angle(result_data),180/pi).round()
        for idx in range(len(expected_result)):
            #pass
            self.assertAlmostEqual(expected_result[idx],result_data[idx],places = 0)
        #self.assertListEqual(list(expected_result),np.angle(result_data).tolist())


if __name__ == '__main__':
    gr_unittest.run(qa_pi_4_qpsk)
