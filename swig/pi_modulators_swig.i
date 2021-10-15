/* -*- c++ -*- */

#define PI_MODULATORS_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "pi_modulators_swig_doc.i"

%{
#include "pi_modulators/pi_2_bpsk.h"
#include "pi_modulators/pi_4_qpsk.h"
%}

%include "pi_modulators/pi_2_bpsk.h"
GR_SWIG_BLOCK_MAGIC2(pi_modulators, pi_2_bpsk);
%include "pi_modulators/pi_4_qpsk.h"
GR_SWIG_BLOCK_MAGIC2(pi_modulators, pi_4_qpsk);
