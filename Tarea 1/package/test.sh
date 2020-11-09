#!/bin/sh
if [ $# != 2 ]
then
	echo Insert a file_path and a dectory to save results.
	exit 0
else
	F=$1
	D=$2
fi

mkdir -p $D

# CountMin
./project -cm $F 40 32000 4 200 > $D/cm_40mers_w32k_d4_k200.txt
./project -cm $F 40 64000 4 200 > $D/cm_40mers_w64k_d4_k200.txt
./project -cm $F 40 32000 8 200 > $D/cm_40mers_w32k_d8_k200.txt
./project -cm $F 40 64000 8 200 > $D/cm_40mers_w64k_d8_k200.txt
#
./project -cm $F 30 32000 4 200 > $D/cm_30mers_w32k_d4_k200.txt
./project -cm $F 30 64000 4 200 > $D/cm_30mers_w64k_d4_k200.txt
./project -cm $F 30 32000 8 200 > $D/cm_30mers_w32k_d8_k200.txt
./project -cm $F 30 64000 8 200 > $D/cm_30mers_w64k_d8_k200.txt
#
./project -cm $F 20 32000 4 200 > $D/cm_20mers_w32k_d4_k200.txt
./project -cm $F 20 64000 4 200 > $D/cm_20mers_w64k_d4_k200.txt
./project -cm $F 20 32000 8 200 > $D/cm_20mers_w32k_d8_k200.txt
./project -cm $F 20 64000 8 200 > $D/cm_20mers_w64k_d8_k200.txt
#
# CountMinCU
./project -cmcu $F 40 32000 4 200 > $D/cmcu_40mers_w32k_d4_k200.txt
./project -cmcu $F 40 64000 4 200 > $D/cmcu_40mers_w64k_d4_k200.txt
./project -cmcu $F 40 32000 8 200 > $D/cmcu_40mers_w32k_d8_k200.txt
./project -cmcu $F 40 64000 8 200 > $D/cmcu_40mers_w64k_d8_k200.txt
#
./project -cmcu $F 30 32000 4 200 > $D/cmcu_30mers_w32k_d4_k200.txt
./project -cmcu $F 30 64000 4 200 > $D/cmcu_30mers_w64k_d4_k200.txt
./project -cmcu $F 30 32000 8 200 > $D/cmcu_30mers_w32k_d8_k200.txt
./project -cmcu $F 30 64000 8 200 > $D/cmcu_30mers_w64k_d8_k200.txt
#
./project -cmcu $F 20 32000 4 200 > $D/cmcu_20mers_w32k_d4_k200.txt
./project -cmcu $F 20 64000 4 200 > $D/cmcu_20mers_w64k_d4_k200.txt
./project -cmcu $F 20 32000 8 200 > $D/cmcu_20mers_w32k_d8_k200.txt
./project -cmcu $F 20 64000 8 200 > $D/cmcu_20mers_w64k_d8_k200.txt
#
# Misra Gries
./project -mg $F 20 200 > $D/mg_20mers_k200.txt
./project -mg $F 20 400 > $D/mg_20mers_k400.txt
./project -mg $F 20 800 > $D/mg_20mers_k800.txt
#
./project -mg $F 30 200 > $D/mg_30mers_k200.txt
./project -mg $F 30 400 > $D/mg_30mers_k400.txt
./project -mg $F 30 800 > $D/mg_30mers_k800.txt
#
./project -mg $F 40 200 > $D/mg_40mers_k200.txt
./project -mg $F 40 400 > $D/mg_40mers_k400.txt
./project -mg $F 40 800 > $D/mg_40mers_k800.txt
#
# Space Saving
./project -ss $F 20 200 > $D/ss_20mers_k200.txt
./project -ss $F 20 400 > $D/ss_20mers_k400.txt
./project -ss $F 20 800 > $D/ss_20mers_k800.txt
#
./project -ss $F 30 200 > $D/ss_30mers_k200.txt
./project -ss $F 30 400 > $D/ss_30mers_k400.txt
./project -ss $F 30 800 > $D/ss_30mers_k800.txt
#
./project -ss $F 40 200 > $D/ss_40mers_k200.txt
./project -ss $F 40 400 > $D/ss_40mers_k400.txt
./project -ss $F 40 800 > $D/ss_40mers_k800.txt
#
