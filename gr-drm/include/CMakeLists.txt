# Copyright 2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Install public header files
########################################################################
install(FILES
    drm_api.h
    drm_audio_encoder_svb.h
    drm_scrambler_vbvb.h
    drm_global_constants.h
    drm_tables.h
    drm_config.h
    drm_params.h
    drm_transm_params.h
    drm_generate_sdc_vb.h
    drm_generate_fac_vb.h 
    drm_util.h
    drm_partitioning_vbvb.h
    drm_punct_vbvb.h
    drm_add_tailbits_vbvb.h
    drm_interleaver_vbvb.h
    drm_qam_map_vbvb.h
    drm_cell_mapping_vbvb.h
    drm_audio_decoder_vbs.h
    drm_cell_interleaver_vcvc.h DESTINATION include/drm
)
