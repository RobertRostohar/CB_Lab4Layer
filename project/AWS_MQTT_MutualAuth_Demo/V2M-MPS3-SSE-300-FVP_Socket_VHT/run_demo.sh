#!/usr/bin/env bash
VHT_Corstone_SSE-300_Ethos-U55 -C mps3_board.visualisation.disable-visualisation=1 -C mps3_board.telnetterminal0.start_telnet=0 -C mps3_board.uart0.out_file=- -a Objects/image.axf $*
