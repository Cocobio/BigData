#!/bin/sh
# CountMin
./project -cm ../../../Database/ERR626208.fastq 40 32000 4 200 > cm_08_40mers_w32k_d4_k200.txt
./project -cm ../../../Database/ERR626208.fastq 40 64000 4 200 > cm_08_40mers_w64k_d4_k200.txt
./project -cm ../../../Database/ERR626208.fastq 40 32000 8 200 > cm_08_40mers_w32k_d8_k200.txt
./project -cm ../../../Database/ERR626208.fastq 40 64000 8 200 > cm_08_40mers_w64k_d8_k200.txt
#
./project -cm ../../../Database/ERR626208.fastq 30 32000 4 200 > cm_08_30mers_w32k_d4_k200.txt
./project -cm ../../../Database/ERR626208.fastq 30 64000 4 200 > cm_08_30mers_w64k_d4_k200.txt
./project -cm ../../../Database/ERR626208.fastq 30 32000 8 200 > cm_08_30mers_w32k_d8_k200.txt
./project -cm ../../../Database/ERR626208.fastq 30 64000 8 200 > cm_08_30mers_w64k_d8_k200.txt
#
./project -cm ../../../Database/ERR626208.fastq 20 32000 4 200 > cm_08_20mers_w32k_d4_k200.txt
./project -cm ../../../Database/ERR626208.fastq 20 64000 4 200 > cm_08_20mers_w64k_d4_k200.txt
./project -cm ../../../Database/ERR626208.fastq 20 32000 8 200 > cm_08_20mers_w32k_d8_k200.txt
./project -cm ../../../Database/ERR626208.fastq 20 64000 8 200 > cm_08_20mers_w64k_d8_k200.txt
#
# CountMinCU
./project -cmcu ../../../Database/ERR626208.fastq 40 32000 4 200 > cmcu_08_40mers_w32k_d4_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 40 64000 4 200 > cmcu_08_40mers_w64k_d4_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 40 32000 8 200 > cmcu_08_40mers_w32k_d8_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 40 64000 8 200 > cmcu_08_40mers_w64k_d8_k200.txt
#
./project -cmcu ../../../Database/ERR626208.fastq 30 32000 4 200 > cmcu_08_30mers_w32k_d4_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 30 64000 4 200 > cmcu_08_30mers_w64k_d4_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 30 32000 8 200 > cmcu_08_30mers_w32k_d8_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 30 64000 8 200 > cmcu_08_30mers_w64k_d8_k200.txt
#
./project -cmcu ../../../Database/ERR626208.fastq 20 32000 4 200 > cmcu_08_20mers_w32k_d4_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 20 64000 4 200 > cmcu_08_20mers_w64k_d4_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 20 32000 8 200 > cmcu_08_20mers_w32k_d8_k200.txt
./project -cmcu ../../../Database/ERR626208.fastq 20 64000 8 200 > cmcu_08_20mers_w64k_d8_k200.txt
#
# Misra Gries
./project -mg ../../../Database/ERR626208.fastq 20 200 > mg_08_20mers_k200.txt
./project -mg ../../../Database/ERR626208.fastq 20 400 > mg_08_20mers_k400.txt
./project -mg ../../../Database/ERR626208.fastq 20 800 > mg_08_20mers_k800.txt
#
./project -mg ../../../Database/ERR626208.fastq 30 200 > mg_08_30mers_k200.txt
./project -mg ../../../Database/ERR626208.fastq 30 400 > mg_08_30mers_k400.txt
./project -mg ../../../Database/ERR626208.fastq 30 800 > mg_08_30mers_k800.txt
#
./project -mg ../../../Database/ERR626208.fastq 40 200 > mg_08_40mers_k200.txt
./project -mg ../../../Database/ERR626208.fastq 40 400 > mg_08_40mers_k400.txt
./project -mg ../../../Database/ERR626208.fastq 40 800 > mg_08_40mers_k800.txt
#
# Space Saving
./project -ss ../../../Database/ERR626208.fastq 20 200 > ss_08_20mers_k200.txt
./project -ss ../../../Database/ERR626208.fastq 20 400 > ss_08_20mers_k400.txt
./project -ss ../../../Database/ERR626208.fastq 20 800 > ss_08_20mers_k800.txt
#
./project -ss ../../../Database/ERR626208.fastq 30 200 > ss_08_30mers_k200.txt
./project -ss ../../../Database/ERR626208.fastq 30 400 > ss_08_30mers_k400.txt
./project -ss ../../../Database/ERR626208.fastq 30 800 > ss_08_30mers_k800.txt
#
./project -ss ../../../Database/ERR626208.fastq 40 200 > ss_08_40mers_k200.txt
./project -ss ../../../Database/ERR626208.fastq 40 400 > ss_08_40mers_k400.txt
./project -ss ../../../Database/ERR626208.fastq 40 800 > ss_08_40mers_k800.txt
#
