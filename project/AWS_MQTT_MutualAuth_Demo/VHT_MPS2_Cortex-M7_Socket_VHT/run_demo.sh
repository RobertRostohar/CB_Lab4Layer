#!/usr/bin/env bash
VHT_MPS2_Cortex-M7 -C fvp_mps2.mps2_visualisation.disable-visualisation=1 -C fvp_mps2.telnetterminal0.start_telnet=0 -C fvp_mps2.UART0.out_file=- -a Objects/image.axf $*
