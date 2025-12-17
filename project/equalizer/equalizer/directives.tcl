############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_interface -mode s_axilite -bundle eq_io "equalizer" y
set_directive_interface -mode s_axilite -bundle eq_io "equalizer"
set_directive_pipeline "IIRFilter::filter/filter_loop"
set_directive_interface -mode s_axilite -bundle eq_io "equalizer" x
set_directive_interface -mode s_axilite -bundle eq_io "equalizer" mode
set_directive_interface -mode s_axilite -bundle eq_io "equalizer" coeffs
set_directive_loop_flatten "IIRFilter::setCoeffs/setCoeffs_loop"
